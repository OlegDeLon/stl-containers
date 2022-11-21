namespace s21 {

//----------------------operator []-----------------------
template <class T, size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
  if (pos >= size()) throw std::out_of_range("index out of array size");
  return data[pos];
}

//----------------------copy constructor------------------
template <class T, size_t N>
array<T, N>::array(const array& other) {
  if (N < other.size()) {
    throw std::out_of_range("not enough space");
  }
  std::copy(other.data, other.data + N, data);
}

//----------------------move constructor------------------
template <class T, size_t N>
array<T, N>::array(array&& other) {
  if (N < other.size()) {
    throw std::out_of_range("not enough space");
  }
  std::move(other.data, other.data + N, data);
}

//----------------------initializer list constructor------
template <class T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const& items) {
  if (items.size() > N)
    throw std::out_of_range(
        "The size of initializer list is bigger than array");
  size_type i = 0;
  for (const auto& item : items) {
    at(i++) = item;
  }
}

//---------------------- swap ----------------------------
template <class T, size_t N>
void array<T, N>::swap(array& other) {
  if (size() != other.size())
    throw std::out_of_range("arrays have different sizes");
  for (size_type i = 0; i < size(); i++) {
    std::swap(at(i), other.at(i));
  }
}
//---------------------- fill ----------------------------
template <class T, size_t N>
void array<T, N>::fill(const_reference value) {
  for (size_type i = 0; i < size(); i++) {
    at(i) = value;
  }
}

//----------------------operator =------------------------
template <class T, size_t N>
array<T, N>& array<T, N>::operator=(array&& other) {
  for (size_type i = 0; i < N; i++) {
    this[i] = other.data[i];
    at(i) = other.at(i);
  }
  return *this;
}

//----------------------method at-------------------------
template <class T, size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  if (pos >= N) throw std::out_of_range("out of array range");
  return *(data + pos);
}
}  // namespace s21