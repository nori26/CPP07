#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iomanip>
#include <iostream>
#define BOLD_UNDELINE "\x1b[39;1;4m"
#define GREEN_BOLD_UNDERLINE "\x1b[32;44;1;4m"
#define RESET_COLOR "\x1b[39;49m"
using std::cout;
using std::endl;
using std::setw;

template <typename T>
void swap(T &a, T &b) {
  T tmp;
  tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
const T &max(const T &a, const T &b) {
  return a > b ? a : b;
}

template <typename T>
const T &min(const T &a, const T &b) {
  return a < b ? a : b;
}
namespace ft {

template <typename T>
void test(T a, T b) {
  T a_ = a;
  T b_ = b;
  std::string amax = "";
  std::string bmax = "";
  std::string amin = "";
  std::string bmin = "";

  if (&::max(a, b) == &a)
    amax = GREEN_BOLD_UNDERLINE;
  else
    bmax = GREEN_BOLD_UNDERLINE;
  if (&::min(a, b) == &a)
    amin = GREEN_BOLD_UNDERLINE;
  else
    bmin = GREEN_BOLD_UNDERLINE;
  ::swap(a, b);

  cout << BOLD_UNDELINE;
  cout << "                               \n";
  cout << "|      |     a     |     b    |\n";
  cout << "| arg  |" << setw(11) << a_ << "|" << setw(10) << b_ << "|\n";

  cout << "| max  |";
  cout << amax << setw(11) << a_ << RESET_COLOR << "|";
  cout << bmax << setw(10) << b_ << RESET_COLOR << "|" << endl;

  cout << "| min  |";
  cout << amin << setw(11) << a_ << RESET_COLOR << "|";
  cout << bmin << setw(10) << b_ << RESET_COLOR << "|" << endl;

  cout << "| swap |" << setw(11) << a << "|" << setw(10) << b << "|" << endl
       << endl;
}
}  // namespace ft

#endif
