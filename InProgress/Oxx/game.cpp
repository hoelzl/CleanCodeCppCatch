#include "game.hpp"

#include <stdexcept>

namespace oxx::game {

std::unique_ptr<GameResult> GameResult::create(const Game& game)
{
    switch (game.get_state()) {
    case GameState::lost: return std::make_unique<Loss>();
    case GameState::won: return std::make_unique<Win>();
    case GameState::in_progress:
    case GameState::not_started:
        throw std::logic_error{"Cannot create result from inconclusive game state."};
    }
    throw std::logic_error{"Got unknown game state."};
}

std::string Win::get_summary() const
{
    return "Congratulations! You won!";
}

std::string Loss::get_summary() const
{
    return "Sorry, you lost :(";
}
} // namespace oxx::game
