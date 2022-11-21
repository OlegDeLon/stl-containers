namespace s21 {

template <class T>
stack<T>::stack() : s_capacity(4), s_size(0) {
    data = new value_type[4 * sizeof(value_type)];
    last = data;
}

template <class T>
stack<T>::stack(std::initializer_list<T> const &items) : s_capacity(4), s_size(0) {
    while (items.size() > s_capacity) {
        s_capacity *= 2;
    }
    data = new value_type[s_capacity];
    int i = 0;
    for (auto a : items) {
        data[i] = a;
        i++;
        s_size++;
    }
    last = (data + s_size - 1);
}

template <class T>
stack<T>::stack(const stack &s) : s_capacity(s.s_capacity), s_size(s.s_size) {
    data = new value_type[s_capacity];
    std::copy(s.data, s.data + s_capacity, data);
    last = s.last;
}

template <class T>
stack<T>::stack(stack &&s) : s_capacity(s.s_capacity), s_size(s.s_size) {
    data = new value_type[s_capacity];
    std::move(s.data, s.data + s_capacity, data);
    last = s.last;
    s.~stack();
}

template <class T>
stack<T> &stack<T>::operator=(stack &&s) {
    ~stack();
    s_capacity = s.s_capacity;
    s_size = s.s_size;
    std::swap(data, s.data);
    last = s.last;
    return *this;
}

template <class T>
stack<T>::~stack() {
    if (data) {
        delete[] data;
        data = nullptr;
        last = nullptr;
        s_capacity = 0;
        s_size = 0;
    }
}

// ------------------------------------------------------------------------------------

template <class T>
void stack<T>::push(const_reference value) {
    if (s_size == s_capacity) {
        s_capacity *= 2;
    }

    T *new_st = new value_type[s_capacity];

    for (size_t i = 0; i < size(); i++) {
        new_st[i] = data[i];
    }

    std::swap(data, new_st);
    delete[] new_st;
    new_st = nullptr;

    data[s_size] = value;
    s_size++;

    last = (data + s_size - 1);
}

template <class T>
void stack<T>::pop() {
    if (s_size - 1 == s_capacity / 2) {
        s_capacity /= 2;
    }
    s_size--;

    T *new_st = new value_type[s_capacity];
    for (size_t i = 0; i < size(); i++) {
        new_st[i] = data[i];
    }

    std::swap(data, new_st);

    delete[] new_st;
    new_st = nullptr;

    last = (data + s_size - 1);
}

template <class T>
typename stack<T>::size_type stack<T>::size() {
    return s_size;
}

template <class T>
typename stack<T>::const_reference stack<T>::top() {
    return *(last);
}

template <class T>
void stack<T>::swap(stack &other) {
    std::swap(s_capacity, other.s_capacity);
    std::swap(s_size, other.s_size);
    std::swap(data, other.data);
    std::swap(last, other.last);
}

template <class T>
template <class... Args>
void stack<T>::emplace_front(Args &&...args) {
    for (const_reference value : {args...}) {
        push(value);
    }
}

}  // namespace s21
