#ifndef SRC_S21_SET_H_
#define SRC_S21_SET_H_

#include <iostream>

namespace s21 {
template <class Key>
class set {
 protected:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;

  class Node_ {
   public:
    Key key;
    Node_ *parent;
    Node_ *left;
    Node_ *right;
    explicit Node_(const value_type &value)
        : key(value), parent(nullptr), left(nullptr), right(nullptr) {}
    void clear_child();
  };

 public:
  class set_iterator {
   public:
    Node_ *pointer;
    Node_ *tail;
    set_iterator() : pointer(nullptr), tail(nullptr) {}
    explicit set_iterator(set<Key> &other)
        : pointer(other.head), tail(nullptr) {}
    set_iterator &operator++();
    set_iterator &operator--();
    reference operator*();
    bool operator==(const set_iterator pos);
    bool operator!=(set_iterator pos);
    ~set_iterator() {}
  };

  class set_const_iterator : public set_iterator {
   public:
    set_const_iterator() {}
    ~set_const_iterator() {}
  };

  using iterator = set_iterator;
  using const_iterator = set_const_iterator;
  //  --------------------------------------------constructors------------------------------------------
  set();
  explicit set(std::initializer_list<value_type> const &items);
  set(const set &other);
  set(set &&other);
  ~set();
  set &operator=(const set &other);
  set &operator=(set &&other);
  void clear();
  //  --------------------------------------------capacity------------------------------------------
  bool empty();
  size_type size() { return size_; }
  size_type max_size();

  //  --------------------------------------------methods------------------------------------------
  iterator begin();
  iterator end();
  iterator find(const Key &key);

  bool contains(const Key &key);
  void swap(set &other);
  void erase(iterator pos);
  void merge(set &other);
  //  --------------------------------------------inserts------------------------------------------
  std::pair<set<Key>::iterator, bool> insert(const value_type &value);
  template <class... Args>
  std::pair<set<Key>::iterator, bool> emplace(Args &&...args);

 protected:
  void clear_parent(iterator pos);
  void copy_set(Node_ *copy);

 protected:
  size_type size_;
  Node_ *head;
  iterator contains(Node_ *node, const Key &key);
};
}  // namespace s21
#include "s21_set.inl"
#endif  // SRC_S21_SET_H_
