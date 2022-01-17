// Created by Dr. Matthias Hölzl on 19/05/2021.
// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "clock_timer.hpp"
#include <thread>

TEST_CASE("Tests for the Clock Timer."){
    SECTION("Tests for get_current_time_as_tm") {
        ClockTimer ct{};
        const std::tm current_time{ct.get_current_time_as_tm()};
        // Test written in May 2021, so...
        REQUIRE(current_time.tm_year >= 2021 - 1900);
        REQUIRE(current_time.tm_mon >= 5 - 1);
    }
    SECTION("Tests for get_ms_since_epoch") {
        using namespace std::chrono_literals;
        ClockTimer ct{};
        const long long time1{ct.get_ms_since_epoch()};
        std::this_thread::sleep_for(100ms);
        const long long time2{ct.get_ms_since_epoch()};
        REQUIRE(time2 - time1 >= 100);
        REQUIRE(time2 - time1 < 200);
    }
}
