#include "ComplementarySet.hpp"
#include <type_traits>

namespace kml {

    ComplementarySet::ComplementarySet(const std::unique_ptr<Set>& set)
        : complementOf(set) {
            id = "complement";
            isinf = true;
        }

    std::unique_ptr<Set> ComplementarySet::clone() const { return std::make_unique<ComplementarySet>(*this); }

    std::unique_ptr<Set> ComplementarySet::complementary(const std::unique_ptr<Set>& set) {
        if constexpr(std::is_same<decltype(*set), EmptySet>()) {
            return std::make_unique<UniversalSet>();
        }
        else if constexpr(std::is_same<decltype(*set), UniversalSet>()) {
            return std::make_unique<EmptySet>();
        }
        else if constexpr(std::is_same<decltype(*set), ComplementarySet>()) {
            return std::unique_ptr<Set>(dynamic_cast<ComplementarySet*>(set.get())->getComplementOf());
        }
        else {
            return std::make_unique<ComplementarySet>(ComplementarySet(set));
        }
    }

    std::unique_ptr<Set> operator!(const std::unique_ptr<Set>& set) { return ComplementarySet::complementary(set); }

    bool ComplementarySet::isEmpty() const { return false; }
    std::string ComplementarySet::toString() const { return complementOf->toString() + "'"; }
    std::string ComplementarySet::toStringASCII() const { return complementOf->toStringASCII() + "'"; }
    std::unique_ptr<Set> ComplementarySet::getComplementOf() { return complementOf->clone(); }

    bool ComplementarySet::contains(const std::any& element) {
        return !complementOf->contains(element);
    }

    bool ComplementarySet::_isSubset(const Set& set) const {
        return  false;// ComplementarySet(set).isSubset(ComplementarySet::complementOf); // <--- Schnittmenge vom Original und set empty?
    }
}