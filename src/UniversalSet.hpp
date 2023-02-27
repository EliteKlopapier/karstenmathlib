#ifndef UNIVERSALSET
    #define UNIVERSALSET
    #include "Set.hpp"
    #include <memory>
    #include <string>

namespace kml {
    class UniversalSet : public Set {
    public:
        bool contains(const std::any&) { return true; }
        UniversalSet() { isinf = true; id = "universal"; }
        bool isEmpty() const { return false; }
        std::string toString() const { return "𝕌"; }
        std::string toStringASCII() const { return "U"; }
        virtual std::unique_ptr<Set> clone() const { return std::make_unique<UniversalSet>(*this); }
    private:
        bool _isSubset(const Set& set) const { return set.getId() == "universal"; }
    };
}
#endif // ifndef UNIVERSALSET