// Copyright 2016, Konstantin Pachuev
#include <iostream>
#include <cstdint>

#define unlikely(expr) __builtin_expect(!!(expr), 0)

uint64_t calc_fib(int n) {
  if ( unlikely(n > 45) )
    return 0;

  if ( unlikely(n < 2) )
    return static_cast<uint64_t>(n);

  uint64_t result = 0;
  uint64_t fib_1 = 0;
  uint64_t fib_2 = 1;
  for (int i = 2; i <= n; ++i) {
    result = fib_1 + fib_2;
    fib_1 = fib_2;
    fib_2 = result;
  }
  return result;
}

int main() {
  uint32_t n = 0;
  std::cin >> n;
  std::cout << calc_fib(n) << '\n';
  return 0;
}
