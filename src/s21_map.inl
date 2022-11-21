namespace s21 {
//--------------------------------------------constructors------------------------------------------
//Конструкторы map
template <class Key, class Value>
map<Key, Value>::map() : size_(0), head(nullptr) {}

template <class Key, class Value>
map<Key, Value>::map(map&& other) : map() {
  *this = std::move(other);
}

template <class Key, class Value>
map<Key, Value>::map(std::initializer_list<value_type> const& items) : map() {
  for (value_type pair : items) {
    insert(pair);
  }
}

//Перегрузка оператора перемещения
template <class Key, class Value>
map<Key, Value>& map<Key, Value>::operator=(map&& other) {
  if (this != &other) {
    head = other.head;
    size_ = other.size_;
    other.head = nullptr;
    other.size_ = 0;
  }
  return *this;
}

template <class Key, class Value>
map<Key, Value>::map(const map& other) : map() {
  *this = other;
}
//Перегрузка оператора копирования
template <class Key, class Value>
map<Key, Value>& map<Key, Value>::operator=(const map& other) {
  if (this == &other) {
    throw std::out_of_range("Maps is equl");
  }
  clear();
  if (other.head != nullptr) {
    copy_map(other.head);
  }
  return *this;
}

template <class Key, class Value>
void map<Key, Value>::copy_map(Node_* copy) {
  insert(copy->data);
  if (copy->right != nullptr) {
    copy_map(copy->right);
  }
  if (copy->left != nullptr) {
    copy_map(copy->left);
  }
}
template <class Key, class Value>
map<Key, Value>::~map() {
  clear();
}
template <class Key, class Value>
void map<Key, Value>::clear() {
  if (head != nullptr) {
    head->clear_child();
    delete head;
    head = nullptr;
    size_ = 0;
  }
}

template <class Key, class Value>
void map<Key, Value>::Node_::clear_child() {
  if (left != nullptr) {
    left->clear_child();
  }
  if (right != nullptr) {
    right->clear_child();
  }
  delete left;
  delete right;
}
//--------------------------------------------capacity------------------------------------------
template <class Key, class Value>
bool map<Key, Value>::empty() {
  return head == nullptr;
}

template <class Key, class Value>
size_t map<Key, Value>::max_size() {
  return (SIZE_MAX / (sizeof(Node_))) / 2;
}

//--------------------------------------------operator[]------------------------------------------
template <class Key, class Value>
Value& map<Key, Value>::operator[](const Key& key) {
  iterator it;
  std::pair<Key, mapped_type> pair;
  pair.first = key;
  if (head == nullptr) {
    insert(pair);
    it = find(key);
  } else {
    it = find(key);
    if (it.pointer != nullptr) {
      return it.pointer->data.second;
    } else {
      insert(pair);
      it = find(key);
    }
  }
  return it.pointer->data.second;
}

//--------------------------------------------insert------------------------------------------
template <class Key, class Value>
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert(
    const value_type& value) {
  if (max_size() == size()) {
    throw std::out_of_range("map is full");
  }
  std::pair<typename map<Key, Value>::iterator, bool> pair;
  iterator new_it;
  bool res;
  Node_* current = new Node_(value);
  if (head == nullptr) {
    size_++;
    head = current;
  } else if (contains(value.first) == 0) {
    res = false;
    pair.first = find(value.first);
    pair.second = res;
    delete current;
  } else {
    new_it.pointer = head;
    bool check = true;
    while (check) {
      if (value.first < new_it.pointer->data.first) {
        if (new_it.pointer->left == nullptr) {
          check = false;
          new_it.pointer->left = current;
          new_it.pointer->left->parent = new_it.pointer;
          pair.first.pointer = new_it.pointer->left;
        } else {
          new_it.pointer = new_it.pointer->left;
        }
      } else {
        if (new_it.pointer->right == nullptr) {
          check = false;
          new_it.pointer->right = current;
          new_it.pointer->right->parent = new_it.pointer;
          pair.first.pointer = new_it.pointer->right;
        } else {
          new_it.pointer = new_it.pointer->right;
        }
      }
    }
    res = true;
    pair.second = res;
    size_++;
  }
  return pair;
}

//--------------------------------------------insert2------------------------------------------
template <class Key, class Value>
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::insert(
    const Key& key, const Value& obj) {
  std::pair<Key, Value> pair;
  std::pair<typename map<Key, Value>::iterator, bool> pair_2;
  pair.first = key;
  pair.second = obj;
  pair_2 = insert(pair);
  return pair_2;
}
//--------------------------------------------insert_or_assign------------------------------------------
template <class Key, class Value>  // просто структура
std::pair<typename map<Key, Value>::iterator, bool>
map<Key, Value>::insert_or_assign(const Key& key, const Value& obj) {
  iterator it = find(key);
  std::pair<typename map<Key, Value>::iterator, bool> pair;
  if (it.pointer == nullptr) {
    pair = insert(key, obj);
  } else {
    pair.first = it;
  }
  return pair;
}
//--------------------------------------------emplace------------------------------------------
template <class Key, class Value>  // просто структура
template <class... Args>
std::pair<typename map<Key, Value>::iterator, bool> map<Key, Value>::emplace(
    Args&&... args) {
  std::pair<typename map<Key, Value>::iterator, bool> pair;
  for (value_type value : {args...}) {
    if (head == nullptr) {
      pair = insert(value);
    }
    iterator it = find(value.first);
    if (it.pointer == nullptr) {
      pair = insert(value);
    } else {
      pair.first = it;
    }
  }
  return pair;
}
//--------------------------------------------begin------------------------------------------
template <class Key, class Value>
typename map<Key, Value>::iterator map<Key, Value>::begin() {
  if (empty() == 1) {
    throw std::out_of_range("map is empty");
  }
  iterator iter(*this);
  while (iter.pointer->left != nullptr) {
    iter.pointer = iter.pointer->left;
  }
  return iter;
}
//--------------------------------------------end------------------------------------------
template <class Key, class Value>
typename map<Key, Value>::iterator map<Key, Value>::end() {
  if (empty() == 1) {
    throw std::out_of_range("map is empty");
  }
  iterator iter(*this);
  if (head != nullptr) {
    while (iter.pointer->right != nullptr) {
      iter.pointer = iter.pointer->right;
    }
    iter.tail = iter.pointer;
    iter.pointer = iter.pointer->right;
  } else {
    iter.pointer = nullptr;
  }
  return iter;
}
//--------------------------------------------operator++------------------------------------------
template <class Key, class Value>
typename map<Key, Value>::map_iterator&
map<Key, Value>::map_iterator::operator++() {
  tail = pointer;
  if (pointer->right != nullptr) {
    pointer = pointer->right;
    while (pointer->left != nullptr) {
      pointer = pointer->left;
    }
  } else if (pointer->right == nullptr && pointer->parent != nullptr) {
    if (pointer == pointer->parent->left) {
      pointer = pointer->parent;
    } else {
      while (pointer->parent != nullptr && pointer == pointer->parent->right) {
        pointer = pointer->parent;
      }
      if (pointer->parent != nullptr) {
        pointer = pointer->parent;
      } else {
        pointer = nullptr;
      }
    }
  } else {
    pointer = nullptr;
  }
  if (pointer != nullptr) {
    tail = nullptr;
  }
  return *this;
}

//--------------------------------------------operator--
//------------------------------------------
template <class Key, class Value>
typename map<Key, Value>::map_iterator&
map<Key, Value>::map_iterator::operator--() {
  if (pointer == nullptr && tail == nullptr) {
    throw std::out_of_range("index is out of range (oper--)");
  }
  if (pointer == nullptr && tail != nullptr) {
    pointer = tail;
  } else {
    if (pointer->left != nullptr) {
      pointer = pointer->left;
      while (pointer->right != nullptr) {
        pointer = pointer->right;
      }
    } else if (pointer->left == nullptr && pointer->parent != nullptr) {
      if (pointer == pointer->parent->right) {
        pointer = pointer->parent;
      } else {
        while (pointer->parent != nullptr && pointer == pointer->parent->left) {
          pointer = pointer->parent;
        }
        if (pointer->parent != nullptr) {
          pointer = pointer->parent;
        }
      }
    }
    tail = nullptr;
  }
  return *this;
}

template <class Key, class Value>
typename map<Key, Value>::reference map<Key, Value>::map_iterator::operator*() {
  if (pointer == nullptr) {
    throw std::out_of_range("pointer is not exist (operator*)");
  }
  return pointer->data;
}

template <class Key, class Value>
bool map<Key, Value>::map_iterator::operator==(const map_iterator other) {
  return pointer == other.pointer;
}

template <class Key, class Value>
bool map<Key, Value>::map_iterator::operator!=(map_iterator other) {
  return pointer != other.pointer;
}
//--------------------------------------------method_at------------------------------------------
template <class Key, class Value>
Value& map<Key, Value>::at(const Key& key) {
  if (head == nullptr) {
    throw std::out_of_range("your map is empty (at)");
  }
  if (contains(key) == 1) {
    throw std::out_of_range("this element is not exist (at)");
  }

  iterator it = find(key);

  return it.pointer->data.second;
}
//--------------------------------------------erase------------------------------------------
template <class Key, class Value>
void map<Key, Value>::erase(iterator pos) {
  if (empty() == 1) {
    throw std::out_of_range("map is empty - erase()");
  }
  if (size_ > 1) {
    iterator change = pos;
    if (pos.pointer->parent == nullptr && pos.pointer->right == nullptr) {
      pos.pointer = pos.pointer->left;
      delete change.pointer;
      change.pointer = nullptr;
      head = pos.pointer;
    } else if (pos.pointer->left != nullptr && pos.pointer->right == nullptr) {
      if (pos.pointer == pos.pointer->parent->right) {
        pos.pointer->parent->right = change.pointer->left;
      } else if (pos.pointer == pos.pointer->parent->left) {
        pos.pointer->parent->left = change.pointer->left;
      }
      pos.pointer->left->parent = change.pointer->parent;
      delete change.pointer;
      change.pointer = nullptr;
    } else {
      if (pos.pointer->left != nullptr && pos.pointer->right != nullptr) {
        iterator min = pos;
        ++pos;
        min.pointer->data = pos.pointer->data;
      }
      if (pos.pointer->left == nullptr && pos.pointer->right != nullptr) {
        iterator change1 = pos;
        if (pos.pointer->parent != nullptr) {
          pos.pointer->parent->right = change1.pointer->right;
          pos.pointer->right->parent = change1.pointer->parent;
        } else {
          pos.pointer = change1.pointer->right;
          head = pos.pointer;
        }
        delete change1.pointer;
        change1.pointer = nullptr;
      } else if (pos.pointer->left == nullptr &&
                 pos.pointer->right == nullptr) {
        iterator change2 = pos;
        clear_parent(change2);
        delete change2.pointer;
        change2.pointer = nullptr;
      }
    }
    --size_;
  } else {
    clear();
  }
}

template <class Key, class Value>
void map<Key, Value>::clear_parent(iterator pos) {
  if (pos.pointer == pos.pointer->parent->right) {
    pos.pointer->parent->right = nullptr;
  } else if (pos.pointer == pos.pointer->parent->left) {
    pos.pointer->parent->left = nullptr;
  }
}

template <class Key, class Value>
typename map<Key, Value>::iterator map<Key, Value>::min_value(iterator pos) {
  iterator answer = pos;
  if (pos.pointer->left != nullptr) {
    answer = min_value(pos.pointer->left);
  }
  return answer;
}
//--------------------------------------------find------------------------------------------
template <class Key, class Value>
typename map<Key, Value>::iterator map<Key, Value>::find(const Key& key) {
  if (head == nullptr) {
    throw std::out_of_range("there is no head in your map (find)");
  }
  return contains(head, key);
}
//--------------------------------------------contains------------------------------------------
template <class Key, class Value>
bool map<Key, Value>::contains(const Key& key) {
  iterator it = contains(head, key);
  return it.pointer == nullptr;
}

template <class Key, class Value>
typename map<Key, Value>::iterator map<Key, Value>::contains(Node_* node,
                                                             const Key& key) {
  iterator it;
  // it.pointer = nullptr;
  if (key < node->data.first && node->left != nullptr)
    it = contains(node->left, key);
  if (key == node->data.first) it.pointer = node;
  if (key > node->data.first && node->right != nullptr)
    it = contains(node->right, key);
  return it;
}
//--------------------------------------------swap------------------------------------------
template <class Key, class Value>
void map<Key, Value>::swap(map& other) {
  if (this == &other) {
    throw std::out_of_range("maps is equal -swap()");
  }
  std::swap(head, other.head);
  std::swap(size_, other.size_);
}
//--------------------------------------------merge------------------------------------------
template <class Key, class Value>
void map<Key, Value>::merge(map& other) {
  if (empty() == 0) {
    iterator iter_other = other.begin();
    iterator other_end = other.end();
    std::pair<typename map<Key, Value>::iterator, bool> pair;
    for (; iter_other.pointer != other_end.pointer; ++iter_other) {
      iterator second = iter_other;
      pair = insert(second.pointer->data);
      if (pair.second == 1) {
        if (second.pointer == other.head) {
          other.erase(second);
          --iter_other;
        } else {
          other.erase(second);
        }
      }
    }
  } else {
    swap(other);
  }
}

}  // namespace s21
