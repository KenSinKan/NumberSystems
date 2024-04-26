#include <string>

int CharToInt(char x) {
  if (x == '-')
    return -1;
  if (x >= '0' && x <= '9')
    return x - '0';
  if (x >= 'A' && x <= 'Z')
    return x - 'A' + 10;
  if (x >= 'a' && x <= 'z')
    return x - 'a' + 10;
  return 2147483647;
}

char IntToChar(int x) {
  if (x == -1)
    return '-';
  if (x >= 0 && x <= 9)
    return x + '0';
  if (x >= 10 && x <= 35)
    return x + 'A' - 10;
  return 127;
}

class NumberSystems {
private:
  std::string num;
  int base;

  // Constructors
  NumberSystems();
  NumberSystems(std::string num);
  NumberSystems(std::string num, int base);
  NumberSystems(int num);
  NumberSystems(int num, int base);
  NumberSystems(long num);
  NumberSystems(long num, int base);
  NumberSystems(long long num);
  NumberSystems(long long num, int base);

  // Getters and Setters
  std::string getNum();
  int getBase();
  void setNum(int num);
  void setNum(long num);
  void setNum(long long num);
  void setNum(std::string num);
  void setBase(int base);
  bool isNeg();
  bool isPos();
  void setNeg();
  void setPos();
  void setOtherSign();

  // Bool Operators
  bool operator==(NumberSystems ns);
  bool operator!=(NumberSystems ns);
  bool operator>(NumberSystems ns);
  bool operator<(NumberSystems ns);
  bool operator>=(NumberSystems ns);
  bool operator<=(NumberSystems ns);

  // Math Operators
  NumberSystems operator+(NumberSystems ns);
  NumberSystems operator-(NumberSystems ns);
  NumberSystems operator*(NumberSystems ns);
  NumberSystems operator/(NumberSystems ns);
  NumberSystems operator%(NumberSystems ns);

  // NumberSystems Conversion
  void toBase(int base);

  // Other
  void push_front(char x);
  void push_back(char x);
  void push_front(std::string x);
  void push_back(std::string x);
};

NumberSystems::NumberSystems() {
  num = "0";
  base = 10;
}

NumberSystems::NumberSystems(std::string num) {
  if (num.size() == 0 || (num[0] == '-' && num.size() == 1)) return;
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

void NumberSystems::setBase(int base) {
  if (base < 2 || base > 36)
    return;
  this->base = base;
}

void NumberSystems::setNum(std::string num) {
  for (char x : num) {
    if (CharToInt(x) >= base)
      return;
  }
  this->num = num;
}

bool NumberSystems::isNeg() {
  return num[0] == '-';
}

bool NumberSystems::isPos() {
  return num[0] != '-';
}

void NumberSystems::setNeg() {
  if (num[0] == '-')
    return;

  num.insert(num.begin(), '-');
}

void NumberSystems::setPos() {
  if (num[0] != '-' || (num.size() == 1 && num[0] == '0'))
    return;

  num.erase(num.begin());
}

void NumberSystems::setOtherSign() {
  if (isPos())
    setNeg();
  setPos();
}

bool NumberSystems::operator==(NumberSystems ns) {
  if (this->base != ns.base)
    ns.toBase(this->base);

  return this->num == ns.num;
}

bool NumberSystems::operator!=(NumberSystems ns) {
  if (this->base != ns.base)
    ns.toBase(this->base);

  return this->num != ns.num;
}

bool NumberSystems::operator>(NumberSystems ns) {
  if (this->base != ns.base)
    ns.toBase(this->base);

  if (this->num.size() > ns.num.size())
    return true;
  if (this->num.size() < ns.num.size())
    return false;
  return this->num > ns.num;
}

bool NumberSystems::operator<(NumberSystems ns) {
  if (this->base != ns.base)
    ns.toBase(this->base);

  if (this->num.size() < ns.num.size())
    return true;
  if (this->num.size() > ns.num.size())
    return false;
  return this->num < ns.num;
}

bool NumberSystems::operator>=(NumberSystems ns) {
  return this ->operator>(ns) || this->operator==(ns);
}

bool NumberSystems::operator<=(NumberSystems ns) {
  return this ->operator<(ns) || this->operator==(ns);
}

NumberSystems NumberSystems::operator+(NumberSystems ns) {
  if (this->base != ns.base)
    ns.toBase(this->base);
  NumberSystems ans;
  ans.setBase(this->base);
  int carry = 0;
  for (int i = this->num.size(), j = ns.num.size(); i > 0 || j > 0; i--, j--) {
    int a = 0, b = 0;
    if (i == 0) a = 0;
    else a = CharToInt(this->num[i - 1]);
    if (j == 0) b = 0;
    else b = CharToInt(ns.num[j - 1]);
    char res = IntToChar((a + b + carry) % this->base);
    carry = (a + b + carry) / this->base;
    ans.push_front(res);
  }
  if (carry != 0) ans.push_front(IntToChar(carry));
  return ans;
}

NumberSystems NumberSystems::operator-(NumberSystems ns) {
  if (this->base != ns.base)
    ns.toBase(this->base);
  NumberSystems ans;
  ans.setBase(this->base);
  int carry = 0;
  for (int i = this->num.size(), j = ns.num.size(); i > 0 || j > 0; i--, j--) {
    int a = 0, b = 0;
    if (i == 0) a = 0;
    else a = CharToInt(this->num[i - 1]);
    if (j == 0) b = 0;
    else b = CharToInt(ns.num[j - 1]);
    char res = IntToChar((a - b - carry + this->base) % this->base);
    carry = (a - b - carry + this->base) / this->base;
    ans.push_front(res);
  }
  if (carry != 0) ans.push_front(IntToChar(carry));
  return ans;
}

void NumberSystems::push_front(char c) {
  this->num.insert(this->num.begin(), c);
}

void NumberSystems::push_front(std::string c) {
  this->num.insert(this->num.begin(), c.begin(), c.end());
}

void NumberSystems::push_back(char c) {
  this->num.push_back(c);
}

void NumberSystems::push_back(std::string c) {
  this->num.insert(this->num.end(), c.begin(), c.end());
}