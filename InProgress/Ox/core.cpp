//
// Created by tc on 08/07/2020.
//
#include "core.h"

CharacterMatch::CharacterMatch(char proposed_char) : proposed_char(proposed_char) {}

PerfectMatch::PerfectMatch(char proposed_char) : CharacterMatch(proposed_char) {}

bool PerfectMatch::is_perfect_match() const { return true; }

bool PerfectMatch::is_partial_match() const { return true; }

PartialMatch::PartialMatch(char proposed_char) : CharacterMatch(proposed_char) {}

bool PartialMatch::is_perfect_match() const { return false; }

bool PartialMatch::is_partial_match() const { return true; }

FailedMatch::FailedMatch(char proposed_char) : CharacterMatch(proposed_char) {}

bool FailedMatch::is_perfect_match() const { return false; }

bool FailedMatch::is_partial_match() const { return false; }

std::unique_ptr<CharacterMatch>
get_character_match(char guess, std::size_t index, const std::string& solution)
{
    if (index < solution.size() && solution[index] == guess) {
        return std::make_unique<PerfectMatch>(guess);
    }
    if (solution.find(guess) != std::string::npos) {
        return std::make_unique<PartialMatch>(guess);
    }
    return std::make_unique<FailedMatch>(guess);
}

Match::Match(const std::string& word_to_guess, const std::string& proposed_solution)
    : word_to_guess(word_to_guess), proposed_solution(proposed_solution)
{
    for (int i{0}; i < word_to_guess.size(); ++i) {
        character_matches.push_back(
            get_character_match(word_to_guess[i], i, proposed_solution));
    }
}

bool Match::is_perfect_match() const
{
    for (auto& char_match : character_matches) {
        if (!char_match->is_perfect_match()) {
            return false;
        }
    }
    return true;
}

std::string Match::describe() const
{
    std::string result{};
    for (auto& char_match : character_matches) {
        if (char_match->is_perfect_match()) {
            result += "+";
        }
        else if (char_match->is_partial_match()) {
            result += "-";
        }
        else {
            result += ".";
        }
    }
    return result;
}
