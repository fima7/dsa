#include <iostream>

int main(){
  int a = 0;
  int b = 0;
  int sum = 0;
  std::cin >> a;
  std::cin >> b;
  if (0 <= a && a <= 9 && 0 <= b && b <= 9) {
    sum = a + b;
    std::cout << sum;
    return 0;
  }
  std::cout << "Error: either a or b is less than 0 or greater than 9" << std::endl;
  return -1;
}
