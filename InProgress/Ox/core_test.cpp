#include <catch2/catch_test_macros.hpp>
#include "core.h"

TEST_CASE("character matchers")
{
    SECTION("PerfectMatch")
    {
        PerfectMatch match{'a'};
        CHECK(match.is_perfect_match());
        CHECK(match.is_partial_match());
    }
    SECTION("PartialMatch")
    {
        PartialMatch match{'b'};
        CHECK_FALSE(match.is_perfect_match());
        CHECK(match.is_partial_match());
    }
    SECTION("FailedMatch")
    {
        FailedMatch match{'c'};
        CHECK_FALSE(match.is_perfect_match());
        CHECK_FALSE(match.is_partial_match());
    }
}

TEST_CASE("match_chars")
{
    SECTION("perfect match")
    {
        std::unique_ptr<CharacterMatch> match{
                get_character_match('b', 1, "abc")};
        CHECK(dynamic_cast<PerfectMatch*>(match.get()));
    }

    SECTION("partial match")
    {
        std::unique_ptr<CharacterMatch> match{
                get_character_match('b', 0, "abc")};
        CHECK(dynamic_cast<PartialMatch*>(match.get()));
    }

    SECTION("failed match")
    {
        std::unique_ptr<CharacterMatch> match{
                get_character_match('x', 0, "abc")};
        CHECK(dynamic_cast<FailedMatch*>(match.get()));
    }
}

TEST_CASE("match strings")
{
    SECTION("perfect match")
    {
        Match match{"word", "word"};
        CHECK(match.is_perfect_match());
    }
    SECTION("failed match")
    {
        Match match{"word", "games"};
        CHECK_FALSE(match.is_perfect_match());
    }
}

TEST_CASE("describe match")
{
    Match match{"word", "warped"};
    CHECK(match.describe() == "+.+-");
}
