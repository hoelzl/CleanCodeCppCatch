// ReSharper disable CppClangTidyCppcoreguidelinesAvoidNonConstGlobalVariables
#include <array>
#include <catch2/catch_test_macros.hpp>
#include <gsl/gsl>
#include <numeric>

namespace ownership_1 {

int compute_sum(int x, int y) { return x + y; }

TEST_CASE("compute_sum()") { CHECK(compute_sum(2, 3) == 5); }

int compute_indirect_sum(const int* x, const int* y) { return *x + *y; }

TEST_CASE("compute_indirect_sum()")
{
    const auto x{std::make_unique<int>(3)};
    const auto y{std::make_unique<int>(4)};
    CHECK(compute_indirect_sum(x.get(), y.get()) == 7);
    // x and y are still valid here.
}

// If you cannot use smart pointers:
int take_ownership_1(gsl::owner<int*> i)
{
    assert(i != nullptr);
    const int result{*i};
    delete i;
    return result;
}

TEST_CASE("take_ownership_1()")
{
    const gsl::owner<int*> i{new int{10}};
    CHECK(take_ownership_1(i) == 10);
}

int take_ownership_1_a(std::unique_ptr<int> i)
{
    assert(i.get() != nullptr);
    // My preference:
    assert(i);
    return *i;
}

TEST_CASE("take_ownership_1_a()")
{
    std::unique_ptr<int> i{std::make_unique<int>(10)};
    CHECK(take_ownership_1_a(std::move(i)) == 10);
    // i is in an unspecified state here!
}


template <typename Deleter = std::default_delete<int>>
int take_ownership_1_b(std::unique_ptr<int, Deleter> i)
{
    assert(i);
    return *i;
}

struct DeleterSpy
{
    static bool deleted_something;
    void operator()(gsl::owner<const int*> ptr) const
    {
        deleted_something = true;
        delete ptr;
    }
};

bool DeleterSpy::deleted_something{false};

TEST_CASE("take_ownership_1_b()")
{
    std::unique_ptr<int, DeleterSpy> i{new int{10}};
    DeleterSpy::deleted_something = false;
    CHECK(take_ownership_1_b(std::move(i)) == 10);
    CHECK(DeleterSpy::deleted_something);
    // i is in an unspecified state here!
}


// take_ownership_2() turns into take_ownership_1().

struct PartialOwner
{
    // This is owned by PartialOwner
    std::shared_ptr<int> pi{};

    void take_ownership(std::shared_ptr<int> value) { pi = std::move(value); }
    void done() { pi = nullptr; }
};

TEST_CASE("PartialOwner")
{
    PartialOwner owner1{};
    PartialOwner owner2{};
    PartialOwner owner3{};

    {
        std::shared_ptr<int> i{std::make_shared<int>(10)};
        CHECK(i.use_count() == 1);
        owner1.take_ownership(i);
        CHECK(i.use_count() == 2);
        owner2.take_ownership(i);
        CHECK(i.use_count() == 3);
        owner3.take_ownership(i);
        CHECK(i.use_count() == 4);
        CHECK(owner1.pi.use_count() == 4);
        CHECK(owner2.pi.use_count() == 4);
        CHECK(owner3.pi.use_count() == 4);
    }
    CHECK(owner1.pi.use_count() == 3);
    CHECK(owner2.pi.use_count() == 3);
    CHECK(owner3.pi.use_count() == 3);
    owner3.done();
    CHECK(owner1.pi.use_count() == 2);
    CHECK(owner2.pi.use_count() == 2);
    owner1.done();
    CHECK(owner2.pi.use_count() == 1);
    owner2.done();
}

} // namespace ownership_1