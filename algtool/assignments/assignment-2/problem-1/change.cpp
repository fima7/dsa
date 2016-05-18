// Copyright 2016, Konstantin Pachuev
#include <iostream>

#define unlikely(expr) __builtin_expect(!!(expr), 0)

int get_change(int m) {
  if ( unlikely(m < 1) )
    return 0;
  if ( unlikely(m > 1000) )
    return 0;

  int f10 = m / 10;
  int f5 = m % 10 / 5;
  int f1 = (m % 10) % 5;

  return f10 + f5 + f1;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
