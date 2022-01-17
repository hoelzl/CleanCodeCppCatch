#pragma once

#include <string>

class Dictionary
{
public:
    Dictionary() = default;
    Dictionary(const Dictionary& other) = delete;
    Dictionary(Dictionary&& other) noexcept = delete;
    Dictionary& operator=(const Dictionary& other) = delete;
    Dictionary& operator=(Dictionary&& other) noexcept = delete;
    virtual ~Dictionary() = default;

    virtual std::string get_random_word() = 0;
};

enum class GameState
{
    not_started,
    in_progress,
    won,
    lost
};
