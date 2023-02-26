#include <cmath> 
#include "Intervall.hpp"

namespace kml {

    Intervall::Intervall(double min, double max, bool minInclusive, bool maxInclusive)
        : min(min), max(max), minIncl(minInclusive), maxIncl(maxInclusive) {
            isinf = min < max; //std::isinf(min) || std::isinf(max);
            id = "intervall";
        }

    double Intervall::getMin() const { return min; }
    double Intervall::getMax() const { return max; }
    bool Intervall::getMinInclude() const { return minIncl; }
    bool Intervall::getMaxInclude() const { return maxIncl; }
    std::unique_ptr<Set> Intervall::clone() const { return std::make_unique<Intervall>(*this); }

    bool Intervall::isEmpty() const { return min > max || (min >= max && !(minIncl && maxIncl)); }

    bool Intervall::contains(double element) {
        return ((minIncl && element >= min) || (!minIncl && element > min)) || ((maxIncl && element <= max) || (!maxIncl && element < max));
    }

    bool Intervall::contains(float element) {
        return ((minIncl && element >= min) || (!minIncl && element > min)) || ((maxIncl && element <= max) || (!maxIncl && element < max));
    }

    bool Intervall::contains(int element) {
        return ((minIncl && element >= min) || (!minIncl && element > min)) || ((maxIncl && element <= max) || (!maxIncl && element < max));
    }

    bool Intervall::contains(long int element) {
        return ((minIncl && element >= min) || (!minIncl && element > min)) || ((maxIncl && element <= max) || (!maxIncl && element < max));
    }

    bool Intervall::contains(long long int element) {
        return ((minIncl && element >= min) || (!minIncl && element > min)) || ((maxIncl && element <= max) || (!maxIncl && element < max));
    }

    bool Intervall::_isSubset(const Q&) const { return true; }

    bool Intervall::_isSubset(const Intervall& intv) const {
        return (((intv.getMinInclude() || !minIncl) && min >= intv.getMin()) || (minIncl && !intv.getMinInclude() && min > intv.getMin()))
            && (((intv.getMaxInclude() || !maxIncl) && max <= intv.getMax()) || (maxIncl && !intv.getMaxInclude() && max > intv.getMax()));
    }

    bool Intervall::_isSubset(const AntiIntervall& aintv) const {
        return (max < aintv.getLow() || (max <= aintv.getLow() && !(maxIncl && !aintv.getLowInclude())))
            && (min > aintv.getHigh() || (min >= aintv.getHigh() && !(minIncl && !aintv.getHighInclude())));
    }

    bool Intervall::_isSubset(const Set&) const { return false; }  

    std::string Intervall::toString() const {
        std::string str = "";
        str += minIncl ? "[" : "]";
        std::string minStr = std::to_string(min);
        minStr.std::string::resize(minStr.size()-4);
        str += minStr;
        str += ", ";
        std::string maxStr = std::to_string(max);
        maxStr.std::string::resize(maxStr.size()-4);
        str += maxStr;
        str += maxIncl ? "]" : "[";
        return str;
    } 

    std::string Intervall::toStringASCII() const { return toString(); }	
}
