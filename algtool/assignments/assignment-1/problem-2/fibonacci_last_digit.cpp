// Copyright 2016, Konstantin Pachuev
#include <iostream>

#define unlikely(expr) __builtin_expect(!!(expr), 0)

int get_fibonacci_last_digit(int n) {
  if ( unlikely(n > 10000000) )
    return -1;
  if ( unlikely(n < 0) )
    return -1;

  if ( unlikely(n < 2) )
    return n;

  uint32_t fib_1 = 0;
  uint32_t fib_2 = 1;
  uint32_t result = 0;
  for (int i = 2; i <= n; ++i) {
    result = (fib_1 + fib_2) % 10;
    fib_1 = fib_2;
    fib_2 = result;
  }
  return result;
}

int main() {
  int n;
  std::cin >> n;
  int c = get_fibonacci_last_digit(n);
  std::cout << c << '\n';
}
