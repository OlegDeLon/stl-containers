namespace s21 {

//----------------------constructors--------------------------

template <class T>
vector<T>::vector() : v_capacity(4), length(0) {
  v_data = new value_type(4);
}

template <class T>
vector<T>::vector(size_type v_capacity) : v_capacity(v_capacity), length(0) {
  v_data = new value_type[v_capacity];
}

template <class T>
vector<T>::vector(std::initializer_list<value_type> const &items)
    : v_capacity(4), length(0) {
  while (items.size() > v_capacity) {
    v_capacity *= 2;
  }
  v_data = new value_type[v_capacity];
  for (auto &i : items) {
    v_data[length] = i;
    length++;
  }
}

template <class T>
vector<T>::vector(const vector<T> &other)
    : v_capacity(other.v_capacity), length(other.length) {
  v_data = new value_type[v_capacity];
  std::copy(other.v_data, other.v_data + v_capacity, v_data);
}

template <class T>
vector<T>::vector(vector &&other)
    : v_capacity(other.v_capacity), length(other.length) {
  v_data = new value_type[v_capacity];
  std::move(other.v_data, other.v_data + v_capacity, v_data);
  delete[] other.v_data;
  other.v_data = nullptr;
  other.v_capacity = 0;
  other.length = 0;
}

//----------------------destructor----------------------------

template <class T>
vector<T>::~vector() {
  if (v_data) {
    delete[] v_data;
    v_data = nullptr;
    v_capacity = 0;
    length = 0;
  }
}

//----------------------operator=-----------------------------

template <class T>
vector<T> &vector<T>::operator=(vector &&other) {
  v_data.~v_data();
  v_capacity = other.v_capacity;
  length = other.length;
  std::swap(v_data, other.v_data);
  return *this;
}

//----------------------methods-------------------------------

template <class T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos > length - 1) {
    throw std::out_of_range("vector.length is less than index");
  } else
    return v_data[pos];
}

template <class T>
void vector<T>::reserve(size_type size) {
  if (size <= v_capacity) {
    return;
  }
  v_capacity = size;

  iterator new_it = new value_type[v_capacity];
  for (size_t i = 0; i < length; i++) {
    new_it[i] = v_data[i];
  }

  std::swap(v_data, new_it);

  delete[] new_it;
  new_it = nullptr;
}

template <class T>
void vector<T>::shrink_to_fit() {
  v_capacity = length;

  iterator new_it = new value_type[v_capacity];
  for (size_t i = 0; i < length; i++) {
    new_it[i] = v_data[i];
  }

  std::swap(v_data, new_it);

  delete[] new_it;
  new_it = nullptr;
}

template <class T>
void vector<T>::push_back(const_reference value) {
  if (v_capacity == length) {
    reserve(2 * capacity());
  }

  new (v_data + length) value_type(value);
  length++;
}

template <class T>
void vector<T>::pop_back() {
  length--;
  (v_data + length)->~value_type();
}

template <class T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  size_t position = pos - v_data;

  if (length == v_capacity) {
    reserve(v_capacity * 2);
  }

  for (size_t i = length; i > 0; i--) {
    v_data[i] = v_data[i - 1];
    if (i == position) {
      break;
    }
  }

  length++;
  v_data[position] = value;
  pos = v_data + position;
  return pos;
}

template <class T>
void vector<T>::erase(iterator pos) {
  if (length != 0) {
    size_t position = pos - v_data;
    iterator it_end = end();
    do {
      v_data[position] = v_data[position + 1];
      position++;
      pos++;
    } while (pos != it_end);
  }
  length--;
}

template <class T>
template <class Type, class... Args>
typename vector<T>::iterator vector<T>::emplace(iterator pos, Type number,
                                                Args... args) {
  pos = insert(pos, number);
  emplace(pos, args...);
  return pos;
}

template <class T>
void vector<T>::swap(vector &other) {
  std::swap(v_capacity, other.v_capacity);
  std::swap(length, other.length);
  std::swap(v_data, other.v_data);
}

template <class T>
template <class Type, class... Args>
void vector<T>::emplace_back(Type number, Args... args) {
  push_back(number);
  emplace_back(args...);
}

}  // namespace s21