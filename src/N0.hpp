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
        template <typename T> bool contains(const T element) { return std::is_arithmetic<T>::value && std::round(element) == element && element >= 0; }
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