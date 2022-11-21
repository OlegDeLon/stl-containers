#include "../s21_multiset.h"

TEST(test_multiset, empty1) {
    s21::multiset<int> s1;
    s21::multiset<int> s2({1});
    EXPECT_TRUE(s1.empty());
    EXPECT_FALSE(s2.empty());
}

TEST(test_multiset, empty2) {
    s21::multiset<int> multiset;
    std::multiset<int> origin;
    ASSERT_EQ(multiset.size(), origin.size());
    ASSERT_EQ(multiset.size(), 0);
}

TEST(test_multiset, size) {
    std::multiset<int> s1({1, 2, 3, 4, 5});
    s21::multiset<int> s2({1, 2, 3, 4, 5});
    EXPECT_EQ(s1.size(), s2.size());
}

TEST(test_multiset, max_size) {
    s21::multiset<int> multiset;
    EXPECT_EQ(multiset.max_size(), 288230376151711743);
}

TEST(test_multiset, it_begin_end) {
    s21::multiset<int> s1({5, 3, 4, 6});
    std::multiset<int> s2({5, 3, 4, 6});
    EXPECT_EQ(*s1.begin(), *s2.begin());
    EXPECT_EQ(*--s1.end(), *--s2.end());
}

// TEST(test_multiset, it_begin_end_empty) {
//   s21::multiset<int> s1;

//   ASSERT_ANY_THROW(*s1.begin());
//   ASSERT_ANY_THROW(*--s1.end());
// }

TEST(test_multiset, clear) {
    s21::multiset<int> s1({1});
    s1.clear();
    EXPECT_TRUE(s1.empty());
}

TEST(test_multiset, constructor_1) {
    s21::multiset<int> s1;
    EXPECT_TRUE(s1.empty());
}

TEST(test_multiset, constructor_2) {
    s21::multiset<int> s1({6, 4, 8, 2});
    EXPECT_EQ(s1.size(), 4);
    EXPECT_EQ(*s1.begin(), 2);
    EXPECT_EQ(*--s1.end(), 8);
}

TEST(test_multiset, constructor_3) {
    s21::multiset<int> s1({5, 3, 4, 6});
    s21::multiset<int> s2(s1);
    EXPECT_EQ(s1.size(), 4);
    EXPECT_EQ(*s1.begin(), 3);
    EXPECT_EQ(*--s1.end(), 6);
    EXPECT_EQ(s2.size(), 4);
    EXPECT_EQ(*s2.begin(), 3);
    EXPECT_EQ(*--s2.end(), 6);
}

TEST(test_multiset, constructor_4) {
    s21::multiset<int> s1({5, 3, 4, 6});
    s21::multiset<int> s2(std::move(s1));
    EXPECT_EQ(s2.size(), 4);
    EXPECT_EQ(*s2.begin(), 3);
    EXPECT_EQ(*--s2.end(), 6);
    EXPECT_EQ(s1.size(), 0);
}

TEST(test_multiset, constructor_5) {
    s21::multiset<int> s1({5, 3, 4, 6});
    s21::multiset<int> s2;
    s2 = std::move(s1);
    EXPECT_EQ(s2.size(), 4);
    EXPECT_EQ(*s2.begin(), 3);
    EXPECT_EQ(*--s2.end(), 6);
    EXPECT_EQ(s1.size(), 0);
}

// TEST(test_multiset, constructor_6) {
//   s21::multiset<int> s1({5, 3, 4, 6});
//   ASSERT_ANY_THROW(s21::multiset<int> s1(s1));
// }

TEST(test_multiset, insert1) {
    s21::multiset<int> s1;
    s1.insert(1);
    EXPECT_EQ(*s1.begin(), 1);
}

TEST(test_multiset, insert2) {
    s21::multiset<int> s1({1});
    EXPECT_EQ(*s1.begin(), 1);
}

TEST(test_multiset, insert3) {
    s21::multiset<int> s1;
    s1.insert(1);
    s1.insert(1);
    EXPECT_EQ(*s1.begin(), 1);
}
TEST(test_multiset, insert4) {
    s21::multiset<int> s1({1, 2, 3, 4, 5, 5, 6});
    std::multiset<int> s2({1, 2, 3, 4, 5, 5, 6});
    s21::multiset<int>::iterator it1 = s1.insert(5);
    std::multiset<int>::iterator it2 = s2.insert(5);
    EXPECT_EQ(*it1, *it2);
    EXPECT_EQ(s1.size(), s2.size());
}
TEST(test_multiset, insert5) {
    s21::multiset<int> s1({1, 2, 4, 5, 5, 6});
    s21::multiset<int> s2({1, 2, 3, 4, 5, 5, 6, 6});
    s1.insert(3);
    s1.insert(6);
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(*it1, *it2);
        ++it1;
        ++it2;
    }
}

TEST(test_multiset, erase1) {
    s21::multiset<int> s1({1, 2, 3, 4, 5});
    s21::multiset<int> s2({1, 2, 3, 4});
    s21::multiset<int>::iterator it;
    it = --s1.end();
    s1.erase(it);
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(*it1, *it2);
        ++it1;
        ++it2;
    }
}

