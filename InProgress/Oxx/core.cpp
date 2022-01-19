#include "core.hpp"

#include <algorithm>

namespace oxx::core {

namespace rng = std::ranges;

bool is_partial_character_match(CharacterMatch match)
{
    return match != CharacterMatch::no_match;
}

bool is_perfect_character_match(CharacterMatch match)
{
    return match == CharacterMatch::perfect_match;
}

CharacterMatch
get_character_match(char guess, std::size_t index, const std::string& solution)
{
    if (index < solution.size() && solution[index] == guess) {
        return CharacterMatch::perfect_match;
    }
    if (solution.find(guess) != std::string::npos) {
        return CharacterMatch::partial_match;
    }
    return CharacterMatch::no_match;
}

Match::Match(const std::string& word_to_guess, const std::string& proposed_solution)
    : word_to_guess(word_to_guess), proposed_solution(proposed_solution)
{
    for (auto i{0}; i < std::ssize(word_to_guess); ++i) {
        character_matches.push_back(
            get_character_match(proposed_solution[i], i, word_to_guess));
    }
}

bool Match::is_perfect_match() const
{
    return rng::all_of(character_matches, [](auto match) {
        return is_perfect_character_match(match);
    });
}

char describe_character_match(CharacterMatch char_match)
{
    if (is_perfect_character_match(char_match)) {
        return '+';
    }
    if (is_partial_character_match(char_match)) {
        return '-';
    }
    return '.';
}

std::string Match::describe() const
{
    std::string result{};
    for (const auto char_match : character_matches) {
        result += describe_character_match(char_match);
    }
    return result;
}
} // namespace oxx::core