#include <iostream>
#include <cmath>
#include "karstenmathlib.hpp"

// For testing purposes

using namespace kml;

int main(void)
{
    std::unique_ptr<Set> i = std::make_unique<Intervall>(1,2);
    auto a = ComplementarySet::complementary(i);
    //std::cout << std::is_same<decltype(*a), ComplementarySet>() << std::endl;
    //std::cout << a->contains(2);
    std::vector<int> v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    std::cout << sum(v);
    return 0;
}
