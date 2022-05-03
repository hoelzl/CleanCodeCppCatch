#include <array>
#include <stdexcept>

class Stack
{
public:
    static constexpr std::size_t max_size{16};

private:
    std::array<int, max_size> elements{};
    std::size_t next_index{0};

public:
    [[nodiscard]] bool is_empty() const { return size() == 0; }
    
	[[nodiscard]] bool is_full() const { return next_index >= elements.size(); }
    
	void push(int element)
    {
        if (!is_full()) {
            elements.at(next_index) = element;
            ++next_index;
        }
        else {
            throw std::out_of_range("Cannot push on a full stack.");
        }
    }

    int pop()
    {
        if (is_empty()) {
            throw std::out_of_range("Cannot pop an empty stack.");
        }
        --next_index;
        return elements.at(next_index);
    }

    [[nodiscard]] std::size_t size() const { return next_index; }
};
