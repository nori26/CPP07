#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
 private:
  int value_;
  static const int frac_precision_ = 8;
  static int multFrac(const int frac1, const int frac2);
  int fetchFrac() const;

 public:
  Fixed();
  ~Fixed();
  Fixed(const Fixed &obj);
  Fixed(const int &integer);
  Fixed(const float &real);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
  static Fixed &max(Fixed &a, Fixed &b);
  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  Fixed &operator=(const Fixed &src);
  bool operator>(const Fixed &rhs) const;
  bool operator<(const Fixed &rhs) const;
  bool operator>=(const Fixed &rhs) const;
  bool operator<=(const Fixed &rhs) const;
  bool operator==(const Fixed &rhs) const;
  bool operator!=(const Fixed &rhs) const;
  Fixed operator+(const Fixed &rhs) const;
  Fixed operator-(const Fixed &rhs) const;
  Fixed operator*(const Fixed &rhs) const;
  Fixed operator/(const Fixed &rhs) const;
  Fixed &operator++();
  Fixed &operator--();
  Fixed operator++(int);
  Fixed operator--(int);
};

#endif

std::ostream &operator<<(std::ostream &os, const Fixed &obj);