TEST(test_multiset, erase2) {
    s21::multiset<int> s1({5, 1});
    s21::multiset<int> s2({1});
    s21::multiset<int>::iterator it;
    it = --s1.end();
    s1.erase(it);
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    for (int i = 0; i < 1; i++) {
        EXPECT_EQ(*it1, *it2);
        ++it1;
        ++it2;
    }
}

TEST(test_multiset, erase3) {
    s21::multiset<int> s1({5, 8, 7, 9});
    s21::multiset<int> s2({5, 7, 9});
    s21::multiset<int>::iterator it;
    it = --s1.end();
    --it;
    s1.erase(it);
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(*it1, *it2);
        ++it1;
        ++it2;
    }
}

TEST(test_multiset, erase4) {
    s21::multiset<int> s1({9, 6, 5});
    s21::multiset<int> s2({9, 5});
    s21::multiset<int>::iterator it;
    it = --s1.end();
    --it;
    s1.erase(it);
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    for (int i = 0; i < 2; i++) {
        EXPECT_EQ(*it1, *it2);
        ++it1;
        ++it2;
    }
}

TEST(test_multiset, erase5) {
    s21::multiset<int> s1({5, 7, 6});
    s21::multiset<int> s2({5, 6});
    s21::multiset<int>::iterator it;
    it = --s1.end();

    s1.erase(it);
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    for (int i = 0; i < 2; i++) {
        EXPECT_EQ(*it1, *it2);
        ++it1;
        ++it2;
    }
}
TEST(test_multiset, erase6) {
    s21::multiset<int> s1({1});
    s21::multiset<int>::iterator it;
    it = s1.begin();
    s1.erase(it);
    EXPECT_TRUE(s1.empty());
}

TEST(test_multiset, swap1) {
    s21::multiset<int> s1({1, 2, 3, 4, 5});
    s21::multiset<int> s2({6, 7, 8, 9, 10});
    s1.swap(s2);
    EXPECT_EQ(*s1.begin(), 6);
    EXPECT_EQ(*--s1.end(), 10);
    EXPECT_EQ(*s2.begin(), 1);
    EXPECT_EQ(*--s2.end(), 5);
}

// TEST(test_multiset, swap2) {
//   s21::multiset<int> s1({1, 2, 3, 4, 5});

//   ASSERT_ANY_THROW(s1.swap(s1));
// }

TEST(test_multiset, merge) {
    s21::multiset<int> s1({1, 2, 3, 4, 5});
    s21::multiset<int> s2({6, 7, 8, 9, 10});
    s1.merge(s2);
    EXPECT_EQ(s1.size(), 10);
    EXPECT_EQ(*s1.begin(), 1);
    EXPECT_EQ(*--s1.end(), 10);
}

TEST(test_multiset, find) {
    s21::multiset<int> s1({1, 3, 4, 5, 6});
    EXPECT_EQ(*s1.find(5), 5);
    EXPECT_EQ(*s1.find(3), 3);
}

// TEST(test_multiset, find2) {
//     s21::multiset<int> s1;

//     ASSERT_ANY_THROW(s1.find(3));
// }

TEST(test_multiset, contains) {
    s21::multiset<int> s1({1, 3, 4, 5, 6});
    EXPECT_TRUE(s1.contains(0));
    EXPECT_TRUE(s1.contains(0));
    EXPECT_FALSE(s1.contains(6));
}

TEST(test_multiset, emplace) {
    s21::multiset<int> s1;
    s1.emplace(1, 2, 3, 4, 5, 6, 7, 8);
    EXPECT_EQ(*s1.begin(), 1);
    EXPECT_EQ(*--s1.end(), 8);
}

TEST(test_multiset, operator_add1) {
    s21::multiset<int> s1;
    s1.emplace(50, 25, 12, 37, 18, 6, 31, 45, 1, 8, 10, 14, 20, 27, 33, 35, 39, 42, 47);

    s21::multiset<int>::iterator it;
    it = s1.begin();
    while (it != --s1.end()) {
        ++it;
    }
    EXPECT_EQ(*s1.begin(), 1);

    EXPECT_EQ(*--s1.end(), 50);
}

TEST(test_multiset, operator_add2) {
    s21::multiset<int> s1;
    s1.emplace(50);

    s21::multiset<int>::iterator it;
    it = s1.begin();

    ++it;

    EXPECT_EQ(*s1.begin(), 50);
}

TEST(test_multiset, operator_sub) {
    s21::multiset<int> s1;
    s1.emplace(50, 25, 12, 37, 18, 6, 31, 45, 1, 8, 10, 14, 20, 27, 33, 35, 39, 42, 47);

    s21::multiset<int>::iterator it;
    it = --s1.end();
    while (it != s1.begin()) {
        --it;
    }
    EXPECT_EQ(*s1.begin(), 1);

    EXPECT_EQ(*--s1.end(), 50);
}

TEST(test_multiset, equal) {
    s21::multiset<int> s1({5, 3, 4, 6});
    std::multiset<int> s2({5, 3, 4, 6});
    // std::pair<int, int> s21_pair;
    // std::pair<int, int> std_pair;
    auto s21_pair = s1.equal_range(6);
    auto std_pair = s2.equal_range(6);

    EXPECT_EQ(*s21_pair.first, *std_pair.first);
}
