#pragma once

#ifndef OXX_GAME_HPP
#define OXX_GAME_HPP

#include <memory>
#include <string>
#include <vector>

#include "core.hpp"

namespace oxx::game {

using Match = core::Match;

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

class Game;

class GameResult
{
public:
    GameResult() = default;
    GameResult(const GameResult& other) = delete;
    GameResult(GameResult&& other) noexcept = delete;
    GameResult& operator=(const GameResult& other) = delete;
    GameResult& operator=(GameResult&& other) noexcept = delete;
    virtual ~GameResult() = default;

    static std::unique_ptr<GameResult> create(const Game& game);
    [[nodiscard]] virtual std::string get_summary() const = 0;
};

class Win final : public GameResult
{
public:
    [[nodiscard]] std::string get_summary() const override;
};

class Loss final : public GameResult
{
public:
    [[nodiscard]] std::string get_summary() const override;
};


class Player
{
public:
    Player() = default;
    Player(const Player&) = delete;
    Player(Player&&) noexcept = delete;
    Player& operator=(const Player&) = delete;
    Player& operator=(Player&&) noexcept = delete;
    virtual ~Player() = default;

    virtual void new_game(int num_chars) = 0;
    [[nodiscard]] virtual std::string guess_word(int num_chars) = 0;
    [[maybe_unused]] virtual void game_over(const GameResult& result) = 0;
};

class Game
{
public:
    Game() = default;
    Game(const Game& other) = delete;
    Game(Game&& other) noexcept = delete;
    Game& operator=(const Game& other) = delete;
    Game& operator=(Game&& other) noexcept = delete;
    virtual ~Game() = default;

    virtual void new_game() = 0;
    virtual void run_game_loop() = 0;
    [[nodiscard]] virtual std::shared_ptr<const GameResult> get_result() const = 0;
    [[nodiscard]] virtual GameState get_state() const = 0;
    [[nodiscard]] virtual std::vector<Match> get_matches() const = 0;
};

class Notifier
{
public:
    Notifier() = default;
    Notifier(const Notifier& other) = default;
    Notifier(Notifier&& other) noexcept = default;
    Notifier& operator=(const Notifier& other) = default;
    Notifier& operator=(Notifier&& other) noexcept = default;
    virtual ~Notifier() = default;

    virtual void display_message(std::string_view message) = 0;

    virtual void note_updated_matches(std::vector<Match> matches) = 0;
    virtual void note_new_game(int num_chars) {}
    virtual void note_guess(const Player& player, const std::string& guess) {}
    virtual void note_result(const GameResult& result) {}
};
} // namespace oxx::game

#endif
