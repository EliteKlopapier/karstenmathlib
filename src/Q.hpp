#ifndef Q_SET
    #define Q_SET
    #include <memory>
    #include <string>
    #include <type_traits>
    #include "Set.hpp"

namespace kml {
    // Set of rational numbers
    class Q : public Set {
    public:
        template <typename T> bool contains(const T) { return std::is_arithmetic<T>::value; }
        Q() { isinf = true; id = "q"; }
        bool isEmpty() const { return false; }
        std::string toString() const { return "ℚ"; }
        std::string toStringASCII() const { return "Q"; }
        virtual std::unique_ptr<Set> clone() const { return std::make_unique<Q>(*this); }
    private:
        bool _isSubset(const Set& set) const { return set.getId() == "q"; } //...
    };
}
#endif // ifndef Q_SET