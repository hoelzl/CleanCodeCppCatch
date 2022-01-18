// ReSharper disable CppClangTidyCppcoreguidelinesAvoidNonConstGlobalVariables
// ReSharper disable CppMemberFunctionMayBeStatic
#include <array>
#include <catch2/catch_test_macros.hpp>
#include <gsl/gsl>
#include <numeric>

namespace ownership_1 {

int global_x;
int global_y;

int compute_sum()
{
    return global_x + global_y;
}

TEST_CASE("compute_sum()")
{
    global_x = 2;
    global_y = 3;
    CHECK(compute_sum() == 5);
}

int compute_indirect_sum(std::unique_ptr<int> x, std::unique_ptr<int> y)
{
    return *x + *y;
}

TEST_CASE("compute_indirect_sum()")
{
    auto x{std::make_unique<int>(3)};
    auto y{std::make_unique<int>(4)};
    CHECK(compute_indirect_sum(std::move(x), std::move(y)) == 7);
    // x and y are no longer valid here!
}

// No no!
int take_ownership_1(const int* i)
{
    const int result{*i};
    delete i;
    return result;
}

TEST_CASE("take_ownership_1()")
{
    int* i{new int{10}};
    CHECK(take_ownership_1(i) == 10);
}

// NONONONONONONO!
int take_ownership_2(int& i)
{
    const int result{i};
    delete &i; // BAD! BAD! BAD!
    return result;
}

TEST_CASE("take_ownership_2()")
{
    int* i{new int{10}};
    CHECK(take_ownership_2(*i) == 10);
}

// We want a class whose instances share a pointer and release it when the last
// one is done with it.
//
// Implementing it like this is a terrible idea! What are some of the problems?
struct PartialOwner
{
    // For debugging...
    static int deleted_values;
    static int num_owners;

    // This is owned by PartialOwner
    static int* pi;

    void take_ownership(int* value)
    {
        if (num_owners == 0) {
            assert(pi == nullptr);
            pi = value;
        }
        assert(pi == value);
        ++num_owners;
    }
    void done()
    {
        --num_owners;
        if (num_owners == 0) {
            delete pi;
            pi = nullptr;
            deleted_values++;
        }
    }
};

int PartialOwner::num_owners{0};
int PartialOwner::deleted_values{0};
int* PartialOwner::pi{nullptr};

TEST_CASE("PartialOwner")
{
    PartialOwner owner1{};
    CHECK(PartialOwner::num_owners == 0);
    CHECK(PartialOwner::deleted_values == 0);
    CHECK(PartialOwner::pi == nullptr);
    int* i{new int{10}};
    owner1.take_ownership(i);
    CHECK(PartialOwner::num_owners == 1);
    CHECK(PartialOwner::deleted_values == 0);
    CHECK(PartialOwner::pi != nullptr);
    PartialOwner owner2{};
    owner2.take_ownership(i);
    CHECK(PartialOwner::num_owners == 2);
    CHECK(PartialOwner::deleted_values == 0);
    CHECK(PartialOwner::pi != nullptr);
    PartialOwner owner3{};
    owner2.take_ownership(i); // <= Oops...
    CHECK(PartialOwner::num_owners == 3);
    CHECK(PartialOwner::deleted_values == 0);
    CHECK(PartialOwner::pi != nullptr);
    owner3.done();
    CHECK(PartialOwner::num_owners == 2);
    CHECK(PartialOwner::deleted_values == 0);
    CHECK(PartialOwner::pi != nullptr);
    owner1.done();
    CHECK(PartialOwner::num_owners == 1);
    CHECK(PartialOwner::deleted_values == 0);
    CHECK(PartialOwner::pi != nullptr);
    owner2.done();
    CHECK(PartialOwner::num_owners == 0);
    CHECK(PartialOwner::deleted_values == 1);
    CHECK(PartialOwner::pi == nullptr);
}

}