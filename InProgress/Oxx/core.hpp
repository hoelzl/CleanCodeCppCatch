// ReSharper disable CppClangTidyCppcoreguidelinesNonPrivateMemberVariablesInClasses
#ifndef OXX_CORE_HPP
#define OXX_CORE_HPP

#include <string>
#include <vector>

namespace oxx::core {

enum class CharacterMatch
{
    no_match,
    partial_match,
    perfect_match,
};

bool is_partial_character_match(CharacterMatch match);
bool is_perfect_character_match(CharacterMatch match);
char describe_character_match(CharacterMatch char_match);

CharacterMatch
get_character_match(char guess, std::size_t index, const std::string& solution);

class Match
{
public:
    Match(const std::string& word_to_guess, const std::string& proposed_solution);
    [[nodiscard]] bool is_perfect_match() const;
    [[nodiscard]] std::string describe() const;
    [[nodiscard]] std::string proposed_solution1() const { return proposed_solution; }

private:
    std::string word_to_guess{};
    std::string proposed_solution{};
    std::vector<CharacterMatch> character_matches{};
};

} // namespace oxx::core
#endif // OXX_CORE_HPP
