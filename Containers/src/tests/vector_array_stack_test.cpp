#include "../s21_array.h"
#include "../s21_stack.h"
#include "../s21_vector.h"

#define ONE \
    { 1, 2, 3, 4 }

template <class T, size_t N>
bool isEqual(s21::array<T, N> s21array, std::array<T, N> stdarray) {
    bool result = true;
    if (stdarray.size() != s21array.size()) {
        result = false;
    }
    for (size_t i = 0; i < s21array.size(); i++) {
        if (stdarray[i] != s21array[i]) {
            result = false;
        }
    }
    return result;
}

template <class T>
bool VisEqual(s21::vector<T> s21vector, std::vector<T> stdvector) {
    bool result = true;
    if (stdvector.size() != s21vector.size()) {
        result = false;
    }
    for (size_t i = 0; i < s21vector.size(); i++) {
        if (stdvector[i] != s21vector[i]) {
            result = false;
        }
    }
    return result;
}

TEST(array_constructors, 1) {
    s21::array<int, 4> our_array ONE;
    std::array<int, 4> std_array ONE;
    ASSERT_TRUE(isEqual(our_array, std_array));
}

TEST(array_constructors, 2) {
    s21::array<int, 4> our_array ONE;
    s21::array<int, 4> our_copy(our_array);
    std::array<int, 4> std_array ONE;
    std::array<int, 4> std_copy(std_array);
    ASSERT_TRUE(isEqual(our_copy, std_copy));
}

TEST(array_constructors, 3) {
    s21::array<int, 4> our_array ONE;
    s21::array<int, 4> our_moved = std::move(our_array);
    std::array<int, 4> std_array ONE;
    std::array<int, 4> std_moved = std::move(std_array);
    ASSERT_TRUE(isEqual(our_moved, std_moved));
}

TEST(array_operators_square_brackets, 4) {
    s21::array<int, 4> our_array ONE;
    std::array<int, 4> std_array ONE;
    for (size_t i = 0; i < our_array.size(); i++) {
        ASSERT_TRUE(our_array[i] == std_array[i]);
    }
}

TEST(array_methods_at, 5) {
    s21::array<int, 4> our_array ONE;
    std::array<int, 4> std_array ONE;
    for (size_t i = 0; i < our_array.size(); i++) {
        ASSERT_TRUE(our_array.at(i) == std_array.at(i));
    }
}

TEST(array_methods_fill, 6) {
    s21::array<int, 10> our_array;
    std::array<int, 10> std_array;

    std_array.fill(3);
    our_array.fill(3);

    for (size_t i = 0; i < our_array.size(); i++) {
        ASSERT_TRUE(our_array.at(i) == 3);
    }
    ASSERT_TRUE(isEqual(our_array, std_array));
}

TEST(array_methods_equal, 7) {
    s21::array<int, 4> other ONE;
    s21::array<int, 4> our_array = other;

    for (size_t i = 0; i < our_array.size(); i++) {
        our_array.at(i) = other.at(i);
    }
}

