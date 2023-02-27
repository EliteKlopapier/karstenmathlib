#ifndef TYPEID_TYPETRAITS
    #define TYPEID_TYPETRAITS
    #include <typeinfo>
    
namespace kml {
    bool isArithmetic(const std::type_info&);
    bool isIntegral(const std::type_info&);
    bool isIntegralUnsigned(const std::type_info&);
}

#endif // ifndef TYPEID_TYPETRAITS