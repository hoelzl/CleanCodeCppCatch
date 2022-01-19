#include "single_player_game.hpp"

namespace oxx::game {

void SinglePlayerGame::new_game()
{
    num_guesses = 0;
    word_to_guess = dictionary->get_random_word();
    matches.clear();
    state = GameState::in_progress;

    player->new_game(expected_size());
}

void SinglePlayerGame::run_game_loop()
{
    while (num_guesses < max_guesses && state == GameState::in_progress) {
        ++num_guesses;
        get_and_process_next_guess();
        update_game_state();
    }
}

std::shared_ptr<const GameResult> SinglePlayerGame::get_result() const
{
    return GameResult::create(*this);
}

GameState SinglePlayerGame::get_state() const { return state; }

std::vector<Match> SinglePlayerGame::get_matches() const { return matches; }

int SinglePlayerGame::expected_size() const
{
    return static_cast<int>(std::ssize(word_to_guess));
}

std::string SinglePlayerGame::get_guess_from_player() const
{
    return player->guess_word(expected_size());
}

void SinglePlayerGame::process_next_guess(const std::string guess) {
    const auto match{Match{word_to_guess, guess}};
    matches.push_back(match);
}

void SinglePlayerGame::get_and_process_next_guess()
{
    const auto guess{get_guess_from_player()};
    process_next_guess(guess);
    notifier->note_updated_matches(matches);
}

void SinglePlayerGame::update_game_state()
{
    const auto match{matches.back()};
    if (match.is_perfect_match()) {
        state = GameState::won;
    }
    else if (num_guesses >= max_guesses) {
        state = GameState::lost;
    }
}

} // namespace oxx::game
