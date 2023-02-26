#include <iostream>
#include <cmath>
#include "karstenmathlib.hpp"

// For testing purposes

using namespace kml;

int main(void)
{
    Intervall i(1,2);
    Q q();
    auto a = ComplementarySet<Q>::complementary(q);
    std::cout << a;
    return 0;
}
