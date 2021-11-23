#include "Fixed.hpp"
#include "whatever.hpp"

int main() {
  int a = 2;
  int b = 3;
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

  ft::test('a', 'b');
  ft::test(1, 1);
  ft::test(0.1, 0.01);
  ft::test(1, 10);
  ft::test(Fixed(1), Fixed(10));
  ft::test(Fixed((float)0.05), Fixed((float)0.04));
}
