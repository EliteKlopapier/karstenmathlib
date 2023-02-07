#ifndef Z_SET
    #define Z_SET
    #include <type_traits>
    #include <memory>
    #include <string>
    #include <cmath>
    #include "Set.hpp"

namespace kml {
    // Set of integers
    class Z : public Set {
    public:
        template <typename T> bool contains(const T element) { return std::is_arithmetic<T>::value && std::round(element) == element; }
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