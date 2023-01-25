#include "karstenmathlib.hpp"

namespace kml {

    ComplementarySet::ComplementarySet(const Set& set)
        : complementOf(set) {
            id = "complement";
        }

    EmptySet ComplementarySet::Complementary(const UniversalSet&) { return EmptySet(); }
    UniversalSet ComplementarySet::Complementary(const EmptySet&) { return UniversalSet(); }
    Set ComplementarySet::Complementary(const ComplementarySet& compl) { return compl.getComplementOf(); }
    AntiInterval ComplementarySet::Complementary(const Intervall& intv) { 
        return AntiIntervall(intv.getMin(), intv.getMax(), !intv.getMinInclude(), !intv.getMaxInclude());
    }
    Intervall ComplementarySet::Complementary(const AntiIntervall& aintv) {
        return Intervall(aintv.getLow(), aintv.getHigh(), !aintv.getLowInclude(), !aintv.getHighInclude());
    }
    ComplementarySet ComplementarySet::Complementary(const Set& complementOf) {
        return ComplementarySet(complementOf);
    }

    bool ComplementarySet::isEmpty() { return false; }
    std::string ComplementarySet::toString() { return complementOf.toString() + "'"; }
    std::string ComplementarySet::toStringASCII() { return complementOf.toStringASCII() + "'"; }
    Set getComplementOf() { return complementOf; }

    template <typename T> bool ComplementarySet::contains(const T element) {
        return !complementOf.contains(element);
    }

    bool ComplementarySet::_isSubset(const Set& set) const {
        return ComplementarySet(set).isSubset(complementOf);
    }
}