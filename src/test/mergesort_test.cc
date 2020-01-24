#include <gtest/gtest.h>
#include <Lab5/mergesort.h>
#include <Lab5/CustomIter.h>
#include <vector>


TEST(MERGE_SORT, REGULAR_VECTOR) {
    std::vector<int> v{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    mergesort(v.begin(), v.end());

    for(int i = 0; i < 10; i++)
        EXPECT_EQ(v[i], i);   
}

TEST(MERGE_SORT, ONE_ELEMENT_VECTOR) {
    std::vector<int> v{0};
    mergesort(v.begin(), v.end());
    EXPECT_EQ(v[0], 0);   
}
