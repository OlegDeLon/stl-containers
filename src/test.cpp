#include <gtest/gtest.h>

#include <array>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "tests/list_test.cpp"
#include "tests/map_test.cpp"
#include "tests/multiset_test.cpp"
#include "tests/queue_test.cpp"
#include "tests/set_test.cpp"
#include "tests/vector_array_stack_test.cpp"

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
