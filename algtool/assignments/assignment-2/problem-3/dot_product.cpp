// Copyright 2016, Konstantin Pachuev
#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

using std::vector;

size_t max(const vector<int32_t> & a) {
  size_t max_i = 0;
  int32_t max = std::numeric_limits<int32_t>::min();
  for (int i = 0; i < a.size(); ++i)
    if (a[i] > max) {
      max = a[i];
      max_i = i;
    }
  return max_i;
}

size_t min(const vector<int32_t> & a) {
  size_t min_i = 0;
  int32_t min = std::numeric_limits<int32_t>::max();
  for (int i = 0; i < a.size(); ++i)
    if (a[i] < min) {
      min = a[i];
      min_i = i;
    }
  return min_i;
}

int64_t min_dot_product(vector<int32_t> a, vector<int32_t> b) {
  int64_t result = 0;
  size_t i, j;
  while ( a.size() > 0 ) {
    i = min(a);
    j = max(b);
#ifdef FIMA_LOCAL
    std::cout << "min: " << i << '\n';
    std::cout << "max: " << j << '\n';
#endif
    result += static_cast<int64_t>(a[i])*static_cast<int64_t>(b[j]);
    a.erase(a.begin() + i);
    b.erase(b.begin() + j);
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  if ( n < 1 || n > 1000 )
    return -1;

  vector<int32_t> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
    if ( a[i] < -100000 || a[i] > 100000 )
      return -1;
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
    if ( b[i] < -100000 || b[i] > 100000 )
      return -1;
  }
  std::cout << min_dot_product(a, b) << std::endl;
  return 0;
}
