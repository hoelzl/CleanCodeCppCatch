#pragma once
#include <array>
#include <optional>
#include <vector>

class Stack
{
private:
    std::vector<int> elements{};
    std::optional<int> default_value{};

public:
    [[nodiscard]] bool is_empty() const noexcept;
    void push(int element);
    int pop();
    [[nodiscard]] std::size_t size() const noexcept;
    [[nodiscard]] std::size_t count(int element) const noexcept;
    int pop_default(int the_default_value) noexcept;
    void set_default(int the_default_value) noexcept;
    void clear_default() noexcept;

private:
    [[nodiscard]] int pop_empty_stack() const;
    int pop_nonempty_stack() noexcept;
};

class BoundedStack
{
public:
    static constexpr std::size_t max_size{16};

private:
    std::array<int, max_size> elements{};
    std::size_t next_index{0};
    std::optional<int> default_value{};

public:
    [[nodiscard]] bool is_empty() const noexcept;
    [[nodiscard]] bool is_full() const noexcept;
    void push(int element);
    int pop();
    [[nodiscard]] std::size_t size() const noexcept;
    [[nodiscard]] std::size_t count(int element) const noexcept;
    int pop_default(int the_default_value) noexcept;
    void set_default(int new_default_value) noexcept;
    void clear_default() noexcept;

private:
    [[nodiscard]] int pop_empty_stack() const;
    int pop_nonempty_stack() noexcept;
};
