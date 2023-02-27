#ifndef N0_SET
    #define N0_SET
    #include <type_traits>
    #include <memory>
    #include <string>
    #include <cmath>
    #include "Set.hpp"

namespace kml {
    // Set of natural numbers including zero
    class N0 : public Set {
    public:
        bool contains(const std::any& element) { 
            if(element.type() == typeid(short int)) {
                short int e = std::any_cast<short int>(element);
                return e >= 0;
            }
            else if(element.type() == typeid(unsigned short int)) {
                unsigned short int e = std::any_cast<unsigned short int>(element);
                return e >= 0;
            }
            else if(element.type() == typeid(int)) {
                int e = std::any_cast<int>(element);
                return e >= 0;
            }
            else if(element.type() == typeid(unsigned int)) {
                unsigned int e = std::any_cast<unsigned int>(element);
                return e >= 0;
            }
            else if(element.type() == typeid(long int)) {
                long int e = std::any_cast<long int>(element);
                return e >= 0;
            }
            else if(element.type() == typeid(unsigned long int)) {
                unsigned long int e = std::any_cast<unsigned long int>(element);
                return e >= 0;
            }
            else if(element.type() == typeid(long long int)) {
                long long int e = std::any_cast<long long int>(element);
                return e >= 0;
            }
            else if(element.type() == typeid(unsigned long long int)) {
                unsigned long long int e = std::any_cast<unsigned long long int>(element);
                return e >= 0;
            }
            else if(element.type() == typeid(float)){
                float e = std::any_cast<float>(element);
                return std::round(e) == e && e >= 0;
            }
            else if(element.type() == typeid(double)) {
                double e = std::any_cast<double>(element);
                return std::round(e) == e && e >= 0;
            }
            else if(element.type() == typeid(long double)) {
                long double e = std::any_cast<long double>(element);
                return std::round(e) == e && e >= 0;
            }
            else return false; 
        }
        N0() { isinf = true; id = "n0"; }
        bool isEmpty() const { return false; }
        std::string toString() const { return "ℕ₀"; }
        std::string toStringASCII() const { return "N0"; }
        virtual std::unique_ptr<Set> clone() const { return std::make_unique<N0>(*this); }
    private:
        bool _isSubset(const Set& set) const { return set.getId() == "q" || set.getId() == "z" || set.getId() == "n0"; }
    };
}
#endif // ifndef N0_SET