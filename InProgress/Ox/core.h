#ifndef OX_CORE_H
#define OX_CORE_H

#include <memory>
#include <string>
#include <vector>

class CharacterMatch
{
protected:
    char proposed_char{};

public:
    explicit CharacterMatch(char proposed_char);
    [[nodiscard]] virtual bool is_perfect_match() const = 0;
    [[nodiscard]] virtual bool is_partial_match() const = 0;
};

class PerfectMatch : public CharacterMatch
{
public:
    explicit PerfectMatch(char proposed_char);
    [[nodiscard]] bool is_perfect_match() const override;
    [[nodiscard]] bool is_partial_match() const override;
};


class PartialMatch : public CharacterMatch
{
public:
    explicit PartialMatch(char proposed_char);
    [[nodiscard]] bool is_perfect_match() const override;
    [[nodiscard]] bool is_partial_match() const override;
};


class FailedMatch : public CharacterMatch
{
public:
    explicit FailedMatch(char proposed_char);
    [[nodiscard]] bool is_perfect_match() const override;
    [[nodiscard]] bool is_partial_match() const override;
};

std::unique_ptr<CharacterMatch>
get_character_match(char guess, std::size_t index, const std::string& solution);

class Match
{
public:
    Match(const std::string& word_to_guess, const std::string& proposed_solution);
    [[nodiscard]] bool is_perfect_match() const;
    [[nodiscard]] std::string describe() const;

private:
    std::string word_to_guess{};
    std::string proposed_solution{};
    std::vector<std::unique_ptr<CharacterMatch>> character_matches{};
};


#endif // OX_CORE_H
