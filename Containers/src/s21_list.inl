
/* ---------------------LIST CONSTRUCTOR--------------------- */
template <typename T>
s21::list<T>::list() : _size(0), _head(nullptr), _end(nullptr) {}

template <typename T>
s21::list<T>::list(size_type count) : list() {
  if (count >= max_size()) {
    throw std::invalid_argument("failed to create a list, count >= max_size");
  }
  for (size_t i = 1; i <= count; i++) {
    push_front(value_type());
  }
}
template <typename T>
s21::list<T>::list(size_type count, const_reference value) : list() {
  if (count >= max_size()) {
    throw std::invalid_argument("failed to create a list, count >= max_size");
  }
  for (size_t i = 1; i <= count; i++) {
    push_front(value);
  }
}
template <typename T>
s21::list<T>::list(std::initializer_list<value_type> const &items) : list() {
  if (items.size() >= max_size()) {
    throw std::invalid_argument(
        "failed to create a list, items.size() >= max_size");
  }
  for (const_reference val : items) {
    push_back(val);
  }
}

template <typename T>
s21::list<T>::list(const list &l) : list() {
  *this = l;
}
template <typename T>
s21::list<T> &s21::list<T>::operator=(const list<T> &l) {
  if (this == &l) {
    throw std::out_of_range("lists is equal");
  }
  clear();
  Node *copy = l._head;
  for (size_t i = 1; i <= l._size; i++) {
    push_back(copy->_data);
    copy = copy->_next;
  }
  return *this;
}

template <typename T>
s21::list<T>::list(list &&l) : list() {
  *this = std::move(l);
}

template <typename T>
s21::list<T> &s21::list<T>::operator=(list &&l) {
  clear();
  swap(l);
  return *this;
}

template <typename T>
s21::list<T>::~list() {
  clear();
}

template <typename T>
void s21::list<T>::clear() {
  Node *ptr = nullptr;
  while (empty() == 0) {
    ptr = _head;
    _head = _head->_next;
    delete ptr;
  }
  _head = nullptr;
  _end = nullptr;
  _size = 0;
}
/* --------------LIST CAPACITY-------------- */
// 0-нет, 1-пустой
template <typename T>
bool s21::list<T>::empty() {
  return _head == nullptr;
}
template <typename T>
size_t s21::list<T>::max_size() {
  return (SIZE_MAX / (sizeof(Node)) / 2);
}
/* ---------------------LIST FUNCTIONS--------------------- */
template <typename T>
void s21::list<T>::push_front(const_reference value) {
  if (_size == max_size()) {
    throw std::invalid_argument("failed to add Node, _size == max_size");
  }
  Node *n_node = new Node(value);
  if (empty() == 1) {
    _head = n_node;
    _end = n_node;
  } else {
    _head->_prev = n_node;
    n_node->_next = _head;
    _head = n_node;
  }
  ++_size;
}
template <typename T>
void s21::list<T>::push_back(const_reference value) {
  if (_size == max_size()) {
    throw std::invalid_argument("failed to add Node, _size == max_size");
  }
  Node *n_node = new Node(value);
  if (empty() == 1) {
    _head = n_node;
    _end = n_node;
  } else {
    _end->_next = n_node;
    n_node->_prev = _end;
    _end = n_node;
  }
  ++_size;
}

template <typename T>
typename s21::list<T>::const_reference s21::list<T>::back() {
  if (_size == 0) {
    throw std::out_of_range("list is empty - back()");
  }
  return _end->_data;
}

template <typename T>
typename s21::list<T>::const_reference s21::list<T>::front() {
  if (_size == 0) {
    throw std::out_of_range("list is empty - front()");
  }
  return _head->_data;
}

template <typename T>
void s21::list<T>::pop_back() {
  if (empty() == 1) {
    throw std::out_of_range("list is empty - pop_back()");
  }
  if (_size > 1) {
    Node *ptr = _end;
    _end = ptr->_prev;
    _end->_next = nullptr;
    delete ptr;
    --_size;
  } else {
    clear();
  }
}
template <typename T>
void s21::list<T>::pop_front() {
  if (empty() == 1) {
    throw std::out_of_range("list is empty - pop_front()");
  }
  if (_size > 1) {
    Node *ptr = _head;
    _head = ptr->_next;
    _head->_prev = nullptr;
    delete ptr;
    --_size;
  } else {
    clear();
  }
}

template <typename T>
void s21::list<T>::erase(iterator pos) {
  if (empty() == 1) {
    throw std::invalid_argument("List is empty - erase()");
  }
  if (pos._pointer == _head) {
    pop_front();
  } else if (pos._pointer == _end) {
    pop_back();
  } else {
    Node *change = pos._pointer;
    pos._pointer->_next->_prev = change->_prev;
    pos._pointer->_prev->_next = change->_next;
    delete change;
    --_size;
  }
}

template <typename T>
void s21::list<T>::unique() {
  iterator iter = begin();
  while (iter._pointer->_next != nullptr) {
    iterator second = iter;
    if (second._pointer->_data == second._pointer->_next->_data) {
      erase(second);
    }
    ++iter;
  }
}

template <typename T>
void s21::list<T>::reverse() {
  if (empty() == 1) {
    throw std::invalid_argument("List is empty - reverse()");
  }
  iterator up = begin();
  iterator back = end();
  --back;
  for (size_t count = 1; count <= (_size / 2); ++up, --back, count++) {
    std::swap(up._pointer->_data, back._pointer->_data);
  }
}

