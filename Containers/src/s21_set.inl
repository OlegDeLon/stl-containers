

namespace s21 {
//--------------------------------------------constructors------------------------------------------
//Конструкторы set
template <class Key>
set<Key>::set() : size_(0), head(nullptr) {}

template <class Key>
set<Key>::set(set&& other) : set() {
  *this = std::move(other);
}

template <class Key>
set<Key>::set(std::initializer_list<value_type> const& items) : set() {
  for (value_type value : items) {
    insert(value);
  }
}

//Перегрузка оператора перемещения
template <class Key>
set<Key>& set<Key>::operator=(set&& other) {
  if (this != &other) {
    head = other.head;
    size_ = other.size_;
    other.head = nullptr;
    other.size_ = 0;
  }
  return *this;
}

template <class Key>
set<Key>::set(const set& other) : set() {
  *this = other;
}
//Перегрузка оператора копирования
template <class Key>
set<Key>& set<Key>::operator=(const set& other) {
  if (this == &other) {
    throw std::out_of_range("sets is equl");
  }
  clear();
  if (other.head != nullptr) {
    copy_set(other.head);
  }
  return *this;
}

template <class Key>
void set<Key>::copy_set(Node_* copy) {
  insert(copy->key);
  if (copy->right != nullptr) {
    copy_set(copy->right);
  }
  if (copy->left != nullptr) {
    copy_set(copy->left);
  }
}
template <class Key>
set<Key>::~set() {
  clear();
}
template <class Key>
void set<Key>::clear() {
  if (head != nullptr) {
    head->clear_child();
    delete head;
    head = nullptr;
    size_ = 0;
  }
}

template <class Key>
void set<Key>::Node_::clear_child() {
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
template <class Key>
bool set<Key>::empty() {
  return head == nullptr;
}

template <class Key>
size_t set<Key>::max_size() {
  return (SIZE_MAX / (sizeof(Node_))) / 2;
}

//--------------------------------------------insert------------------------------------------
template <class Key>
std::pair<typename set<Key>::iterator, bool> set<Key>::insert(
    const value_type& value) {
  if (max_size() == size()) {
    throw std::out_of_range("set is full");
  }

  std::pair<typename set<Key>::iterator, bool> pair;
  iterator new_it;
  bool res;
  Node_* current = new Node_(value);
  if (head == nullptr) {
    size_++;
    head = current;
  } else if (contains(value) == 0) {
    res = false;
    pair.first = find(value);
    pair.second = res;
    delete current;
  } else {
    new_it.pointer = head;
    bool check = true;
    while (check) {
      if (value < new_it.pointer->key) {
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

//--------------------------------------------emplace------------------------------------------
template <class Key>
template <class... Args>
std::pair<typename set<Key>::iterator, bool> set<Key>::emplace(Args&&... args) {
  std::pair<typename set<Key>::iterator, bool> pair;
  for (value_type value : {args...}) {
    if (head == nullptr) {
      pair = insert(value);
    }
    iterator it = find(value);
    if (it.pointer == nullptr) {
      pair = insert(value);
    } else {
      pair.first = it;
    }
  }
  return pair;
}
//--------------------------------------------begin------------------------------------------
template <class Key>
typename set<Key>::iterator set<Key>::begin() {
  if (empty() == 1) {
    throw std::out_of_range("set is empty");
  }
  iterator iter(*this);
  while (iter.pointer->left != nullptr) {
    iter.pointer = iter.pointer->left;
  }
  return iter;
}
//--------------------------------------------end------------------------------------------
template <class Key>
typename set<Key>::iterator set<Key>::end() {
  if (empty() == 1) {
    throw std::out_of_range("set is empty");
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
template <class Key>
typename set<Key>::set_iterator& set<Key>::set_iterator::operator++() {
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

//--------------------------------------------operators--------------------------------------------
template <class Key>
typename set<Key>::set_iterator& set<Key>::set_iterator::operator--() {
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

template <class Key>
typename set<Key>::reference set<Key>::set_iterator::operator*() {
  if (pointer == nullptr) {
    throw std::out_of_range("pointer is not exist (operator*)");
  }
  return pointer->key;
}

template <class Key>
bool set<Key>::set_iterator::operator==(const set_iterator other) {
  return pointer == other.pointer;
}

template <class Key>
bool set<Key>::set_iterator::operator!=(set_iterator other) {
  return pointer != other.pointer;
}

//--------------------------------------------erase------------------------------------------
template <class Key>
void set<Key>::erase(iterator pos) {
  if (empty() == 1) {
    throw std::out_of_range("set is empty - erase()");
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
        min.pointer->key = pos.pointer->key;
      }
      if (pos.pointer->left == nullptr && pos.pointer->right != nullptr) {
        iterator change1 = pos;
        if (pos.pointer->parent != nullptr) {
          pos.pointer->parent->right = change.pointer->right;
          pos.pointer->right->parent = change.pointer->parent;
        } else {
          pos.pointer = change.pointer->right;
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

template <class Key>
void set<Key>::clear_parent(iterator pos) {
  if (pos.pointer == pos.pointer->parent->right) {
    pos.pointer->parent->right = nullptr;
  } else if (pos.pointer == pos.pointer->parent->left) {
    pos.pointer->parent->left = nullptr;
  }
}

//--------------------------------------------find------------------------------------------
template <class Key>
typename set<Key>::iterator set<Key>::find(const Key& key) {
  if (head == nullptr) {
    throw std::out_of_range("there is no head in your set (find)");
  }
  return contains(head, key);
}
//--------------------------------------------contains------------------------------------------
template <class Key>
bool set<Key>::contains(const Key& key) {
  iterator it = contains(head, key);
  return it.pointer == nullptr;
}

template <class Key>
typename set<Key>::iterator set<Key>::contains(Node_* node, const Key& key) {
  iterator it;
  if (key < node->key && node->left != nullptr) it = contains(node->left, key);
  if (key == node->key) it.pointer = node;
  if (key > node->key && node->right != nullptr)
    it = contains(node->right, key);

  return it;
}
//--------------------------------------------swap------------------------------------------
template <class Key>
void set<Key>::swap(set& other) {
  if (this == &other) {
    throw std::out_of_range("sets is equal -swap()");
  }
  std::swap(head, other.head);
  std::swap(size_, other.size_);
}
//--------------------------------------------merge------------------------------------------
template <class Key>
void set<Key>::merge(set& other) {
  if (empty() == 0) {
    iterator iter_other = other.begin();
    std::pair<typename set<Key>::iterator, bool> pair;
    for (; iter_other != other.end(); ++iter_other) {
      iterator second = iter_other;
      pair = insert(second.pointer->key);
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
