#include "Fixed.hpp"

#include <limits.h>

#include <cmath>
#include <iostream>

#define RED_BOLD "\x1b[31;1m"
#define RESET_COLOR "\x1b[39;0m"
#define OVEERFLOW RED_BOLD "overflow detected "

std::ostream &operator<<(std::ostream &os, const Fixed &obj) {
  os << obj.toFloat();
  return os;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return a > b ? a : b; }

Fixed &Fixed::min(Fixed &a, Fixed &b) { return a < b ? a : b; }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return a < b ? a : b;
}

Fixed::Fixed() : value_() {}

Fixed::Fixed(const int &integer) {
  int overflow = 0x7fffff;

  if (integer > overflow || integer < -overflow - 1) {
    std::cout << OVEERFLOW << "in constructor" RESET_COLOR << std::endl;
  }
  value_ = integer << frac_precision_;
}

Fixed::Fixed(const float &real) {
  double d = real;

  d *= 1 << frac_precision_;
  if (d > INT_MAX || d < INT_MIN) {
    std::cout << OVEERFLOW << "in constructor" RESET_COLOR << std::endl;
  }
  value_ = (int)roundf(d);
}

Fixed::Fixed(const Fixed &obj) { *this = obj; }

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return value_; }

void Fixed::setRawBits(int const raw) { value_ = raw; }

float Fixed::toFloat(void) const {
  return (float)value_ / (1 << frac_precision_);
};

int Fixed::toInt(void) const { return value_ / (1 << frac_precision_); };

Fixed &Fixed::operator=(const Fixed &src) {
  value_ = src.value_;
  return *this;
}

bool Fixed::operator>(const Fixed &rhs) const {
  return this->value_ > rhs.value_;
}

bool Fixed::operator<(const Fixed &rhs) const { return rhs > *this; }

bool Fixed::operator>=(const Fixed &rhs) const { return !(*this < rhs); }

bool Fixed::operator<=(const Fixed &rhs) const { return !(*this > rhs); }

bool Fixed::operator==(const Fixed &rhs) const { return !(*this != rhs); }

bool Fixed::operator!=(const Fixed &rhs) const {
  return *this < rhs || *this > rhs;
}

Fixed Fixed::operator+(const Fixed &rhs) const {
  return (float)(value_ + rhs.value_) / (1 << frac_precision_);
}

Fixed Fixed::operator-(const Fixed &rhs) const {
  return (float)(value_ - rhs.value_) / (1 << frac_precision_);
}

int Fixed::fetchFrac() const {
  int sign = value_ < 0;
  int res = value_ & 0xff;
  return sign && res ? res | 0xffffff00 : res;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
  Fixed tmp;
  int lhs_int = toInt();
  int rhs_int = rhs.toInt();
  int lhs_frac = fetchFrac();
  int rhs_frac = rhs.fetchFrac();

  int lintrint = lhs_int * rhs_int;
  int intint = lintrint << frac_precision_;
  if (lhs_int && (lintrint / lhs_int != rhs_int ||
                  intint / (1 << frac_precision_) != lintrint)) {
    std::cout << OVEERFLOW << "in operator *" RESET_COLOR << std::endl;
  }
  int intfrac = lhs_int * rhs_frac;
  int fracint = rhs_int * lhs_frac;
  int fracfrac = (lhs_frac * rhs_frac) / (1 << frac_precision_);

  int res = intint + intfrac + fracint + fracfrac;
  tmp.setRawBits(res);
  return tmp;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
  if (rhs.value_ == 0) {
    std::cout << RED_BOLD "zero divide detected" RESET_COLOR << std::endl;
    return 0;
  }
  Fixed tmp;
  int frac_divider = rhs.fetchFrac();
  int divider = rhs.value_ / (1 << frac_precision_);
  int fraction = fetchFrac();
  int integer = value_ - fraction;
  int res;

  if (divider) {
    res = value_ / divider;
  } else {
    int remainder = integer % frac_divider;
    res = (integer / frac_divider) << frac_precision_;
    res += ((fraction + remainder) << frac_precision_) / frac_divider;
  }
  tmp.setRawBits(res);
  return tmp;
}

Fixed &Fixed::operator++() {
  if (value_ == INT_MAX) {
    std::cout << OVEERFLOW << "in preinc" RESET_COLOR << std::endl;
  }
  value_++;
  return *this;
}

Fixed &Fixed::operator--() {
  if (value_ == INT_MIN) {
    std::cout << OVEERFLOW << "in predec" RESET_COLOR << std::endl;
  }
  value_--;
  return *this;
}

Fixed Fixed::operator++(int) {
  if (value_ == INT_MAX) {
    std::cout << OVEERFLOW << "in postinc" RESET_COLOR << std::endl;
  }
  Fixed tmp;

  tmp.setRawBits(value_++);
  return tmp;
}

Fixed Fixed::operator--(int) {
  if (value_ == INT_MIN) {
    std::cout << OVEERFLOW << "in postdec" RESET_COLOR << std::endl;
  }
  Fixed tmp;

  tmp.setRawBits(value_--);
  return tmp;
}
