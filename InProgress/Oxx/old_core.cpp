class CharacterMatch
{
protected:
    char proposed_char{};

public:
    explicit CharacterMatch(char proposed_char);

    CharacterMatch(const CharacterMatch& other) = delete;
    CharacterMatch(CharacterMatch&& other) noexcept = delete;
    CharacterMatch& operator=(const CharacterMatch& other) = delete;
    CharacterMatch& operator=(CharacterMatch&& other) noexcept = delete;
    virtual ~CharacterMatch() = default;

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