TEST(array_methods_swap, 8) {
    s21::array<int, 10> our_array{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    s21::array<int, 10> our_array_2{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    std::array<int, 10> std_array{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::array<int, 10> std_array_2{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    our_array_2.swap(our_array);
    std_array_2.swap(std_array);

    ASSERT_TRUE(isEqual(our_array, std_array));
    ASSERT_TRUE(isEqual(our_array_2, std_array_2));
}

TEST(array_iterators, 9) {
    s21::array<int, 4> our_array ONE;
    s21::array<int, 4>::iterator it_our_array = our_array.begin();
    std::array<int, 4> std_array ONE;
    std::array<int, 4>::iterator it_std_array = std_array.begin();
    for (; it_our_array != our_array.end(); ++it_our_array, ++it_std_array) {
        ASSERT_TRUE(*it_our_array == *it_std_array);
    }
}

TEST(array_empty, 10) {
    s21::array<int, 4> our_array;
    s21::array<int, 10> our_array_2{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    std::array<int, 4> std_array;
    std::array<int, 10> std_array_2{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    ASSERT_TRUE(our_array.empty() == std_array.empty());
    ASSERT_TRUE(our_array_2.empty() == std_array_2.empty());
}

TEST(array_front_back, 11) {
    s21::array<int, 10> our_array{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    std::array<int, 10> std_array_2{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    ASSERT_TRUE(our_array.front() == std_array_2.front());
    ASSERT_TRUE(our_array.back() == std_array_2.back());
}

TEST(vector_constructors, 1) {
    s21::vector<int> our_vector ONE;
    std::vector<int> std_vector ONE;
    ASSERT_TRUE(VisEqual(our_vector, std_vector));
}

TEST(vector_constructors, 2) {
    s21::vector<int> our_vector ONE;
    s21::vector<int> our_copy(our_vector);
    std::vector<int> std_array ONE;
    std::vector<int> std_copy(std_array);
    ASSERT_TRUE(VisEqual(our_copy, std_copy));
}

TEST(vector_constructors, 3) {
    s21::vector<int> our_array ONE;
    s21::vector<int> our_moved = std::move(our_array);
    std::vector<int> std_array ONE;
    std::vector<int> std_moved = std::move(std_array);
    ASSERT_TRUE(VisEqual(our_moved, std_moved));
}

TEST(vector_operators_square_brackets, 4) {
    s21::vector<int> our_array ONE;
    std::vector<int> std_array ONE;
    for (size_t i = 0; i < our_array.size(); i++) {
        ASSERT_TRUE(our_array[i] == std_array[i]);
    }
}

TEST(vector_size_max_size_capacity, 5) {
    s21::vector<int> our_array ONE;
    std::vector<int> std_array ONE;
    ASSERT_TRUE(our_array.size() == std_array.size());
    ASSERT_TRUE(our_array.capacity() == std_array.capacity());
    ASSERT_TRUE(our_array.max_size() == std_array.max_size());
}

TEST(vector_methods_at, 6) {
    s21::vector<int> our_array ONE;
    std::vector<int> std_array ONE;
    for (size_t i = 0; i < our_array.size(); i++) {
        ASSERT_TRUE(our_array.at(i) == std_array.at(i));
    }
}

TEST(vector_methods_push_pop_back, 7) {
    s21::vector<int> our_array ONE;
    std::vector<int> std_array ONE;
    our_array.push_back(1);
    std_array.push_back(1);
    ASSERT_TRUE(VisEqual(our_array, std_array));
    our_array.pop_back();
    std_array.pop_back();
    ASSERT_TRUE(VisEqual(our_array, std_array));
}

TEST(vector_reserve_shrink_to_fit, 8) {
    s21::vector<int> our_array ONE;
    std::vector<int> std_array ONE;
    our_array.reserve(1233);
    std_array.reserve(1233);
    ASSERT_TRUE(our_array.capacity() == std_array.capacity());
    our_array.shrink_to_fit();
    std_array.shrink_to_fit();
    ASSERT_TRUE(our_array.capacity() == std_array.capacity());
}

TEST(vector_erase, 9) {
    s21::vector<int> our_array ONE;
    s21::vector<int>::iterator our_it = our_array.begin();
    std::vector<int> std_array ONE;
    std::vector<int>::iterator std_it = std_array.begin();
    our_array.erase(our_it + 1);
    std_array.erase(std_it + 1);
    ASSERT_TRUE(VisEqual(our_array, std_array));
}

TEST(vector_insert, 10) {
    s21::vector<int> our_array ONE;
    s21::vector<int>::iterator our_it = our_array.begin();
    std::vector<int> std_array ONE;
    std::vector<int>::iterator std_it = std_array.begin();
    our_array.insert(our_it + 1, 5);
    std_array.insert(std_it + 1, 5);
    ASSERT_TRUE(VisEqual(our_array, std_array));
}

TEST(vector_emplace, 11) {
    s21::vector<int> our_array;
    std::vector<int> std_array{5, 4, 3, 2, 1};
    our_array.emplace(our_array.begin(), 1, 2, 3, 4, 5);
    ASSERT_TRUE(VisEqual(our_array, std_array));
}

TEST(vector_emplace_back, 12) {
    s21::vector<int> our_array ONE;
    std::vector<int> std_array ONE;
    our_array.emplace_back(1, 2, 3);
    std_array.emplace_back(1);
    std_array.emplace_back(2);
    std_array.emplace_back(3);
    ASSERT_TRUE(VisEqual(our_array, std_array));
}

TEST(vector_clear_empty, 13) {
    s21::vector<int> our_array ONE;
    std::vector<int> std_array;
    our_array.clear();
    ASSERT_TRUE(our_array.empty() == std_array.empty());
}

TEST(vector_front_back, 14) {
    s21::vector<int> our_array ONE;
    std::vector<int> std_array ONE;
    ASSERT_TRUE(our_array.front() == std_array.front());
    ASSERT_TRUE(our_array.back() == std_array.back());
}

TEST(vector_swap, 15) {
    s21::vector<int> our_array ONE;
    s21::vector<int> sec_array{52, 33, 342, 12, 15, 16};
    std::vector<int> std_array ONE;
    std::vector<int> std_sec_array{52, 33, 342, 12, 15, 16};
    our_array.swap(sec_array);
    std_array.swap(std_sec_array);
    ASSERT_TRUE(VisEqual(our_array, std_array));
    ASSERT_TRUE(VisEqual(sec_array, std_sec_array));
}

TEST(vector_iterators, 16) {
    s21::vector<int> our_array ONE;
    s21::vector<int>::iterator it_our = our_array.begin();
    std::vector<int> std_array ONE;
    std::vector<int>::iterator it_std = std_array.begin();

    for (; it_our != our_array.end(); ++it_our, ++it_std) {
        ASSERT_TRUE(*it_our == *it_std);
    }
}

TEST(stack_default_constructor, 1) {
    s21::stack<int> our_stack;
    std::stack<int> std_stack;
    ASSERT_TRUE(our_stack.empty() == std_stack.empty());
}

TEST(stack_copy_constructor, 2) {
    s21::stack<int> our_stack ONE;
    s21::stack<int> copy_stack(our_stack);
    for (size_t i = 0; i < our_stack.size(); i++) {
        ASSERT_TRUE(our_stack[i] == copy_stack[i]);
    }
}

TEST(stack_move_constructor, 3) {
    s21::stack<int> our_stack ONE;
    s21::stack<int> our_stack_2 ONE;
    s21::stack<int> our_stack_3 = std::move(our_stack_2);
    for (size_t i = 0; i < our_stack.size(); i++) {
        ASSERT_TRUE(our_stack[i] == our_stack_3[i]);
    }
}

TEST(stack_operator_equal, 4) {
    s21::stack<int> our_stack ONE;
    s21::stack<int> our_stack_2(our_stack);
    for (size_t i = 0; i < our_stack.size(); i++) {
        ASSERT_TRUE(our_stack[i] == our_stack_2[i]);
    }
}

TEST(stack_push_pop, 5) {
    s21::stack<int> our_stack;
    std::stack<int> std_stack;
    our_stack.push(3);
    std_stack.push(3);
    ASSERT_TRUE(our_stack.top() == std_stack.top());
    our_stack.push(4);
    std_stack.push(4);
    ASSERT_TRUE(our_stack.top() == std_stack.top());
    our_stack.pop();
    std_stack.pop();
    ASSERT_TRUE(our_stack.top() == std_stack.top());
}

TEST(stack_emplace_front, 6) {
    s21::stack<int> our_stack;
    std::stack<int> std_stack;
    std_stack.push(1);
    std_stack.push(2);
    std_stack.push(3);
    std_stack.push(4);
    our_stack.emplace_front(1, 2, 3, 4);
    for (size_t i = 0; i < our_stack.size(); i++) {
        ASSERT_TRUE(our_stack.top() == std_stack.top());
    }
}

TEST(stack_swap, 7) {
    s21::stack<int> our_stack;
    s21::stack<int> our_stack_2;
    our_stack_2.emplace_front(1, 2, 3, 4);
    s21::stack<int> our_stack_3;
    s21::stack<int> our_stack_4;
    our_stack_4.emplace_front(1, 2, 3, 4);
    for (size_t i = 0; i < our_stack.size(); i++) {
        ASSERT_TRUE(our_stack[i] == our_stack_3[i]);
    }
    for (size_t i = 0; i < our_stack.size(); i++) {
        ASSERT_TRUE(our_stack_4[i] == our_stack_2[i]);
    }

    our_stack.swap(our_stack_2);
    our_stack_3.swap(our_stack_4);

    for (size_t i = 0; i < our_stack.size(); i++) {
        ASSERT_TRUE(our_stack[i] == our_stack_3[i]);
    }
    for (size_t i = 0; i < our_stack.size(); i++) {
        ASSERT_TRUE(our_stack_4[i] == our_stack_2[i]);
    }
}
