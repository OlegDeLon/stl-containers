#ifndef SRC_S21_MULTISET_H_
#define SRC_S21_MULTISET_H_
#include "s21_set.h"

namespace s21 {
template <class Key>
class multiset : public set<Key> {
 public:
  using value_type = Key;
  using iterator = typename set<Key>::iterator;
  using Node_ = typename set<Key>::Node_;
  using size_type = size_t;

  multiset();
  explicit multiset(std::initializer_list<value_type> const& items);
  multiset(const multiset& other);
  multiset(multiset&& other);
  ~multiset();
  multiset& operator=(const multiset& other);
  multiset& operator=(multiset&& other);

  iterator insert(const value_type& value);

  template <class... Args>
  std::pair<multiset<Key>::iterator, bool> emplace(Args&&... args);

  void merge(multiset& other);  // NOLINT(*)

  std::pair<iterator, iterator> equal_range(const Key& key);
  iterator lower_bound(const Key& key);
  iterator upper_bound(const Key& key);
};
}  // namespace s21
#include "s21_multiset.inl"
#endif  // SRC_S21_MULTISET_H_
