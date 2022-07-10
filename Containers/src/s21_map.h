#ifndef SRC_S21_MAP_H_
#define SRC_S21_MAP_H_

#include <iostream>

namespace s21 {
template <class Key, class Value>
class map {
 private:
  using key_type = Key;
  using mapped_type = Value;
  using value_type = std::pair<key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;

  class Node_ {
   public:
    Node_ *parent;
    Node_ *left;
    Node_ *right;
    std::pair<Key, Value> data;
    explicit Node_(const value_type &value)
        : parent(nullptr), left(nullptr), right(nullptr), data(value) {}
    void clear_child();
  };

 public:
  class map_iterator {
   public:
    Node_ *pointer;
    Node_ *tail;
    map_iterator() : pointer(nullptr), tail(nullptr) {}
    explicit map_iterator(const map<Key, Value> &other)
        : pointer(other.head), tail(nullptr) {}
    map_iterator &operator++();
    map_iterator &operator--();
    reference operator*();
    bool operator==(const map_iterator pos);
    bool operator!=(map_iterator pos);
    ~map_iterator() {}
  };

  class map_const_iterator : public map_iterator {
   public:
    map_const_iterator() {}
    ~map_const_iterator() {}
  };

  using iterator = map_iterator;
  using const_iterator = map_const_iterator;
  // --------------------------------------------constructors------------------------------------------
  map();
  explicit map(std::initializer_list<value_type> const &items);
  map(const map &other);
  map(map &&other);
  ~map();
  map &operator=(const map &other);
  map &operator=(map &&other);
  void clear();
  // --------------------------------------------capacity------------------------------------------
  bool empty();
  size_type size() { return size_; }
  size_type max_size();

  // --------------------------------------------methods------------------------------------------
  Value &operator[](const Key &key);
  Value &at(const Key &key);

  iterator begin();
  iterator end();
  iterator find(const Key &key);

  bool contains(const Key &key);
  void swap(map &other);
  void erase(iterator pos);
  void merge(map &other);
  // --------------------------------------------inserts------------------------------------------
  std::pair<map<Key, Value>::iterator, bool> insert(const value_type &value);
  std::pair<map<Key, Value>::iterator, bool> insert(const Key &key,
                                                    const Value &obj);
  std::pair<map<Key, Value>::iterator, bool> insert_or_assign(const Key &key,
                                                              const Value &obj);
  template <class... Args>
  std::pair<map<Key, Value>::iterator, bool> emplace(Args &&...args);

 private:
  void clear_parent(iterator pos);
  void copy_map(Node_ *copy);

 private:
  size_type size_;
  Node_ *head;
  iterator min_value(iterator pos);
  iterator contains(Node_ *node, const Key &key);
};
}  // namespace s21
#include "s21_map.inl"
#endif  // SRC_S21_MAP_H_
