#include "karstenmathlib.hpp"

namespace kml {

    bool Set::isInfinite() const { return isinf; }
    std::string Set::getId() const { return id; }

    bool Set::operator<=(const Set& set) { return isSubset(set); }
    bool Set::operator>=(const Set& set) { return isSuperset(set); }
    bool Set::operator<(const Set& set) { return isProperSubset(set); }
    bool Set::operator>(const Set& set) { return isProperSuperset(set); }

    bool Set::operator==(const Set& set) {
        return isSubset(set) && set.isSubset(*this);
    }

    bool Set::isSubset(const Set& set) const {
        if(id == set.getId() && (id == "empty" || id == "universal" || id == "q" || id == "z" || id == "n" || id == "n0")) return true; //<---- in einzelne klassen auslagern
        else if((isinf && !set.isInfinite()) || (set.isEmpty() && !isEmpty())) return false;
        else if(set.getId() == "universal" || isEmpty()) return true; //<---- leeres Intervall??
        else return _isSubset(set);
    }

    bool Set::isProperSubset(const Set& set) const{
        return isSubset(set) && !set.isSubset(*this);
    }

    bool Set::isSuperset(const Set& set) const {
        return set.isSubset(*this);
    }

    bool Set::isProperSuperset(const Set& set) const {
        return set.isProperSubset(*this);
    }
}