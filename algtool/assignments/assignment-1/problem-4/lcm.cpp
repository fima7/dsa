// Copyright 2016, Konstantin Pachuev
#include <iostream>

#define unlikely(expr) __builtin_expect(!!(expr), 0)

int64_t lcm(int a, int b) {
  if ( unlikely(a < 1) )
    return -1;
  if ( unlikely(a > 2000000000) )
    return -1;
  if ( unlikely(b < 1) )
    return -1;
  if ( unlikely(b > 2000000000) )
    return -1;


  int64_t prod_ab = static_cast<int64_t>(a) * static_cast<int64_t>(b);
  int64_t reminder = a % b;
  while ( unlikely(reminder != 0) ) {
    a = b;
    b = reminder;
    reminder = a % b;
  }
  return prod_ab / static_cast<int64_t>(b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
