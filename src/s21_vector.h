#ifndef SRC_S21_VECTOR_H_
#define SRC_S21_VECTOR_H_

#include <math.h>

namespace s21 {
template <class T>
class vector {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;
  using iterator = T*;
  using const_iterator = const T*;

  vector();
  explicit vector(size_type v_capacity);
  explicit vector(std::initializer_list<value_type> const& items);
  vector(const vector<T>& other);
  vector(vector&& other);
  vector<T>& operator=(vector&& other);
  ~vector();

  iterator begin() { return v_data; }
  iterator end() { return v_data + length; }
  iterator data() { return v_data; }
  iterator insert(iterator pos, const_reference value);
  iterator emplace(iterator it) { return it; }
  template <class Type, class... Args>
  iterator emplace(iterator pos, Type number, Args... args);

  const_reference front() { return v_data[0]; }
  const_reference back() { return v_data[length - 1]; }

  size_type size() { return length; }
  size_type max_size() {
    return 2 * static_cast<size_type>(
                   (pow(2.0, 64.0 - static_cast<T>(sizeof(value_type))))) -
           1;
  }
  size_type capacity() { return v_capacity; }

  reference operator[](size_type pos) { return v_data[pos]; }
  reference at(size_type pos);

  void reserve(size_type size);
  void shrink_to_fit();
  bool empty() { return length > 0 ? 0 : 1; }
  void clear() { length = 0; }
  void push_back(const_reference value);
  void pop_back();
  void erase(iterator pos);
  void swap(vector& other);
  void emplace_back() {}
  template <class Type, class... Args>
  void emplace_back(Type number, Args... args);

 private:
  size_type v_capacity;
  size_type length;
  T* v_data;
};

}  // namespace s21

#include "s21_vector.inl"
#endif  // SRC_S21_VECTOR_H_
