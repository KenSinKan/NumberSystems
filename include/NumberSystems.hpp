#include <string>

int CharToInt(char x) {
  if (x >= '0' && x <= '9')
    return x - '0';
  else if (x >= 'A' && x <= 'Z')
    return x - 'A' + 10;
  else if (x >= 'a' && x <= 'z')
    return x - 'a' + 10;
  else
    return 2147483647;
}

char IntToChar(int x) {
  if (x >= 0 && x <= 9)
    return x + '0';
  else if (x >= 10 && x <= 35)
    return x + 'A' - 10;
  else
    return -1;
}

class NumberSystems {
private:
std::string num;
int base;
public:
  NumberSystems();
  NumberSystems(std::string num);
  NumberSystems(std::string num, int base);
  NumberSystems(int num);
  NumberSystems(int num, int base);
  NumberSystems(long num);
  NumberSystems(long num, int base);
  NumberSystems(long long num);
  NumberSystems(long long num, int base);
  std::string getNum();
  int getBase();
  void setNum(int num);
  void setNum(long num);
  void setNum(long long num);
  void setNum(std::string num);
};

NumberSystems::NumberSystems() {
  num = "0";
  base = 10;
}

NumberSystems::NumberSystems(std::string num) {
  for (char x : num) {
    if (CharToInt(x) >= 10)
      return;
  }
  this->num = num;
  base = 10;
}

NumberSystems::NumberSystems(std::string num, int base) {
  if (base < 2 || base > 36)
    return;
  for (char x : num) {
    if (CharToInt(x) >= base)
      return;
  }
  this->num = num;
  this->base = base;
}

NumberSystems::NumberSystems(int num) {
  this->num = std::to_string(num);
  base = 10;
}

NumberSystems::NumberSystems(int num, int base) {
  if (base < 2 || base > 36)
    return;
  for (char x : std::to_string(num)) {
    if (CharToInt(x) >= base)
      return;
  }
  this->num = std::to_string(num);
  this->base = base;
}

NumberSystems::NumberSystems(long num) {
  this->num = std::to_string(num);
  base = 10;
}

NumberSystems::NumberSystems(long num, int base) {
  if (base < 2 || base > 36)
    return;
  for (char x : std::to_string(num)) {
    if (CharToInt(x) >= base)
      return;
  }
  this->num = std::to_string(num);
  this->base = base;
}

NumberSystems::NumberSystems(long long num) {
  this->num = std::to_string(num);
  base = 10;
}

NumberSystems::NumberSystems(long long num, int base) {
  if (base < 2 || base > 36)
    return;
  for (char x : std::to_string(num)) {
    if (CharToInt(x) >= base)
      return;
  }
  this->num = std::to_string(num);
  this->base = base;
}

std::string NumberSystems::getNum() {
  return num;
}

int NumberSystems::getBase() {
  return base;
}

void NumberSystems::setNum(int num) {
  for (char x : std::to_string(num)) {
    if (CharToInt(x) >= base)
      return;
  }
  this->num = std::to_string(num);
}

void NumberSystems::setNum(long num) {
  for (char x : std::to_string(num)) {
    if (CharToInt(x) >= base)
      return;
  }
  this->num = std::to_string(num);
}

void NumberSystems::setNum(long long num) {
  for (char x : std::to_string(num)) {
    if (CharToInt(x) >= base)
      return;
  }
  this->num = std::to_string(num);
}

void NumberSystems::setNum(std::string num) {
  for (char x : num) {
    if (CharToInt(x) >= base)
      return;
  }
  this->num = num;
}