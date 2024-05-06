#include <iostream>
#include "NumberSystems.hpp"

int main(int argc, char *argv[]) {
  NumberSystems a = {"FF", 16};
  a.toDec();
  std::cout << a << std::endl;
  return 0;
}
