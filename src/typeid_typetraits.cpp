#include "typeid_typetraits.hpp"

namespace kml {
    bool isIntegralUnsigned(const std::type_info& t) {
        return t == typeid(unsigned short int)
            || t == typeid(unsigned int)
            || t == typeid(unsigned long int)
            || t == typeid(unsigned long long int);
    }

    bool isIntegral(const std::type_info& t) {
        return isIntegralUnsigned(t)
            || t == typeid(short int)
            || t == typeid(int)
            || t == typeid(long int)
            || t == typeid(long long int);
    }

    bool isArithmetic(const std::type_info& t) {
        return isIntegral(t)
            || t == typeid(float)
            || t == typeid(double)
            || t == typeid(long double);
    }
}