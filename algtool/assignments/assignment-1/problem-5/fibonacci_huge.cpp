// Copyright 2016, Konstantin Pachuev
#include <iostream>

#ifdef FIMA_LOCAL
#include <utility>
#include <algorithm>
#include "colormod.hpp"
#endif  // FIMA_LOCAL

#define unlikely(expr) __builtin_expect(!!(expr), 0)

#ifdef FIMA_LOCAL
// pair.first = fib number
// pair.second = Pisano period start
std::pair<uint64_t, uint64_t> get_pisano_period(uint64_t n, uint64_t m) {
  if ( unlikely(m < 2) )
    return std::make_pair(0, 0);
  if ( unlikely(m > 100000) )
    return std::make_pair(0, 0);
  if ( unlikely(n < 2) )
    return std::make_pair(n, 0);

  uint64_t fib = 0;
  uint64_t fib_1 = 0;
  uint64_t fib_2 = 1;

  // Find beginning of Pisano period

  int period_begin = 0;
  uint64_t k;
  for (k = 2; k < m*m; ++k) {
    fib = fib_1 + fib_2;
    if ( ((fib % m) == 1) && ((fib_2 % m) == 0) ) {
      break;
    }
    fib_1 = fib_2;
    fib_2 = fib;
  }
  period_begin = k - 1;

  fib = 0;
  fib_1 = 0;
  fib_2 = 1;

  // Find number
  for (uint64_t i = 2; i <= n; ++i) {
    fib = fib_1 + fib_2;
    fib_1 = fib_2;
    fib_2 = fib;
  }
  return std::make_pair(fib % m, period_begin);
}
#endif  // FIMA_LOCAL

uint64_t get_fibonaccihuge(uint64_t n, uint64_t m) {
  if ( unlikely(m < 2) )
    return 0;
  if ( unlikely(m > 100000) )
    return 0;
  if ( unlikely(n < 2) )
    return n % m;

  uint64_t fib = 0;
  uint64_t fib_1 = 0;
  uint64_t fib_2 = 1;

  // Find beginning of Pisano period
  uint64_t period = 0;
  uint64_t k;
  for (k = 2; k < m*m; ++k) {
    fib = (fib_1 % m + fib_2 % m) % m;
    if ( ((fib) == 1) && ((fib_2) == 0) ) {
      break;
    }
    fib_1 = fib_2;
    fib_2 = fib;
  }
  period = k - 1;
  uint64_t nn = n % period;

#ifdef FIMA_LOCAL
  std::cout << "n = " << n << "\n";
  std::cout << "n mod period = " << nn << "\n";
  std::cout << "period = " << period << "\n";
#endif  // FIMA_LOCAL

  if ( unlikely(nn < 2) )
    return nn;

  fib = 0;
  fib_1 = 0;
  fib_2 = 1;

  // Find F mod m number
  for (uint64_t i = 2; i <= nn; ++i) {
    fib = (fib_1 % m + fib_2 % m) % m;
    fib_1 = fib_2;
    fib_2 = fib;
  }

  return fib;
}

int main() {
    uint64_t n, m;

#ifdef FIMA_LOCAL
    color::modifier current_mod(color::code::FG_GREEN);
    color::modifier previous_mod(color::code::FG_RED);
    color::modifier default_mod(color::code::FG_DEFAULT);

    for (uint64_t m = 2; m < 32; ++m) {
      std::cout << m << ": ";
      int period = 0;
      for (uint64_t n = 0; n < 64; ++n) {
        auto result = get_pisano_period(n, m);
        if (result.second == n)
          std::swap(current_mod, previous_mod);
        std::cout << current_mod << result.first << ' ';
        period = result.second;
      }
      std::cout << default_mod << ": " << period << "\n";
    }
#endif  // FIMA_LOCAL
    std::cin >> n >> m;
    std::cout << get_fibonaccihuge(n, m) << '\n';
    return 0;
}
