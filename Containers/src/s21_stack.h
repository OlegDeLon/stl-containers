#ifndef SRC_S21_STACK_H_
#define SRC_S21_STACK_H_

namespace s21 {
template <class T>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  stack();
  explicit stack(std::initializer_list<T> const &items);
  explicit stack(const stack &s);
  stack(stack &&s);
  ~stack();
  stack &operator=(stack &&s);
  reference operator[](size_type pos) { return data[pos]; }

  const_reference top();

  bool empty() { return size() > 0 ? 0 : 1; }
  size_type size();

  void push(const_reference value);
  void pop();
  void swap(stack &other);
  template <class... Args>
  void emplace_front(Args &&...args);

 private:
  T *data;
  size_t s_capacity;
  size_t s_size;
  T *last = nullptr;
};
}  // namespace s21
#include "s21_stack.inl"
#endif  // SRC_S21_STACK_H_
