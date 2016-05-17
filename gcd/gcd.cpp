// Copyright 2016

#include <iostream>

int64_t gcd(int64_t a, int64_t b) {
  int64_t reminder = a % b;
  return reminder ? gcd(b, reminder) : b;
}

int main() {
  int64_t a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << "\n";

  return 0;
}
