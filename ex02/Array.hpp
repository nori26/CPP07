#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <stdexcept>
template <typename T>
class Array {
 private:
  T *ary_;
  unsigned int size_;

  T *copy(Array const &other) {
    T *ary = new T[size_]();
    for (unsigned int i = 0; i < size_; i++) {
      ary[i] = other.ary_[i];
    }
    return ary;
  }

 public:
  Array(unsigned int n = 0) : ary_(new T[n]()), size_(n) {}

  ~Array() { delete[] ary_; }

  Array(Array const &other) : size_(other.size_) { ary_ = copy(other); }

  Array &operator=(Array const &other) {
    if (this == &other) {
      return *this;
    }
    size_ = other.size_;
    delete[] ary_;
    ary_ = copy(other);
    return *this;
  }

  T &operator[](unsigned int index) {
    if (index >= size_) {
      throw std::range_error("index out of range");
    }
    return ary_[index];
  };

  unsigned int size() { return size_; };
};
#endif
