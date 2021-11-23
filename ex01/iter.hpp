#ifndef ITER_HPP
#define ITER_HPP
#include <cstddef>
#include <iostream>

template <typename T>
void iter(T *ary, size_t length, void (*func)(T &)) {
  for (size_t i = 0; i < length; i++) {
    func(ary[i]);
  }
}

template <typename T>
void iter(const T *ary, size_t length, void (*func)(const T &)) {
  for (size_t i = 0; i < length; i++) {
    func(ary[i]);
  }
}

#endif
