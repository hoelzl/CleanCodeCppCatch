// Created by Dr. Matthias Hölzl on 19/05/2021.
// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

// ReSharper disable CppClangTidyCppcoreguidelinesProBoundsPointerArithmetic
#ifndef ITERATORS_ITERATORS_HPP
#define ITERATORS_ITERATORS_HPP

#include <array>
#include <iterator>

class MyClass
{
    class MyIterator
    {
        using iterator_category = std::forward_iterator_tag;
        using value_type = int;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;

    public:
        explicit MyIterator(pointer p) : ptr{p} {};

        reference operator*() const { return *ptr; }
        pointer operator->() const { return ptr; }

        MyIterator& operator++()
        {
            ptr++;
            return *this;
        }

        MyIterator operator++(int)
        {
            const MyIterator tmp{*this};
            ++(*this);
            return tmp;
        }

        friend bool operator==(const MyIterator& lhs, const MyIterator& rhs)
        {
            return lhs.ptr == rhs.ptr;
        }

        friend bool operator!=(const MyIterator& lhs, const MyIterator& rhs)
        {
            return lhs.ptr != rhs.ptr;
        }

    private:
        pointer ptr;
    }; // MyIterator

    MyIterator begin()
    {
        return MyIterator{data.data()};
    } // NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)

    MyIterator end() { return MyIterator{data.data() + data.size()}; }

private:
    std::array<int, 200> data{};
};

#endif // ITERATORS_ITERATORS_HPP
