#ifndef N_SET
    #define N_SET
    #include <type_traits>
    #include <memory>
    #include <string>
    #include <cmath>
    #include "Set.hpp"

namespace kml {
    // Set of natural numbers without zero
    class N : public Set {
    public:
        template <typename T> bool contains(const T element) { return std::is_arithmetic<T>::value && std::round(element) == element && element > 0; }
        N() { isinf = true; id = "n"; }
        bool isEmpty() const { return false; }
        std::string toString() const { return "ℕ"; }
        std::string toStringASCII() const { return "N"; }
        virtual std::unique_ptr<Set> clone() const { return std::make_unique<N>(*this); }
    private:
        bool _isSubset(const Set& set) const { return set.getId() == "q" || set.getId() == "z" || set.getId() == "n0" || set.getId() == "n"; }
    };

}
#endif // ifndef N_SET