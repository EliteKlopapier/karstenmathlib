/*#include <functional>
#include "karstenmathlib.hpp"

namespace kml {

    CustomSet::CustomSet(bool isInfinite, std::function<bool(int)> containsLambda, std::function<bool(const Set&)> subsetLambda, std::string id) {
        isinf = isInfinite;
        containsL = containsLambda;
        subsetL = subsetLambda;
    } 

    template <typename T> bool CustomSet::contains(const T element) {
        return containsL(element);
    }

    bool CustomSet::isSubset(const Set& set) {
        return subsetL(set);
    }
        
}*/