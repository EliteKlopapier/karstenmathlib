#include "ComplementarySet.hpp"

namespace kml {

    ComplementarySet::ComplementarySet(const Set& set)
        : complementOf(set) {
            id = "complement";
            isinf = true;
        }

    std::unique_ptr<Set> ComplementarySet::clone() const { return std::make_unique<ComplementarySet>(*this); }

    std::unique_ptr<EmptySet> ComplementarySet::Complementary(UniversalSet&) { return std::make_unique<EmptySet>(EmptySet()); }
    std::unique_ptr<UniversalSet> ComplementarySet::Complementary(EmptySet&) { return std::make_unique<UniversalSet>(UniversalSet()); }
    std::unique_ptr<Set> ComplementarySet::Complementary(ComplementarySet& comp) { return comp.getComplementOf(); }
    std::unique_ptr<AntiIntervall> ComplementarySet::Complementary(Intervall& intv) { 
        return std::make_unique<AntiIntervall>(AntiIntervall(intv.getMin(), intv.getMax(), !intv.getMinInclude(), !intv.getMaxInclude()));
    }
    std::unique_ptr<Intervall> ComplementarySet::Complementary(AntiIntervall& aintv) {
        return std::make_unique<Intervall>(Intervall(aintv.getLow(), aintv.getHigh(), !aintv.getLowInclude(), !aintv.getHighInclude()));
    }
    std::unique_ptr<ComplementarySet> ComplementarySet::Complementary(Set& complementOf) {
        return std::make_unique<ComplementarySet>(ComplementarySet(complementOf));
    }

    std::unique_ptr<UniversalSet> operator!(EmptySet& set) { return ComplementarySet::Complementary(set); }
    std::unique_ptr<EmptySet> operator!(UniversalSet& set) { return ComplementarySet::Complementary(set); }
    std::unique_ptr<Set> operator!(ComplementarySet& set) { return ComplementarySet::Complementary(set); }
    std::unique_ptr<AntiIntervall> operator!(Intervall& set) { return ComplementarySet::Complementary(set); }
    std::unique_ptr<Intervall> operator!(AntiIntervall& set) { return ComplementarySet::Complementary(set); }
    std::unique_ptr<ComplementarySet> operator!(Set& set) { return ComplementarySet::Complementary(set); }

    bool ComplementarySet::isEmpty() const { return false; }
    std::string ComplementarySet::toString() const { return complementOf.toString() + "'"; }
    std::string ComplementarySet::toStringASCII() const { return complementOf.toStringASCII() + "'"; }
    std::unique_ptr<Set> ComplementarySet::getComplementOf() { return complementOf.clone(); }

    template <typename T> bool ComplementarySet::contains(const T element) {
        return !complementOf.contains(element);
    }

    bool ComplementarySet::_isSubset(const Set& set) const {
        return  false;// ComplementarySet(set).isSubset(ComplementarySet::complementOf); // <--- Schnittmenge vom Original und set empty?
    }
}