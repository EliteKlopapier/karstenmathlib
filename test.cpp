#include <iostream>
#include <cmath>
#include "karstenmathlib.hpp"
#include <any>

// For testing purposes

using namespace kml;

int main(void)
{
    std::unique_ptr<Set> i = std::make_unique<Intervall>(1,2);
    auto a = !i;
    std::cout << UniversalSet().contains("chungus");
    return 0;
}
