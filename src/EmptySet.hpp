#ifndef EMPTYSET
    #define EMPTYSET
    #include "Set.hpp"
    #include <memory>
    #include <string>

namespace kml {
    class EmptySet : public Set {
    public:
        bool contains(const std::any&) { return false; }
        EmptySet() { isinf = false; id = "empty"; }
        bool isEmpty() const { return true; }
        std::string toString() const { return "Ø"; }
        std::string toStringASCII() const { return "{}"; }
        virtual std::unique_ptr<Set> clone() const { return std::make_unique<EmptySet>(*this); }
    private:
        bool _isSubset(const Set&) const { return true; }
    };
}
#endif // ifndef EMPTYSET   