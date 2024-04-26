#include <iostream>
#include "../include/NumberSystems.hpp"

int main(int argc, char *argv[]) {
  NumberSystems a = 10, b = 15, c;
  c = a + b;
  std::cout << c << std::endl;
  c = a - b;
  std::cout << c << std::endl;
  return 0;
}
