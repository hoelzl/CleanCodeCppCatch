#include "cli.hpp"

#include <iostream>

void oxx::cli::CommandLinePlayer::new_game(int num_chars)
{
    std::cout << "\nLet's play a new game!\n";
    std::cout << "The word to guess has " << num_chars << " letters.\n";
}

std::string oxx::cli::CommandLinePlayer::guess_word(int num_chars)
{
    std::string guess;
    std::cout << "Please enter a word: ";
    std::cin >> guess;
    return guess;
}

void oxx::cli::CommandLinePlayer::game_over(const game::GameResult& result)
{
    std::cout << "Game over.\n";
}

void oxx::cli::CommandLineNotifier::display_message(std::string_view message)
{
    std::cout << message << "\n";
}

void oxx::cli::CommandLineNotifier::note_updated_matches(std::vector<game::Match> matches)
{
    for (auto& match : matches) {
        std::cout << match.proposed_solution1() << "\n";
        std::cout << match.describe() << "\n";
    }
}
