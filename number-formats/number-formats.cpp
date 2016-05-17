
#include <iostream>
#include <cstring>

template <typename T>
void print_bits(T x) {
  unsigned char d[sizeof(T)];
  std::memcpy(d, &x, 4);

  for (int i = sizeof(T); i >= 0; --i) {
    unsigned char v = 0x80;
    for (int j = 7; j >= 0; v = v >> 1, --j)
      std::cout << static_cast<unsigned int>((v & d[i]) >> j);
    std::cout << " ";
  }
}


int main(int argc, char *argv[]) {
  // float x = 1.0;
  // unsigned int x = 65535;
  // std::cout << x << ":";
  float x;
  std::cin >> x;
  print_bits(x);
  std::cout << "\n";

#if 0
  for (unsigned int x = 0; x <= 65535; ++x) {
    print_bits(x);
    std::cout << "\n";
  }
#endif

  // std::printf("%f:%x%x%x%x\n", x, d[3], d[2], d[1], d[0]);

  return 0;
}
