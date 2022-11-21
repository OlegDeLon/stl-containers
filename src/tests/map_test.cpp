#include <gtest/gtest.h>

#include "../s21_map.h"

#define PAIR_INT                                                                                  \
    {                                                                                             \
        std::pair<int, int>(50, 3), std::pair<int, int>(25, 23), std::pair<int, int>(12, 63),     \
            std::pair<int, int>(37, 37), std::pair<int, int>(18, 53), std::pair<int, int>(6, 93), \
            std::pair<int, int>(31, 13), std::pair<int, int>(45, 31), std::pair<int, int>(1, 33), \
            std::pair<int, int>(8, 35), std::pair<int, int>(10, 35), std::pair<int, int>(14, 34), \
            std::pair<int, int>(20, 33), std::pair<int, int>(27, 76), std::pair<int, int>(33, 1), \
            std::pair<int, int>(35, 33), std::pair<int, int>(39, 76), std::pair<int, int>(42, 1), \
            std::pair<int, int>(47, 33)                                                           \
    }

TEST(test_map, empty1) {
    s21::map<int, int> m1;
    s21::map<int, int> m2(PAIR_INT);
    EXPECT_TRUE(m1.empty());
    EXPECT_FALSE(m2.empty());
}

TEST(test_map, empty2) {
    s21::map<int, int> map;
    std::map<int, int> origin;
    ASSERT_EQ(map.size(), origin.size());
    ASSERT_EQ(map.size(), 0);
}

TEST(test_map, size) {
    std::map<int, int> m1(PAIR_INT);
    s21::map<int, int> m2(PAIR_INT);
    ASSERT_EQ(m1.size(), m2.size());
}

TEST(test_map, max_size) {
    s21::map<int, int> map;
    ASSERT_EQ(map.max_size(), 288230376151711743);
}

TEST(test_map, clear) {
    s21::map<int, int> m1(PAIR_INT);
    m1.clear();
    EXPECT_TRUE(m1.empty());
}
TEST(test_map, at) {
    std::map<int, int> m1(PAIR_INT);
    s21::map<int, int> m2(PAIR_INT);

    ASSERT_EQ(m1.at(50), m2.at(50));
}

TEST(test_map, constructor_1) {
    s21::map<int, int> m1;
    EXPECT_TRUE(m1.empty());
}

TEST(test_map, constructor_2) {
    s21::map<int, int> m1(PAIR_INT);
    ASSERT_EQ(m1.size(), 19);
}

TEST(test_map, constructor_3) {
    s21::map<int, int> m1(PAIR_INT);
    s21::map<int, int> m2(m1);
    ASSERT_EQ(m1.size(), 19);
    ASSERT_EQ(m2.size(), 19);
}

TEST(test_map, constructor_4) {
    s21::map<int, int> m1(PAIR_INT);
    s21::map<int, int> m2(std::move(m1));
    ASSERT_EQ(m2.size(), 19);
    ASSERT_EQ(m1.size(), 0);
}

TEST(test_map, insert1) {
    s21::map<int, int> m1;
    std::map<int, int> m2;

    s21::map<int, int>::iterator it;
    std::map<int, int>::iterator std_it;

    m1.insert(1, 1);
    m2.insert(std::pair<int, int>(1, 1));
    it = m1.begin();
    std_it = m2.begin();
    EXPECT_EQ((*it).first, (*std_it).first);
}
TEST(test_map, insert2) {
    s21::map<int, int> m1;
    m1[55] = 88;
    m1[2] = 7;
    m1[233] = 252;
    m1.insert_or_assign(3, 18);

    EXPECT_EQ(m1[3], 18);
}

TEST(test_map, erase1) {
    s21::map<int, int> m1;
    m1[1] = 2;
    m1[2] = 2;
    m1[3] = 2;
    m1[4] = 2;
    m1[5] = 2;
    s21::map<int, int>::iterator it;
    it = --m1.end();
    --it;
    m1.erase(it);
    EXPECT_FALSE(m1.empty());
}

TEST(test_map, erase2) {
    s21::map<int, int> m1;
    m1[1] = 5;
    m1[2] = 1;

    s21::map<int, int>::iterator it;
    it = --m1.end();
    m1.erase(it);
    EXPECT_FALSE(m1.empty());
}

TEST(test_map, erase3) {
    s21::map<int, int> m1;
    m1[5] = 2;
    m1[8] = 2;
    m1[7] = 2;
    m1[9] = 2;

    s21::map<int, int>::iterator it;
    it = --m1.end();
    --it;
    m1.erase(it);
    EXPECT_FALSE(m1.empty());
}

