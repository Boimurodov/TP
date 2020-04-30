#pragma once

#include <vector>

namespace my_lib {
    class SegmentTree {
    public:
        int sum(int v, int tl, int tr, int l, int r);

        void update(int v, int tl, int tr, int pos, int new_val);

        explicit SegmentTree(const std::vector<int> &a);

    private:
        void build(const std::vector<int> &a, int v, int tl, int tr);

        std::vector<int> t;
        int n;
    };
}
