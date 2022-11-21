#ifndef SRC_S21_ARRAY_H_
#define SRC_S21_ARRAY_H_
#include <iostream>
// #include <array>

namespace s21 {
template <class T, size_t N>
class array {
 private:
  T data[N]{};

 public:
  using value_type = T;
  using reference = T &;
  using size_type = size_t;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;

  array() {}
  explicit array(std::initializer_list<value_type> const &items);
  array(const array &other);
  array(array &&other);
  ~array() {}

  reference at(size_type pos);
  reference operator[](size_type pos);

  size_type size() const { return N; }
  size_type max_size() const { return N; }

  array &operator=(array &&other);

  void fill(const_reference value);
  void swap(array &other);

  bool empty() const { return N == 0 ? 1 : 0; }

  iterator i_data() { return data; }
  iterator begin() { return data; }
  iterator end() { return data + N; }

  const_iterator cbegin() const { return data; }
  const_iterator cend() const { return data + N; }

  const_reference front() const { return data[0]; }
  const_reference back() const { return data[N - 1]; }
};
}  // namespace s21

#include "s21_array.inl"
#endif  // SRC_S21_ARRAY_H_