TEST(test_map, erase4) {
    s21::map<int, int> m1;
    m1[9] = 2;
    m1[6] = 2;
    m1[5] = 2;

    s21::map<int, int>::iterator it;
    it = --m1.end();
    --it;
    m1.erase(it);
    EXPECT_FALSE(m1.empty());
}

TEST(test_map, erase5) {
    s21::map<int, int> m1;
    m1[5] = 2;
    m1[7] = 2;
    m1[6] = 2;

    s21::map<int, int>::iterator it;
    it = --m1.end();
    m1.erase(it);
    EXPECT_FALSE(m1.empty());
}

TEST(test_map, erase6) {
    s21::map<int, int> m1({std::pair<int, int>(4, 23)});
    s21::map<int, int>::iterator it;
    it = m1.begin();
    m1.erase(it);
    EXPECT_TRUE(m1.empty());
}

TEST(test_map, swap1) {
    s21::map<int, int> m1({std::pair<int, int>(4, 23)});
    s21::map<int, int> m2({std::pair<int, int>(33, 2)});
    m1.swap(m2);
}

// TEST(test_map, swap2) {
//     s21::map<int, int> m1({std::pair<int, int>(4, 23)});

//     ASSERT_ANY_THROW(m1.swap(m1));
// }

TEST(test_map, merge) {
    s21::map<int, int> m1;
    s21::map<int, int> m2;

    s21::map<int, int> m3;

    m1[15] = 2;
    m1[13] = 2;
    m1[17] = 2;

    m2[18] = 2;
    m2[13] = 2;
    m2[17] = 2;

    m3[15] = 2;
    m3[13] = 2;
    m3[17] = 2;
    m3[18] = 2;

    m1.merge(m2);

    s21::map<int, int>::iterator it;
    s21::map<int, int>::iterator std_it;
    it = m1.begin();
    std_it = m3.begin();
    while (it != --m1.end()) {
        EXPECT_EQ((*it).first, (*std_it).first);
        EXPECT_EQ((*it).second, (*std_it).second);
        ++it;
        ++std_it;
    }
}

// TEST(test_map, find2) {
//     s21::map<int, int> m1;

//     ASSERT_ANY_THROW(m1.find(3));
// }

TEST(test_map, contains) {
    s21::map<int, int> m1(PAIR_INT);
    EXPECT_FALSE(m1.contains(18));
    EXPECT_TRUE(m1.contains(13));
}

TEST(test_map, emplace) {
    s21::map<int, int> my_map;

    // std::cout << my_map.at(5);
    std::map<int, int> original_map;
    std::pair<int, int> pair = {1, 1};
    auto my_pair = my_map.emplace(pair);
    auto original_pair = original_map.emplace(pair);
    EXPECT_EQ((*(my_pair.first)).first, (*(original_pair.first)).first);
    EXPECT_EQ((*(my_pair.first)).second, (*(original_pair.first)).second);
    s21::map<int, int>::iterator my_it = my_map.begin();
    std::map<int, int>::iterator originalIt = original_map.begin();
    for (size_t i = 0; i < my_map.size(); i++) {
        EXPECT_EQ((*my_it).first, (*originalIt).first);
        EXPECT_EQ((*my_it).second, (*originalIt).second);
        ++my_it;
        ++originalIt;
    }
}

TEST(test_map, operator_add1) {
    s21::map<int, int> m1(PAIR_INT);
    std::map<int, int> m2(PAIR_INT);

    s21::map<int, int>::iterator it;
    std::map<int, int>::iterator std_it;
    it = m1.begin();
    std_it = m2.begin();
    while (it != --m1.end()) {
        EXPECT_EQ((*it).first, (*std_it).first);
        EXPECT_EQ((*it).second, (*std_it).second);
        ++it;
        ++std_it;
    }
}

TEST(test_map, operator_sub) {
    s21::map<int, int> m1(PAIR_INT);
    std::map<int, int> m2(PAIR_INT);

    s21::map<int, int>::iterator it;
    std::map<int, int>::iterator std_it;
    it = --m1.end();
    std_it = --m2.end();
    while (it != m1.begin()) {
        EXPECT_EQ((*it).first, (*std_it).first);
        EXPECT_EQ((*it).second, (*std_it).second);
        --it;
        --std_it;
    }
}
