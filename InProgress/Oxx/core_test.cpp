#include "core.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace oxx::core;

TEST_CASE("character matches")
{
    SECTION("PerfectMatch")
    {
        CHECK(is_perfect_character_match(CharacterMatch::perfect_match));
        CHECK(is_partial_character_match(CharacterMatch::perfect_match));
    }
    SECTION("PartialMatch")
    {
        CHECK_FALSE(is_perfect_character_match(CharacterMatch::partial_match));
        CHECK(is_partial_character_match(CharacterMatch::partial_match));
    }
    SECTION("FailedMatch")
    {
        CHECK_FALSE(is_perfect_character_match(CharacterMatch::no_match));
        CHECK_FALSE(is_partial_character_match(CharacterMatch::no_match));
    }
}

TEST_CASE("match_chars")
{
    SECTION("perfect match")
    {
        const CharacterMatch match{get_character_match('b', 1, "abc")};
        CHECK(match == CharacterMatch::perfect_match);
    }

    SECTION("partial match")
    {
        const CharacterMatch match{get_character_match('b', 0, "abc")};
        CHECK(match == CharacterMatch::partial_match);
    }

    SECTION("failed match")
    {
        const CharacterMatch match{get_character_match('x', 0, "abc")};
        CHECK(match == CharacterMatch::no_match);
    }
}

TEST_CASE("match strings")
{
    SECTION("perfect match")
    {
        const Match match{"word", "word"};
        CHECK(match.is_perfect_match());
    }
    SECTION("failed match")
    {
        const Match match{"word", "games"};
        CHECK_FALSE(match.is_perfect_match());
    }
}

TEST_CASE("describe match")
{
    const Match match{"word", "warped"};
    CHECK(match.describe() == "+.+-");
}
