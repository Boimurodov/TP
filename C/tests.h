#pragma once

#include "gtest/gtest.h"
#include "B/lib.h"
#include "A/index.h"

TEST(TreeTest, SegmentTreeTest) {
    int n = 100;
    std::vector<int> data(n);
    for (int i = 0; i < n; i++) {
        data[i] = rand() % n;
        if (rand() % 2) {
            data[i] *= -1;
        }
    }

    my_lib::SegmentTree st(data);
    for (int i = 0; i < n; i++) {
        int l = rand() % n;
        int r = rand() % n;
        if (l > r) {
            std::swap(l, r);
        }
        int expectedSum = 0;
        for (int j = l; j <= r; j++) {
            expectedSum += data[j];
        }
        ASSERT_EQ(expectedSum, st.sum(1, 0, n - 1, l, r));
    }
    printf("segment tree passed all tests!\n");
};

TEST(NumTest, testGcd) {
    for (int i = 0; i < 1000; i++) {
        int a = rand() % 1000 + 1;
        int b = rand() % 1000 + 1;

        int trueGcd = 1;
        for (int x = 1; x <= std::min(a, b); x++) {
            if (a % x == 0 && b % x == 0) {
                trueGcd = x;
            }
        }
        ASSERT_EQ(trueGcd, gcd(a, b));
    }
    printf("gcd passed all tests!\n");
}
