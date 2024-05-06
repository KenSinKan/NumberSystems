#include <string>
#include <iostream>

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
  
public:
  // Constructors
  NumberSystems();
  NumberSystems(std::string num);
  NumberSystems(std::string num, int base);
  NumberSystems(int num);
  NumberSystems(int num, int base);

  // Getters and Setters
  std::string getNum();
  int getBase();
  void setNum(int num);
  void setNum(std::string num);
  void setBase(int base);
  
  // Sign methods
  bool isNeg();
  bool isPos();
  void setNeg();
  void setPos();
  void setOtherSign();
  NumberSystems getNeg();
  NumberSystems getPos();
  NumberSystems getOtherSign();

  // Bool Operators
  bool operator==(NumberSystems other);
  bool operator!=(NumberSystems other);
  bool operator>(NumberSystems other);
  bool operator<(NumberSystems other);
  bool operator>=(NumberSystems other);
  bool operator<=(NumberSystems other);

  // Math Operators
  NumberSystems operator+(NumberSystems other);
  NumberSystems operator-(NumberSystems other);
  NumberSystems operator*(NumberSystems other);
  NumberSystems operator/(NumberSystems other);
  NumberSystems operator%(NumberSystems other);
  NumberSystems operator-();
  NumberSystems abs();

  // NumberSystems Conversion
  void toBase(int base);

  // Other
  void push_front(char x);
  void push_back(char x);
  void push_front(std::string x);
  void push_back(std::string x);

  friend std::ostream &operator<<(std::ostream &os, const NumberSystems &ns) {
    os << ns.num;
    return os;
  }

  friend std::istream &operator>>(std::istream &is, NumberSystems &ns) {
    is >> ns.num;
    return is;
  }
};

// Constructors and Destructors

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

// System's methods
bool NumberSystems::isNeg() {
  return num[0] == '-';
}

bool NumberSystems::isPos() {
  return num[0] != '-';
}

void NumberSystems::setNeg() {
  if (isNeg())
    return;

  push_front('-');
}

void NumberSystems::setPos() {
  if (isPos())
    return;

  num.erase(num.begin());
}

void NumberSystems::setOtherSign() {
  if (num == "0") return;
  if (isPos()) {
    setNeg();
    return;
  }
  setPos();
}

NumberSystems NumberSystems::getNeg() {
  if (isNeg()) return *this;
  NumberSystems ans = *this;
  ans.setNeg();
  return ans;
}

NumberSystems NumberSystems::getPos() {
  if (isPos()) return *this;
  NumberSystems ans = *this;
  ans.setPos();
  return ans;
}

NumberSystems NumberSystems::getOtherSign() {
  NumberSystems ans = *this;
  ans.setOtherSign();
  
  return ans;
}

// Getters and Setters

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

// Bool operations

bool NumberSystems::operator==(NumberSystems other) {
  if (this->base != other.base)
    other.toBase(this->base);

  return num == other.num;
}

bool NumberSystems::operator!=(NumberSystems other) {
  if (this->base != other.base)
    other.toBase(this->base);

  return this->num != other.num;
}

bool NumberSystems::operator>(NumberSystems other) {
  if (this->base != other.base)
    other.toBase(this->base);

  if (this->num.size() > other.num.size())
    return true;
  if (this->num.size() < other.num.size())
    return false;
  return this->num > other.num;
}

bool NumberSystems::operator<(NumberSystems other) {
  if (this->base != other.base)
    other.toBase(this->base);

  if (this->num.size() < other.num.size())
    return true;
  if (this->num.size() > other.num.size())
    return false;
  return this->num < other.num;
}

bool NumberSystems::operator>=(NumberSystems other) {
  return this ->operator>(other) || this->operator==(other);
}

bool NumberSystems::operator<=(NumberSystems other) {
  return this ->operator<(other) || this->operator==(other);
}

// Math operations

NumberSystems NumberSystems::operator+(NumberSystems other) {
  if (this->base != other.base)
    other.toBase(this->base);
  if (isPos() && other.isNeg())
    return *this - other.abs();
  if (isNeg() && other.isPos())
    return other - abs();
  if (isNeg() && other.isNeg()) {
    return -(abs() + other.abs());
  }
  NumberSystems ans = {"", this->base};
  int carry = 0;
  for (int i = this->num.size() - 1, j = other.num.size() - 1; i >= 0 || j >= 0; i--, j--) {
    int a = 0, b = 0;
    if (i < 0) a = 0;
    else a = CharToInt(this->num[i]);
    if (j < 0) b = 0;
    else b = CharToInt(other.num[j]);
    char res = IntToChar((a + b + carry) % this->base);
    carry = (a + b + carry) / this->base;
    ans.push_front(res);
  }
  if (carry != 0)
    ans.push_front(IntToChar(carry));
  if (ans.num == "") return NumberSystems{0, ans.base};
  return ans;
}

NumberSystems NumberSystems::operator-(NumberSystems other) {
  if (this->base != other.base)
    other.toBase(this->base);
  if (isNeg() && other.isPos())
    return -(abs() + other);
  if (isPos() && other.isNeg())
    return *this + other.abs();
  if (isNeg() && other.isNeg())
    return other.abs() - abs();
  
  NumberSystems ans = {"", this->base};
  bool subtract = 0;
  for (int i = this->num.size() - 1, j = other.num.size() - 1; i >= 0 || j >= 0; i--, j--) {
    int a = 0, b = 0;
    if (i < 0) a = 0;
    else a = CharToInt(this->num[i]);
    a -= subtract;
    if (j < 0) b = 0;
    else b = CharToInt(other.num[j]);
    if (b > a) subtract = 1;
    else subtract = 0;
    std::string res = std::to_string((a - b + (i <= 0 ? 0 : this->base)) % this->base);
    if (res != "0") ans.push_front(res);
  }
  if (ans.num == "") return NumberSystems{0, ans.base};
  return ans;
}

NumberSystems NumberSystems::operator-() {
  return getOtherSign();
}

NumberSystems NumberSystems::abs() {
  if (isNeg()) return getOtherSign();
  return *this;
}

// Other

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

void NumberSystems::toBase(int base) {
  std::cout << "cot" << std::endl;
}

