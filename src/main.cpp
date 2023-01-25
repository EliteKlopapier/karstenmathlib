#include <iostream>
#include <cmath>
#include "karstenmathlib.hpp"

int main(void)
{
    //kml::CustomSet emptySet(false, [=](int element){ return false; }, [=](const kml::Set& set){ return true; }, "empty");
    kml::Intervall i(1,2);
    kml::AntiIntervall a = kml::ComplementarySet::Complementary(kml::Intervall(3,4));
    std::cout << (kml::Intervall(1,INFINITY)==kml::Intervall(1,INFINITY));
    return 0;
}
