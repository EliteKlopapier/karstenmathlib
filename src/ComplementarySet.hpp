#ifndef COMPLEMENTARYSET
    #define COMPLEMENTARYSET
    #include "UniversalSet.hpp"
    #include "EmptySet.hpp"
    #include "Set.hpp"
    #include "AntiIntervall.hpp"
    #include "Intervall.hpp"
    #include <memory>
    #include <string>

namespace kml {
    class ComplementarySet : public Set {
    private:
        ComplementarySet(const std::unique_ptr<Set>&);
        bool _isSubset(const Set&) const;
        const std::unique_ptr<Set>& complementOf;
    public:
        bool isEmpty() const;
        std::string toString() const;
        std::string toStringASCII() const;
        bool contains(const std::any& element);
        static std::unique_ptr<Set> complementary(const std::unique_ptr<Set>&);
        std::unique_ptr<Set> getComplementOf();
        virtual std::unique_ptr<Set> clone() const;
    };

    std::unique_ptr<Set> operator!(const std::unique_ptr<Set>&);
    
}
#endif // ifndef COMPLEMENTARYSET