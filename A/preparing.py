import sys

code = '''
#pragma once
#include <algorithm>

int gcd(int a, int b) {
    while(b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}
'''

path = sys.argv[1]
with open(path, "w") as f:
    f.write(code)
