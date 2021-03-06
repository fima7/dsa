// Copyright 2016, Konstantin Pachuev
#include <iostream>
#include <vector>

using std::vector;

//  Finds item with max of wight/value
int find_best_item(const vector<uint32_t> & w, const vector<uint32_t> & v) {
  int best_item = 0;
  double unit_value = 0.0;
  double max_unit_value = 0.0;
  for (int i = 0; i < w.size(); ++i) {
      unit_value = static_cast<double>(v[i])/static_cast<double>(w[i]);
      if ( max_unit_value < unit_value ) {
        max_unit_value = unit_value;
        best_item = i;
      }
  }
  return best_item;
}

double get_optimal_value(uint32_t W,
                         vector<uint32_t> w,
                         vector<uint32_t> v) {
  double value = 0.0;

  while (w.size() > 0 && W != 0) {
    // 1. Find best item
    int best_item = find_best_item(w, v);

    double best_unit_value =
        static_cast<double>(v[best_item]) / static_cast<double>(w[best_item]);

    // 2. Put best item to sack
    if ( W >= w[best_item] ) {  // Sack has enough room to place whole item
      W -= w[best_item];
      value += static_cast<double>(v[best_item]);
      w.erase(w.begin() + best_item);
      v.erase(v.begin() + best_item);
    } else {  // Sack less than item
      value += static_cast<double>(W) * best_unit_value;
      return value;  // Sack is full
    }
  }
  return value;  // no more value left
}

int main() {
  uint64_t n;
  uint64_t capacity;
  std::cin >> n >> capacity;

  if (n < 1 || n > 1000)
    return -1;
  if (capacity > 2000000)
    return -1;

  vector<uint32_t> values;
  vector<uint32_t> weights;
  uint32_t v, w;
  for (int i = 0; i < n; i++) {
    std::cin >> v >> w;
    // 2016 Economy and Physical conditions: we have a cost limits and gravity.
    if (v >= 0 && v <= 2000000 &&
        w > 0 && w <= 2000000 ) {
      values.push_back(v);
      weights.push_back(w);
    }
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
