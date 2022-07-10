#include "../s21_set.h"

TEST(test_set, empty1) {
    s21::set<int> s1;
    s21::set<int> s2({1});
    EXPECT_TRUE(s1.empty());
    EXPECT_FALSE(s2.empty());
}

TEST(test_set, empty2) {
    s21::set<int> set;
    std::set<int> origin;
    ASSERT_EQ(set.size(), origin.size());
    ASSERT_EQ(set.size(), 0);
}

TEST(test_set, size) {
    std::set<int> s1({1, 2, 3, 4, 5});
    s21::set<int> s2({1, 2, 3, 4, 5});
    EXPECT_EQ(s1.size(), s2.size());
}

TEST(test_set, max_size) {
    s21::set<int> set;
    EXPECT_EQ(set.max_size(), 288230376151711743);
}

TEST(test_set, it_begin_end) {
    s21::set<int> s1({5, 3, 4, 6});
    std::set<int> s2({5, 3, 4, 6});
    EXPECT_EQ(*s1.begin(), *s2.begin());
    EXPECT_EQ(*--s1.end(), *--s2.end());
}

TEST(test_set, it_begin_end_empty) {
    // s21::set<int> s1;

    // ASSERT_ANY_THROW(*s1.begin());
    // ASSERT_ANY_THROW(*--s1.end());
}

TEST(test_set, clear) {
    s21::set<int> s1({1});
    s1.clear();
    EXPECT_TRUE(s1.empty());
}

TEST(test_set, constructor_1) {
    s21::set<int> s1;
    EXPECT_TRUE(s1.empty());
}

TEST(test_set, constructor_2) {
    s21::set<int> s1({6, 4, 8, 2});
    EXPECT_EQ(s1.size(), 4);
    EXPECT_EQ(*s1.begin(), 2);
    EXPECT_EQ(*--s1.end(), 8);
}

TEST(test_set, constructor_3) {
    s21::set<int> s1({5, 3, 4, 6});
    s21::set<int> s2(s1);
    EXPECT_EQ(s1.size(), 4);
    EXPECT_EQ(*s1.begin(), 3);
    EXPECT_EQ(*--s1.end(), 6);
    EXPECT_EQ(s2.size(), 4);
    EXPECT_EQ(*s2.begin(), 3);
    EXPECT_EQ(*--s2.end(), 6);
}

TEST(test_set, constructor_4) {
    s21::set<int> s1({5, 3, 4, 6});
    s21::set<int> s2(std::move(s1));
    EXPECT_EQ(s2.size(), 4);
    EXPECT_EQ(*s2.begin(), 3);
    EXPECT_EQ(*--s2.end(), 6);
    EXPECT_EQ(s1.size(), 0);
}

TEST(test_set, constructor_5) {
    s21::set<int> s1({5, 3, 4, 6});
    s21::set<int> s2;
    s2 = std::move(s1);
    EXPECT_EQ(s2.size(), 4);
    EXPECT_EQ(*s2.begin(), 3);
    EXPECT_EQ(*--s2.end(), 6);
    EXPECT_EQ(s1.size(), 0);
}

TEST(test_set, constructor_6) {
    // s21::set<int> s1({5, 3, 4, 6});

    // ASSERT_ANY_THROW(s21::set<int> s1(s1));
}

TEST(test_set, insert1) {
    s21::set<int> s1;
    s1.insert(1);
    EXPECT_EQ(*s1.begin(), 1);
}

TEST(test_set, insert2) {
    s21::set<int> s1({1});
    EXPECT_EQ(*s1.begin(), 1);
}

TEST(test_set, insert3) {
    s21::set<int> s1;
    s1.insert(1);
    s1.insert(1);
    EXPECT_EQ(*s1.begin(), 1);
}
TEST(test_set, insert4) {
    s21::multiset<int> s1({1, 2, 4, 5});
    s21::multiset<int> s2({1, 2, 3, 4, 5, 6});
    s1.insert(3);
    s1.insert(6);
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    for (int i = 0; i < 6; i++) {
        EXPECT_EQ(*it1, *it2);
        ++it1;
        ++it2;
    }
}

TEST(test_set, erase1) {
    s21::set<int> s1({1, 2, 3, 4, 5});
    s21::set<int> s2({1, 2, 3, 4});
    s21::set<int>::iterator it;
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

TEST(test_set, erase2) {
    s21::set<int> s1({5, 1});
    s21::set<int> s2({1});
    s21::set<int>::iterator it;
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

TEST(test_set, erase3) {
    s21::set<int> s1({5, 8, 7, 9});
    s21::set<int> s2({5, 7, 9});
    s21::set<int>::iterator it;
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

TEST(test_set, erase4) {
    s21::set<int> s1({9, 6, 5});
    s21::set<int> s2({9, 5});
    s21::set<int>::iterator it;
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

TEST(test_set, erase5) {
    s21::set<int> s1({5, 7, 6});
    s21::set<int> s2({5, 6});
    s21::set<int>::iterator it;
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

TEST(test_set, erase6) {
    s21::set<int> s1({1});
    s21::set<int>::iterator it;
    it = s1.begin();
    s1.erase(it);
    EXPECT_TRUE(s1.empty());
}

TEST(test_set, swap1) {
    s21::set<int> s1({1, 2, 3, 4, 5});
    s21::set<int> s2({6, 7, 8, 9, 10});
    s1.swap(s2);
    EXPECT_EQ(*s1.begin(), 6);
    EXPECT_EQ(*--s1.end(), 10);
    EXPECT_EQ(*s2.begin(), 1);
    EXPECT_EQ(*--s2.end(), 5);
}

TEST(test_set, swap2) {
    // s21::set<int> s1({1, 2, 3, 4, 5});

    // ASSERT_ANY_THROW(s1.swap(s1));
}

TEST(test_set, find) {
    s21::set<int> s1({1, 3, 4, 5, 6});
    EXPECT_EQ(*s1.find(5), 5);
    EXPECT_EQ(*s1.find(3), 3);
}

TEST(test_set, find2) {
    // s21::set<int> s1;

    // ASSERT_ANY_THROW(s1.find(3));
}

TEST(test_set, contains) {
    s21::set<int> s1({1, 3, 4, 5, 6});
    EXPECT_TRUE(s1.contains(0));
    EXPECT_TRUE(s1.contains(0));
    EXPECT_FALSE(s1.contains(6));
}

TEST(test_set, emplace) {
    s21::set<int> s1;
    s21::set<int> s2{1, 2, 3, 4, 5, 6, 7, 8};
    s1.emplace(1, 2, 3, 4, 5, 6, 7, 8);
    auto it1 = s1.begin();
    auto it2 = s2.begin();
    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(*it1, *it2);
        ++it1;
        ++it2;
    }
}
TEST(test_set, merge) {
    s21::set<int> m1{15, 13, 17};
    s21::set<int> m2{18, 13, 17};

    s21::set<int> m3{15, 13, 17, 18};

    m1.merge(m2);

    auto it1 = m1.begin();
    auto it2 = m3.begin();
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(*it1, *it2);
        ++it1;
        ++it2;
    }
}
