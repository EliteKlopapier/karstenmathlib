#include "AntiIntervall.hpp"
#include <cmath>

namespace kml {

    AntiIntervall::AntiIntervall(double low, double high, bool lowInclude, bool highInclude)
        : low(low), high(high), lowIncl(lowInclude), highIncl(highInclude) {
            isinf = !(low == -INFINITY && high == INFINITY);
            id = "antiintervall";
        }

    double AntiIntervall::getLow() const { return low; }
    double AntiIntervall::getHigh() const { return high; }
    bool AntiIntervall::getLowInclude() const { return lowIncl; }
    bool AntiIntervall::getHighInclude() const { return highIncl; }
    bool AntiIntervall::isEmpty() const { return !isinf; }
    std::unique_ptr<Set> AntiIntervall::clone() const { return std::make_unique<AntiIntervall>(*this); }

    bool AntiIntervall::contains(double element) {
        return ((lowIncl && element <= low) || (!lowIncl && element < low)) || ((highIncl && element >= high) || (!highIncl && element > high));
    }

    bool AntiIntervall::contains(float element) {
        return ((lowIncl && element <= low) || (!lowIncl && element < low)) || ((highIncl && element >= high) || (!highIncl && element > high));
    }

    bool AntiIntervall::contains(int element) {
        return ((lowIncl && element <= low) || (!lowIncl && element < low)) || ((highIncl && element >= high) || (!highIncl && element > high));
    }

    bool AntiIntervall::contains(long int element) {
        return ((lowIncl && element <= low) || (!lowIncl && element < low)) || ((highIncl && element >= high) || (!highIncl && element > high));
    }

    bool AntiIntervall::contains(long long int element) {
        return ((lowIncl && element <= low) || (!lowIncl && element < low)) || ((highIncl && element >= high) || (!highIncl && element > high));
    }

    bool AntiIntervall::_isSubset(const Q&) const { return true; }

    bool AntiIntervall::_isSubset(const AntiIntervall& aintv) const {
        return (low < aintv.getLow() || (low <= aintv.getLow() && !(lowIncl && !aintv.getLowInclude())))
            && (high > aintv.getHigh() || (high >= aintv.getHigh() && !(highIncl && !aintv.getHighInclude())));
    }

    bool AntiIntervall::_isSubset(const Intervall& intv) const {
        return intv.getMin() == -INFINITY && intv.getMax() == INFINITY;
    }

    bool AntiIntervall::_isSubset(const Set&) const { return false; }

    std::string AntiIntervall::toString() const {
        std::string str = "";
        str += lowIncl ? "]" : "[";
        std::string lowStr = std::to_string(low);
        lowStr.std::string::resize(lowStr.size()-4);
        str += lowStr;
        str += ", ";
        std::string highStr = std::to_string(high);
        highStr.std::string::resize(highStr.size()-4);
        str += highStr;
        str += highIncl ? "[" : "]";
        str += "'";
        return str;
    } 

    std::string AntiIntervall::toStringASCII() const {
        return toString();
    }
}