template <typename T>
void s21::list<T>::swap(list &other) {
  if (this == &other) {
    throw std::out_of_range("Lists is equal -swap()");
  }
  std::swap(_head, other._head);
  std::swap(_end, other._end);
  std::swap(_size, other._size);
}

template <typename T>
void s21::list<T>::splice(const_iterator pos, list &other) {
  if (_size + other._size >= max_size()) {
    throw std::out_of_range("Failed to splice lists, _size ==  max_size()");
  }
  iterator it_other = other.begin();
  for (; it_other != other.end(); ++it_other) {
    insert(pos, it_other._pointer->_data);
  }
}

template <typename T>
typename s21::list<T>::iterator s21::list<T>::insert(iterator pos,
                                                     const_reference value) {
  if (_size == max_size()) {
    throw std::out_of_range("failed to insert Node, _size == max_size");
  }
  if (pos._tail == nullptr && pos._pointer == nullptr) {
    throw std::invalid_argument("Iterator is nullptr");
  }
  if (pos._pointer == _head) {
    push_front(value);
  } else if (pos._pointer == nullptr) {
    push_back(value);
  } else {
    Node *add = new Node(value);
    add->_next = pos._pointer;
    add->_prev = pos._pointer->_prev;
    pos._pointer->_prev->_next = add;
    pos._pointer->_prev = add;
    ++_size;
  }
  return pos;
}

template <typename T>
void s21::list<T>::sort() {
  if (empty() == 1) {
    throw std::out_of_range("lists is empty");
  }
  for (size_t i = 1; i < _size; i++) {
    iterator check = begin();
    for (size_t j = i; j < _size; j++, ++check) {
      if (check._pointer->_next->_data < check._pointer->_data)
        std::swap(check._pointer->_data, check._pointer->_next->_data);
    }
  }
}

template <typename T>
void s21::list<T>::merge(list &other) {
  const_iterator add = cbegin();
  splice(add, other);
  sort();
}

template <typename T>
typename s21::list<T>::iterator s21::list<T>::begin() {
  iterator iter(*this);
  // iter._pointer = _head;
  return iter;
}
template <typename T>
typename s21::list<T>::iterator s21::list<T>::end() {
  iterator iter(*this);
  while (iter._pointer != nullptr) {
    ++iter;
  }
  return iter;
}
template <typename T>
typename s21::list<T>::const_iterator s21::list<T>::cbegin() {
  const_iterator iter(*this);
  return iter;
}
template <typename T>
typename s21::list<T>::const_iterator s21::list<T>::cend() {
  const_iterator iter(*this);
  while (iter._pointer != nullptr) {
    ++iter;
  }
  return iter;
}
/* ------------------LIST ITERATOR------------------ */
template <typename T>
s21::list<T>::ListIterator::ListIterator(const list<T> &other) {
  if (other._size == 0) {
    throw std::invalid_argument("List is empty");
  }
  _pointer = other._head;
  _tail = other._end;
}

template <typename T>
typename s21::list<T>::ListIterator &s21::list<T>::ListIterator::operator++() {
  if (_pointer == nullptr) {
    throw std::invalid_argument("Iterator is nullptr");
  }
  _tail = _pointer;
  _pointer = _pointer->_next;
  if (_pointer != nullptr) {
    _tail = nullptr;
  }
  return *this;
}
template <typename T>
typename s21::list<T>::ListIterator &s21::list<T>::ListIterator::operator--() {
  if (_tail == nullptr && _pointer == nullptr) {
    throw std::invalid_argument("Iterator is nullptr");
  }
  if (_pointer == nullptr) {
    _pointer = _tail;
  } else {
    _pointer = _pointer->_prev;
  }
  return *this;
}
template <typename T>
bool s21::list<T>::ListIterator::operator!=(const ListIterator &other) {
  return _pointer != other._pointer;
}
template <typename T>
bool s21::list<T>::ListIterator::operator==(const ListIterator &other) {
  return _pointer == other._pointer;
}
template <typename T>
typename s21::list<T>::reference s21::list<T>::ListIterator::operator*() {
  if (_pointer == nullptr) {
    throw std::invalid_argument("Othe element does not exist");
  }
  return _pointer->_data;
}
/* ------------------LIST CONST_ITERATOR------------------ */
template <typename T>
typename s21::list<T>::ListConstIterator &
s21::list<T>::ListConstIterator::operator=(const ListIterator &other) {
  this->_pointer = other._pointer;
  this->_tail = other._tail;
  return *this;
}
/* ------------------------BONUS------------------------ */
template <typename T>
template <typename... Args>
typename s21::list<T>::iterator s21::list<T>::emplace(const_iterator pos,
                                                      Args &&...args) {
  for (const_reference val : {args...}) {
    pos = insert(pos, val);
  }
  return pos;
}

template <typename T>
template <typename... Args>
void s21::list<T>::emplace_back(Args &&...args) {
  for (const_reference val : {args...}) {
    push_back(val);
  }
}

template <typename T>
template <typename... Args>
void s21::list<T>::emplace_front(Args &&...args) {
  for (const_reference val : {args...}) {
    push_front(val);
  }
}
