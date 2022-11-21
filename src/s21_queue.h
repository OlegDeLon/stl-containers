#ifndef SRC_S21_QUEUE_H_
#define SRC_S21_QUEUE_H_

#include <iostream>

namespace s21 {
template <typename T>
class queue {
 private:
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = std::size_t;

  class Node {
   public:
    value_type _data;
    Node* _next;
    Node* _prev;
    explicit Node(const_reference value)
        : _data(value), _next(nullptr), _prev(nullptr) {}
  };

  size_t _size;
  Node* _head;
  Node* _end;

 public:
  queue();
  explicit queue(std::initializer_list<value_type> const& items);
  explicit queue(const queue& q);
  queue(queue&& q);
  ~queue();

  queue<value_type>& operator=(const queue<T>& q);
  queue<value_type>& operator=(queue&& q);
  void clear();

  const_reference front();
  const_reference back();

  bool empty();
  size_type size();

  void push(const_reference value);
  void pop();
  void swap(queue& other);
  template <typename... Args>
  void emplace_back(Args&&... args);
};
}  // namespace s21
#include "s21_queue.inl"
#endif  // SRC_S21_QUEUE_H_
