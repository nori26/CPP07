#include "Fixed.hpp"
#include "utils.hpp"

int main() {
  ft::test('a', 'b');
  ft::test(1, 1);
  ft::test(0.1, 0.01);
  ft::test(1, 10);
  ft::test(Fixed(1), Fixed(10));
  ft::test(Fixed((float)0.05), Fixed((float)0.04));
}
