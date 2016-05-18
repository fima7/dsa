// Copyright 2016, Konstantin Pachuev
#include <iostream>
#include <vector>

using std::vector;

//  Finds item with max of wight/value
int find_best_item(const vector<uint32_t> & w, const vector<uint32_t> & v) {
  int best_item = -1;
  double unit_value = 0.0;
  double max_unit_value = 0.0;
  for (int i = 0; i < w.size(); ++i) {
    unit_value = static_cast<double>(v[i])/static_cast<double>(w[i]);
#ifdef FIMA_LOCAL
    std::cout << "wi=" << w[i] << ", "
              << "vi=" << v[i] << ", "
              << "uv=" << unit_value << "\n";
#endif
    if ( max_unit_value < unit_value ) {
      max_unit_value = unit_value;
      best_item = i;
    }
  }
  return best_item;
}

double get_optimal_value(uint32_t capacity,
                         vector<uint32_t> w,
                         vector<uint32_t> v) {
  double value = 0.0;
  uint32_t W = capacity;

  while (w.size() > 0 && W != 0) {
#ifdef FIMA_LOCAL
    std::cout << "begin <items: " << w.size() << ", W: " << W << ">\n";
#endif

    // 1. Find best item
    int best_item = find_best_item(w, v);
    double best_unit_value =
        static_cast<double>(v[best_item]) / static_cast<double>(w[best_item]);
#ifdef FIMA_LOCAL
    std::cout << "Best item is #" << best_item << ", "
              << "unit cost is " << best_unit_value << ". \n";
#endif
    // 2. Put best item to sack
    if ( W >= w[best_item] ) {  // Sack has enough room to place whole item
      W -= w[best_item];
      value += static_cast<double>(v[best_item]);
#ifdef FIMA_LOCAL
      std::cout << " value: " << value << "\n";
#endif
      w.erase(w.begin() + best_item);
      v.erase(v.begin() + best_item);
#ifdef FIMA_LOCAL
      std::cout << " removing #" << best_item << "\n";
#endif
    } else {  // Sack less than item
      value += static_cast<double>(W) * best_unit_value;
      return value;  // Sack is full
    }
#ifdef FIMA_LOCAL
    std::cout << "end <items: " << w.size() << ", W: " << W << ">\n";
#endif
  }

#ifdef FIMA_LOCAL
  std::cout << "exit value: " << value << "\n";
#endif
  return value;  // no more value left
}

int main() {
  int n;
  uint64_t capacity;
  std::cin >> n >> capacity;

  if (n < 1 || n > 1000)
    return -1;
  if (capacity > 2000000)
    return -1;

  vector<uint32_t> values(n);
  vector<uint32_t> weights(n);
  for (int i = 0; i < n; i++) {
    if (values[i] < 0 || values[i] > 2000000)
      return -1;
    if (weights[i] < 0 || weights[i] > 2000000)
      return -1;
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
