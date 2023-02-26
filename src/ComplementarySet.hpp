#ifndef COMPLEMENTARYSET
    #define COMPLEMENTARYSET
    #include "UniversalSet.hpp"
    #include "EmptySet.hpp"
    #include "Set.hpp"
    #include "AntiIntervall.hpp"
    #include "Intervall.hpp"
    #include <memory>
    #include <string>
    #include <type_traits>

namespace kml {
    template <typename T>
    class ComplementarySet : public Set {
        static_assert(std::is_base_of<Set, T>::value, "T must inherit from Set.");
    private:
        ComplementarySet(const T& set)
        : complementOf(set) {
            id = "complement";
            isinf = true;
        }
        const T complementOf;
    public:
        bool isEmpty() const { return false; }
        std::string toString() const { return complementOf.toString() + "'"; }
        std::string toStringASCII() const { return complementOf.toStringASCII() + "'"; }
        template <typename T2> bool contains(const T2 set) { return !complementOf.contains(set); }
        T getComplementOf() { return complementOf; }
        
        static auto complementary(UniversalSet&) -> EmptySet { return EmptySet(); }
        static auto complementary(EmptySet&) -> UniversalSet { return UniversalSet(); }
        static auto complementary(T& set) -> ComplementarySet { return ComplementarySet(set); }
        static auto complementary(ComplementarySet& comp) -> decltype(comp.getComplementOf()) { return comp.getComplementOf(); }

        /*
        static std::unique_ptr<UniversalSet> Complementary(EmptySet&);
        static std::unique_ptr<EmptySet> Complementary(UniversalSet&);
        static std::unique_ptr<> Complementary(ComplementarySet&);
        static std::unique_ptr<AntiIntervall> Complementary(Intervall&);
        static std::unique_ptr<Intervall> Complementary(AntiIntervall&); 
        static std::unique_ptr<ComplementarySet> Complementary(Set&);
        std::unique_ptr<Set> getComplementOf();*/
        
        //virtual std::unique_ptr<Set> clone() const;
    private:
        bool _isSubset(const Set&) const { return false; }
        bool _isSubset(const ComplementarySet& comp) { return comp.getComplementOf().isSubset(complementOf); }
    };
/*
    std::unique_ptr<UniversalSet> operator!(EmptySet&);
    std::unique_ptr<EmptySet> operator!(UniversalSet&);
    std::unique_ptr<Set> operator!(ComplementarySet&);
    std::unique_ptr<AntiIntervall> operator!(Intervall&);
    std::unique_ptr<Intervall> operator!(AntiIntervall&);
    std::unique_ptr<ComplementarySet> operator!(Set&);*/

    //template <typename T2>
    //auto operator!(T2 set) { return ComplementarySet<T2>::complementary(set); }
    
}
#endif // ifndef COMPLEMENTARYSET