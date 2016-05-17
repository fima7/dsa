// Copyright 2016, Konstantin Pachuev
#include <iostream>

#define unlikely(expr) __builtin_expect(!!(expr), 0)

int gcd(int a, int b) {
  if ( unlikely(a < 0) )
    return -1;
  if ( unlikely(a > 2000000000) )
    return -1;
  if ( unlikely(b < 0) )
    return -1;
  if ( unlikely(b > 2000000000) )
    return -1;

  // recursion free
  int reminder = a % b;
  while ( unlikely(reminder != 0) ) {
    a = b;
    b = reminder;
    reminder = a % b;
  }
  return b;
#if 0
  int reminder = a % b;
  if ( unlikely(reminder == 0) )
    return b;

  return gcd(b, reminder);
#endif
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
