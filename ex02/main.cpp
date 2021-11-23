#include <stdlib.h>

#include <Array.hpp>
#include <iomanip>
#include <iostream>

#include "Fixed.hpp"
#define GREEN_BOLD "\x1b[32;1m"
#define RESET_COLOR "\x1b[39;0m"
#define MAX_VAL 750
void example() {
  Array<int> numbers(MAX_VAL);
  int* mirror = new int[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }
  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return;
    }
  }
  try {
    numbers[-2] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }
  delete[] mirror;  //
  return;
}

template <typename U, typename T>
void setval(Array<T>& ary, unsigned int size) {
  for (unsigned int i = 0; i < size; i++) {
    ary[i] = T((U)('a' + i));
  }
}

template <typename T>
void print(Array<T>& ary, unsigned int size) {
  for (unsigned int i = 0; i < size; i++) {
    std::cout << ary[i] << ", ";
  }
  std::cout << std::endl;
}

template <typename T>
void sizetest(const unsigned int size) {
  std::cout << "\n======= size test =======\n" << std::endl;

  Array<T> f1;
  Array<T> f2(size);

  std::cout << "default size : " << f1.size() << std::endl;
  std::cout << std::left << std::setw(10) << "param " << f2.size() << " : "
            << f2.size() << std::endl;
}

template <typename T, typename U>
void copytest(const unsigned int size) {
  std::cout << "\n======= copy test =======\n" << std::endl;

  Array<T> src(size);
  setval<U>(src, size);
  Array<T> dest(src);

  std::cout << std::left << std::setw(13) << "src"
            << ": ";
  print(src, size);
  src = dest;
  std::cout << std::left << std::setw(13) << "dest"
            << ": ";
  print(dest, size);
}

template <typename T, typename U>
void eqtest(const unsigned int size) {
  std::cout << "\n======== eq test ========\n" << std::endl;

  Array<T> f1;
  Array<T> f2(size);

  setval<U>(f2, size);
  std::cout << std::left << std::setw(13) << "value"
            << ": ";
  print(f2, size);
  f1 = f2;
  std::cout << std::left << std::setw(13) << "assign"
            << ": ";
  print(f1, size);
}
template <typename T>
void excepttest(const unsigned int size,
                void (*func)(Array<T>&, const unsigned int)) {
  std::cout << "\n====== except test ======\n" << std::endl;
  try {
    Array<T> f1(size);
    func(f1, size + 1);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}

template <typename T, typename U>
void test(const unsigned int size) {
  std::cout << GREEN_BOLD "\n==========TEST===========" RESET_COLOR
            << std::endl;
  sizetest<T>(size);
  copytest<T, U>(size);
  eqtest<T, U>(size);
  excepttest<T>(size, print);
}

int main(int, char**) {
  example();
  test<Fixed, int>(10);
  test<Fixed, float>(10);
  test<int, int>(10);
  test<char, char>(10);
}
