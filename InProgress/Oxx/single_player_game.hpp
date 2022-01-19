// Copyright (c) 2022 Dr. Matthias Hölzl.

#pragma once
#ifndef OXX_DEFAULT_GAME_HPP
#define OXX_DEFAULT_GAME_HPP

#include "game.hpp"

namespace oxx::game {

class SinglePlayerGame final : public Game
{
public:
    SinglePlayerGame(
        std::shared_ptr<Player> player, std::shared_ptr<Dictionary> dictionary,
        std::unique_ptr<Notifier> notifier)
        : player{std::move(player)}
        , dictionary{std::move(dictionary)}
        , notifier{std::move(notifier)}
    {}

    void new_game() override;
    void run_game_loop() override;

    [[nodiscard]] std::shared_ptr<const GameResult> get_result() const override;
    [[nodiscard]] GameState get_state() const override;
    [[nodiscard]] std::vector<Match> get_matches() const override;

private:
    std::shared_ptr<Player> player{};
    std::shared_ptr<Dictionary> dictionary{};
    std::unique_ptr<Notifier> notifier{};
    int max_guesses{10};

    int num_guesses{0};
    std::string word_to_guess{};
    std::vector<Match> matches{};
    GameState state{GameState::not_started};

    [[nodiscard]] int expected_size() const;
    [[nodiscard]] std::string get_guess_from_player() const;
    void process_next_guess(std::string guess);
    void get_and_process_next_guess();
    void update_game_state();};

} // namespace oxx::game

#endif // OXX_DEFAULT_GAME_HPP
