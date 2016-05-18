// Copyright 2016, Konstantin Pachuev
#include <iostream>
#include <vector>

using std::vector;

vector<uint32_t> optimal_summands(uint32_t n) {
  vector<uint32_t> summands;
  uint32_t l = 0;
  while (n > 0) {
    if ( 2*(l+1) < n )
      l++;
    else
      l = n;
    summands.push_back(l);
    n = n - l;
  }
  return summands;
}

int main() {
  uint32_t n;
  std::cin >> n;
  if (n < 1 || 1000000000 < n)
    return -1;
  vector<uint32_t> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
