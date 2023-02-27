#include "product.hpp"

namespace kml {
    long factorial(int n) {
        return product<long>(0, n-1, [n](int i) { return n - i; });
    }

    int choose(int n, int k) {
        return factorial(n) / (factorial(n - k) * factorial(k));
    }
}