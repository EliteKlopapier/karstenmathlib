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
    public:
        bool isEmpty() const;
        std::string toString() const;
        std::string toStringASCII() const;
        template <typename T> bool contains(const T);
        static std::unique_ptr<UniversalSet> Complementary(EmptySet&);
        static std::unique_ptr<EmptySet> Complementary(UniversalSet&);
        static std::unique_ptr<Set> Complementary(ComplementarySet&);
        static std::unique_ptr<AntiIntervall> Complementary(Intervall&);
        static std::unique_ptr<Intervall> Complementary(AntiIntervall&); 
        static std::unique_ptr<ComplementarySet> Complementary(Set&);
        std::unique_ptr<Set> getComplementOf();
        virtual std::unique_ptr<Set> clone() const;
    private:
        ComplementarySet(const Set&);
        bool _isSubset(const Set&) const;
        const Set& complementOf;
    };
}
#endif // ifndef COMPLEMENTARYSET