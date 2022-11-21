namespace s21 {
// --------------------------------------------constructors-----------------------------------------
template <class Key>
multiset<Key>::multiset() {
    this->size_ = 0;
    this->head = nullptr;
}

template <class Key>
multiset<Key>::multiset(std::initializer_list<value_type> const& items) : multiset() {
    for (value_type value : items) {
        insert(value);
    }
}

template <class Key>
multiset<Key>::multiset(const multiset& other) : multiset() {
    *this = other;
}

template <class Key>
multiset<Key>::multiset(multiset&& other) : multiset() {
    // *this = std::move(other);
    *this = other;
    other.~multiset();
}
//Перегрузка оператора перемещения
template <class Key>
multiset<Key>& multiset<Key>::operator=(multiset&& other) {
    if (this != &other) {
        this->head = other.head;
        this->size_ = other.size_;
        other.head = nullptr;
        other.size_ = 0;
    }
    return *this;
}

template <class Key>
multiset<Key>::~multiset() {
    this->clear();
}

// --------------------------------------------multiinsert------------------------------------------
template <class Key>
typename multiset<Key>::iterator multiset<Key>::insert(const value_type& value) {
    if (this->max_size() == this->size()) {
        throw std::out_of_range("map is full");
    }
    // check for set;
    iterator new_it;
    Node_* current = new Node_(value);
    if (this->head == nullptr) {
        this->size_++;
        this->head = current;
    } else if (this->contains(value) == 0) {
        iterator second_it;
        new_it = this->find(value);
        if (new_it.pointer->right == nullptr) {
            new_it.pointer->right = current;
            new_it.pointer->right->parent = new_it.pointer;
        } else {
            second_it = new_it;
            second_it.pointer = second_it.pointer->right;

            new_it.pointer->right = current;
            new_it.pointer->right->parent = new_it.pointer;
            new_it.pointer = new_it.pointer->right;

            new_it.pointer->right = second_it.pointer;
            second_it.pointer->parent = new_it.pointer;
        }
        this->size_++;
    } else {
        new_it.pointer = this->head;
        bool check = true;
        while (check) {
            if (value < new_it.pointer->key) {
                if (new_it.pointer->left == nullptr) {
                    check = false;
                    new_it.pointer->left = current;
                    new_it.pointer->left->parent = new_it.pointer;
                } else {
                    new_it.pointer = new_it.pointer->left;
                }
            } else {
                if (new_it.pointer->right == nullptr) {
                    check = false;
                    new_it.pointer->right = current;
                    new_it.pointer->right->parent = new_it.pointer;
                } else {
                    new_it.pointer = new_it.pointer->right;
                }
            }
        }
        this->size_++;
    }
    return new_it;
}

// --------------------------------------------merge------------------------------------------
template <class Key>
void multiset<Key>::merge(multiset& other) {
    iterator iter_other = other.begin();
    for (; iter_other != other.end(); ++iter_other) {
        insert(iter_other.pointer->key);
    }
}

// --------------------------------------------emplace------------------------------------------
template <class Key>
template <class... Args>
std::pair<typename multiset<Key>::iterator, bool> multiset<Key>::emplace(Args&&... args) {
    std::pair<typename set<Key>::iterator, bool> pair;
    for (value_type value : {args...}) {
        pair.first = insert(value);
    }
    return pair;
}

//Перегрузка оператора копирования
template <class Key>
multiset<Key>& multiset<Key>::operator=(const multiset& other) {
    if (this == &other) {
        throw std::out_of_range("sets is equl");
    }
    this->clear();
    if (other.head != nullptr) {
        this->copy_set(other.head);
    }
    return *this;
}

template <class Key>
std::pair<typename multiset<Key>::iterator, typename multiset<Key>::iterator> multiset<Key>::equal_range(
    const Key& key) {
    return std::make_pair(lower_bound(key), upper_bound(key));
}

template <class Key>
typename multiset<Key>::iterator multiset<Key>::lower_bound(const Key& key) {
    if (this->empty() == 1) {
        throw std::out_of_range("multiset is empty");
    }
    iterator it_b = this->begin();
    iterator it_e = this->end();
    while (it_b != it_e) {
        if (it_b.pointer->key >= key) {
            break;
        }
        ++it_b;
    }
    return it_b;
}

template <class Key>
typename multiset<Key>::iterator multiset<Key>::upper_bound(const Key& key) {
    if (this->empty() == 1) {
        throw std::out_of_range("multiset is empty");
    }
    iterator it_b = this->begin();
    iterator it_e = this->end();
    while (it_b != it_e) {
        if (it_b.pointer->key > key) {
            break;
        }
        ++it_b;
    }
    return it_b;
}

}  // namespace s21
