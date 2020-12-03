#pragma once

#include <string>

class Dictionary
{
public:
    virtual ~Dictionary() = default;
    virtual std::string get_random_word() = 0;
};

enum class GameState
{
    NotStarted,
    InProgress,
    Won,
    Lost
};

