#include <iostream>

#include "iter.hpp"
#define N 10

void inc1(int &i) { i++; }
template <typename T>
void print(T ary, size_t length) {
  for (size_t i = 0; i < length; i++) {
    std::cout << ary[i] << ", ";
  }
  std::cout << std::endl;
}
template <typename T>
void inc(T &i) {
  i++;
}

template <typename T>
void add(T &i) {
  i += 'a';
}
template <typename T>
void nop(const T &i) {
  (void)i;
}
template <typename T>
void nop2(T &i) {
  (void)i;
}

template <typename T>
void test(const char *s, T *arg, void (*func)(T &)) {
  std::cout << s;
  ::iter(arg, N, func);
  print(arg, N);
}

template <typename T>
void test(const char *s, const T *arg, void (*func)(const T &)) {
  std::cout << s;
  ::iter(arg, N, func);
  print(arg, N);
}

void tasu(char &c) { c++; }

int main() {
  int ary[N];
  const int ary2[N] = {1, 2, 3, 4, 5, 6, 7};
  std::string sp[N];

  for (int i = 0; i < N; i++) {
    ary[i] = i;
    sp[i] = "abc";
    sp[i] += 'a' + i;
  }

  test("normal normal\n", ary, inc1);
  test("", ary, inc);
  test("", ary, add);
  test("", sp, add);
  test("\nnormal const\n", sp, nop);
  test("\nconst  const\n", ary2, nop);
  test("\nconst  normal\n", ary2, nop2);
  test("\nliteral  const\n", "0123456789", nop);
}
