// Created by Dr. Matthias Hölzl on 19/05/2021.
// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#ifndef CLOCKTIMER_CLOCK_TIMER_HPP
#define CLOCKTIMER_CLOCK_TIMER_HPP
#ifdef __clang__
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#endif
#ifdef _MSC_VER
#pragma warning(disable : 4996)
#endif

#include <chrono>
#include <ctime>

class ClockTimer
{
public:
    // ReSharper disable once CppMemberFunctionMayBeStatic
    [[nodiscard]] std::tm get_current_time_as_tm()
    {
        using namespace std::chrono;
        const time_point<system_clock> current_time_point{system_clock::now()};
        const std::time_t current_time_t{system_clock::to_time_t(current_time_point)};
        // ReSharper disable once CppDeprecatedEntity
        const std::tm* current_time_tm{localtime(&current_time_t)};
        return *current_time_tm;
    }

    // The more correct return type would be std::chrono::milliseconds::rep,
    // but let's keep things simple.
    [[nodiscard]] long long get_ms_since_epoch() const
    {
        using namespace std::chrono;
        const time_point<steady_clock> current_time_point{steady_clock::now()};
        const auto duration{duration_cast<milliseconds>(
                current_time_point.time_since_epoch())};
        return duration.count();
    }
};

#endif//CLOCKTIMER_CLOCK_TIMER_HPP
