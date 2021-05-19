// Created by Dr. Matthias Hölzl on 19/05/2021.
// Copyright (c) 2021 Dr. Matthias Hölzl. See file LICENSE.md.

#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
  std::vector<int> numbers = {};
  std::cout << std::reduce(begin(numbers), end(numbers)) << std::endl;

  std::vector<int>::iterator::value_type x{};
  std::cout << "x = " << x << ", typeid = " << typeid(x).name() << std::endl;

  std::vector<int *>::iterator::value_type xp{};
  std::vector<int *>::iterator::pointer xpp{};
  std::cout << "xp = " << xp << ", typeid = " << typeid(xp).name() << std::endl;

  return 0;
}
