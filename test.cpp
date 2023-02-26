#include <iostream>
#include <cmath>
#include "karstenmathlib.hpp"

// For testing purposes

int main(void)
{
    //kml::CustomSet emptySet(false, [=](int element){ return false; }, [=](const kml::Set& set){ return true; }, "empty");
    kml::Intervall i(1,2);
    std::unique_ptr<kml::AntiIntervall> a = !i;
    std::cout << a->contains(2);
    return 0;
}
