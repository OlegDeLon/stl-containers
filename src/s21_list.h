#ifndef SRC_S21_LIST_H_
#define SRC_S21_LIST_H_

#include <iostream>

namespace s21 {
template <typename T>
class list {
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

 private:
  size_t _size;
  Node* _head;
  Node* _end;

 public:
  class ListIterator {
   public:
    Node* _pointer;
    Node* _tail;
    ListIterator() : _pointer(nullptr), _tail(nullptr) {}
    explicit ListIterator(const list<T>& other);
    ListIterator& operator--();
    ListIterator& operator++();
    reference operator*();
    bool operator!=(const ListIterator& other);
    bool operator==(const ListIterator& other);
  };
  class ListConstIterator : public ListIterator {
   public:
    ListConstIterator() : ListIterator() {}
    explicit ListConstIterator(const list<T>& other) : ListIterator(other) {}
    ListConstIterator& operator=(const ListIterator& other);
  };
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;

  list();
  explicit list(size_t count);
  list(size_t count, const_reference value);
  explicit list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l);
  list<value_type>& operator=(const list<value_type>& l);
  list<value_type>& operator=(list&& l);
  ~list();

  bool empty();
  void push_front(const_reference value);
  void push_back(const_reference value);
  void pop_front();
  void pop_back();
  void clear();
  size_type size() { return _size; }
  size_type max_size();
  const_reference front();
  const_reference back();

  iterator begin();
  iterator end();
  const_iterator cbegin();
  const_iterator cend();
  void erase(iterator pos);
  iterator insert(iterator pos, const_reference value);
  void splice(const_iterator pos, list& other);  // NOLINT(*)
  void unique();
  void reverse();
  void swap(list& other);
  void sort();
  void merge(list& other);

  template <typename... Args>
  iterator emplace(const_iterator pos, Args&&... args);
  template <typename... Args>
  void emplace_back(Args&&... args);
  template <typename... Args>
  void emplace_front(Args&&... args);
};
}  // namespace s21
#include "s21_list.inl"

#endif  // SRC_S21_LIST_H_
