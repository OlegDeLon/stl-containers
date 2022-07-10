
namespace s21 {

/* ---------------------QUEUE CONSTRUCTOR--------------------- */
template <typename T>
queue<T>::queue() : _size(0), _head(nullptr), _end(nullptr) {}

template <typename T>
queue<T>::queue(std::initializer_list<value_type> const &items) : queue() {
  for (const_reference val : items) {
    push(val);
  }
}

template <typename T>
queue<T>::queue(const queue &q) : queue() {
  *this = q;
}

template <typename T>
queue<T> &queue<T>::operator=(const queue<T> &q) {
  if (this == &q) {
    throw std::out_of_range("Queues is equal");
  }
  clear();
  Node *copy = q._head;
  for (size_t i = 1; i <= q._size; i++) {
    push(copy->_data);
    copy = copy->_next;
  }
  return *this;
}

template <typename T>
queue<T>::queue(queue &&q) {
  *this = std::move(q);
}

template <typename T>
queue<T> &queue<T>::operator=(queue &&q) {
  clear();
  swap(q);
  return *this;
}

template <typename T>
queue<T>::~queue() {
  clear();
}

template <typename T>
void queue<T>::clear() {
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
/* ---------------------QUEUE FUNCTIONS--------------------- */
template <typename T>
typename queue<T>::const_reference queue<T>::front() {
  if (_size == 0) {
    throw std::out_of_range("Queue is empty - front()");
  }
  return _head->_data;
}
template <typename T>
typename queue<T>::const_reference queue<T>::back() {
  if (_size == 0) {
    throw std::out_of_range("Queue is empty - back()");
  }
  return _end->_data;
}
template <typename T>
bool queue<T>::empty() {
  return _head == nullptr;
}
template <typename T>
typename queue<T>::size_type queue<T>::size() {
  return _size;
}

template <typename T>
void queue<T>::push(const_reference value) {
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
void queue<T>::pop() {
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
void queue<T>::swap(queue &other) {
  if (this == &other) {
    throw std::out_of_range("Queues is equal -swap()");
  }
  std::swap(_head, other._head);
  std::swap(_end, other._end);
  std::swap(_size, other._size);
}

template <typename T>
template <typename... Args>
void queue<T>::emplace_back(Args &&...args) {
  for (const_reference val : {args...}) {
    push(val);
  }
}
}  // namespace s21
