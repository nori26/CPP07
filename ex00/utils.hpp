#ifndef UTILS_HPP
#define UTILS_HPP
#include <iomanip>
#include <iostream>
#define BOLD_UNDELINE "\x1b[39;1;4m"
#define GREEN_BOLD_UNDERLINE "\x1b[32;44;1;4m"
#define RESET_COLOR "\x1b[39;49m"
using std::cout;
using std::endl;
using std::setw;
namespace ft {

template <typename T>
void swap(T &a, T &b) {
  T tmp;
  tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
T &max(T &a, T &b) {
  return a > b ? a : b;
}

template <typename T>
T &min(T &a, T &b) {
  return a < b ? a : b;
}

template <typename T>
void test(T a, T b) {
  T a_ = a;
  T b_ = b;
  std::string amax = "";
  std::string bmax = "";
  std::string amin = "";
  std::string bmin = "";

  if (&ft::max(a, b) == &a)
    amax = GREEN_BOLD_UNDERLINE;
  else
    bmax = GREEN_BOLD_UNDERLINE;
  if (&ft::min(a, b) == &a)
    amin = GREEN_BOLD_UNDERLINE;
  else
    bmin = GREEN_BOLD_UNDERLINE;
  ft::swap(a, b);

  cout << BOLD_UNDELINE << endl;
  cout << "                             \n";
  cout << "|      |     a     |     b    |\n";
  cout << "| arg  |" << setw(11) << a_ << "|" << setw(10) << b_ << "|\n";

  cout << "| max  |";
  cout << amax << setw(11) << a_ << RESET_COLOR << "|";
  cout << bmax << setw(10) << b_ << RESET_COLOR << "|" << endl;

  cout << "| min  |";
  cout << amin << setw(11) << a_ << RESET_COLOR << "|";
  cout << bmin << setw(10) << b_ << RESET_COLOR << "|" << endl;

  cout << "| swap |" << setw(11) << a << "|" << setw(10) << b << "|" << endl;
}
}  // namespace ft

#endif
