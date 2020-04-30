#include <random>
#include <stdio.h>
#include "main.h"

int main() {
    int n = rand() % 10 + 2;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10000;
    }
    my_lib::SegmentTree st(a);
    for (int i = 0; i < 1000; i++) {
        if (i % 10 == 0) {
            printf("%d\n",  i);
        }
        int l = rand() % n;
        int r = rand() % n;
        if (l > r) {
            std::swap(l, r);
        }
        printf("%d\n", st.sum(1, 0, n - 1, l, r));
    }
}
