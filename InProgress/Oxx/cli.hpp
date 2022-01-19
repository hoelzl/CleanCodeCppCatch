// Copyright (c) 2022 Dr. Matthias Hölzl.

#pragma once
#ifndef OXX_CLI_HPP
#define OXX_CLI_HPP

#include "game.hpp"

namespace oxx::cli {
using Player = game::Player;
using Notifier = game::Notifier;

class CommandLinePlayer final : public Player
{
public:
    using Player::Player;

    void new_game(int num_chars) override;
    [[nodiscard]] std::string guess_word(int num_chars) override;
    void game_over(const game::GameResult& result) override;
};

class CommandLineNotifier final : public Notifier
{
public:
    void display_message(std::string_view message) override;
    void note_updated_matches(std::vector<game::Match> matches) override;
};

}

#endif // OXX_CLI_HPP