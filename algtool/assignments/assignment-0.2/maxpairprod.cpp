
#include <stdint.h>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int64_t MaxPairwiseProduct(const vector<int>& numbers) {
  int max_index1 = -1;
  int max_index2 = -1;
  int64_t result = 0;
  int n = numbers.size();

  for (int i = 0; i < n; ++i)
    if (max_index1 == -1 || numbers[max_index1] < numbers[i])
      max_index1 = i;

  for (int i = 0; i < n; ++i)
    if ( (i != max_index1) &&
         (max_index2 == -1 ||
          numbers[max_index2] < numbers[i]) )
      max_index2 = i;

  result = static_cast<int64_t>(
      numbers[max_index1]) * static_cast<int64_t>(numbers[max_index2]);

  return result;
}

int32_t main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    int64_t result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
