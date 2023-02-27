#ifndef Z_SET
    #define Z_SET
    #include <type_traits>
    #include <memory>
    #include <string>
    #include <cmath>
    #include "Set.hpp"
    #include "typeid_typetraits.hpp"

namespace kml {
    // Set of integers
    class Z : public Set {
    public:
        bool contains(const std::any& element) { 
            if(isIntegral(element.type()))
                return true;
            else if(element.type() == typeid(float)){
                float e = std::any_cast<float>(element);
                return std::round(e) == e;
            }
            else if(element.type() == typeid(double)) {
                double e = std::any_cast<double>(element);
                return std::round(e) == e;
            }
            else if(element.type() == typeid(long double)) {
                long double e = std::any_cast<long double>(element);
                return std::round(e) == e;
            }
            else return false; 
        }
        Z() { isinf = true; id = "z"; }
        bool isEmpty() const { return false; }
        std::string toString() const { return "ℤ"; }
        std::string toStringASCII() const { return "Z"; }
        virtual std::unique_ptr<Set> clone() const { return std::make_unique<Z>(*this); }
    private:
        bool _isSubset(const Set& set) const { return set.getId() == "q" || set.getId() == "z"; }
    };
}
#endif // ifndef Z_SET