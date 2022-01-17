#include "stack.h"

#include <stdexcept>

bool Stack::is_empty() const noexcept { return elements.empty(); }

void Stack::push(int element) { elements.push_back(element); }

int Stack::pop()
{
    if (is_empty()) {
        return pop_empty_stack();
    }
    return pop_nonempty_stack();
}

std::size_t Stack::size() const noexcept { return elements.size(); }

std::size_t Stack::count(int element) const noexcept
{
    return std::count(std::cbegin(elements), std::cend(elements), element);
}

int Stack::pop_default(int the_default_value) noexcept
{
    if (is_empty()) {
        return the_default_value;
    }
    return pop_nonempty_stack();
}

void Stack::set_default(int the_default_value) noexcept
{
    default_value = the_default_value;
}

void Stack::clear_default() noexcept { default_value.reset(); }

int Stack::pop_empty_stack() const
{
    if (default_value.has_value()) {
        return default_value.value();
    }
    throw std::out_of_range("Cannot pop an empty stack.");
}

int Stack::pop_nonempty_stack() noexcept
{
    const int result{elements.back()};
    elements.pop_back();
    return result;
}

/// Implementation of StackV2

bool BoundedStack::is_empty() const noexcept { return size() == 0; }

bool BoundedStack::is_full() const noexcept { return next_index >= elements.size(); }

void BoundedStack::push(int element)
{
    if (!is_full()) {
        elements.at(next_index) = element;
        ++next_index;
    }
    else {
        throw std::out_of_range("Cannot push on a full stack.");
    }
}

int BoundedStack::pop()
{
    if (is_empty()) {
        return pop_empty_stack();
    }
    return pop_nonempty_stack();
}

std::size_t BoundedStack::size() const noexcept { return next_index; }

std::size_t BoundedStack::count(int element) const noexcept
{
    // The commented-out implementation is wrong!
    // It counts all the occurrences of element on the stack, not just
    // those in the "active region".
    // return std::count(std::cbegin(elements), std::cend(elements), element);
    const auto& begin_it = std::cbegin(elements);
    return std::count(
        begin_it, begin_it + static_cast<std::ptrdiff_t>(next_index), element);
}

int BoundedStack::pop_default(int the_default_value) noexcept
{
    if (is_empty()) {
        return the_default_value;
    }
    return pop_nonempty_stack();
}

void BoundedStack::set_default(int new_default_value) noexcept
{
    default_value = new_default_value;
}

void BoundedStack::clear_default() noexcept { default_value.reset(); }

int BoundedStack::pop_empty_stack() const
{
    if (default_value.has_value()) {
        return default_value.value();
    }
    throw std::out_of_range("Cannot pop an empty stack.");
}

int BoundedStack::pop_nonempty_stack() noexcept
{
    --next_index;
    return elements.at(next_index);
}
