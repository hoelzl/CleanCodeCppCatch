#include "EmployeeDao.hpp"
#include <catch2/catch_test_macros.hpp>

using namespace employee_completed_simplified;

TEST_CASE("SaveResult::operator&")
{
    CHECK((SaveResult::failed & SaveResult:: failed) == SaveResult::failed);
    CHECK((SaveResult::failed & SaveResult:: successful) == SaveResult::failed);
    CHECK((SaveResult::successful & SaveResult:: failed) == SaveResult::failed);
    CHECK((SaveResult::successful & SaveResult:: successful) == SaveResult::successful);
}

TEST_CASE("SaveResult::operator|")
{
    CHECK((SaveResult::failed | SaveResult:: failed) == SaveResult::failed);
    CHECK((SaveResult::failed | SaveResult:: successful) == SaveResult::successful);
    CHECK((SaveResult::successful | SaveResult:: failed) == SaveResult::successful);
    CHECK((SaveResult::successful | SaveResult:: successful) == SaveResult::successful);
}

TEST_CASE("SaveResult::operator!")
{
    CHECK(!SaveResult:: failed == SaveResult::successful);
    CHECK(!SaveResult:: successful == SaveResult::failed);
}

TEST_CASE("SaveResult::operator&=")
{
    SECTION("original value is failed")
    {
        auto save_result{SaveResult::failed};
        
        SECTION("remains failed for failed other value")
        {
            save_result &= SaveResult::failed;
            CHECK(save_result == SaveResult::failed);
        }

        SECTION("remains failed for successful other value")
        {
            save_result &= SaveResult::successful;
            CHECK(save_result == SaveResult::failed);
        }
    }

    SECTION("original value is successful")
    {
        auto save_result{SaveResult::successful};
        
        SECTION("becomes failed for failed other value")
        {
            save_result &= SaveResult::failed;
            CHECK(save_result == SaveResult::failed);
        }

        SECTION("remains successful for successful other value")
        {
            save_result &= SaveResult::successful;
            CHECK(save_result == SaveResult::successful);
        }
    }
}


TEST_CASE("SaveResult::operator|=")
{
    SECTION("original value is failed")
    {
        auto save_result{SaveResult::failed};
        
        SECTION("remains failed for failed other value")
        {
            save_result |= SaveResult::failed;
            CHECK(save_result == SaveResult::failed);
        }

        SECTION("becomes successful for successful other value")
        {
            save_result |= SaveResult::successful;
            CHECK(save_result == SaveResult::successful);
        }
    }

    SECTION("original value is successful")
    {
        auto save_result{SaveResult::successful};
        
        SECTION("remains successful for failed other value")
        {
            save_result |= SaveResult::failed;
            CHECK(save_result == SaveResult::successful);
        }

        SECTION("remains successful for successful other value")
        {
            save_result |= SaveResult::successful;
            CHECK(save_result == SaveResult::successful);
        }
    }
}
