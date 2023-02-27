#include <cmath> 
#include "Intervall.hpp"

namespace kml {

    Intervall::Intervall(double min, double max, bool minInclusive, bool maxInclusive)
        : min(min), max(max), minIncl(minInclusive), maxIncl(maxInclusive) {
            isinf = std::isinf(min) || std::isinf(max);
            id = "intervall";
        }

    double Intervall::getMin() const { return min; }
    double Intervall::getMax() const { return max; }
    bool Intervall::getMinInclude() const { return minIncl; }
    bool Intervall::getMaxInclude() const { return maxIncl; }
    std::unique_ptr<Set> Intervall::clone() const { return std::make_unique<Intervall>(*this); }

    bool Intervall::isEmpty() const { return min > max || (min >= max && !(minIncl && maxIncl)); }

    bool Intervall::contains(const std::any& element) {
        if(element.type() == typeid(short int)) {
            short int e = std::any_cast<short int>(element);
            return ((minIncl && e >= min) || (!minIncl && e > min)) && ((maxIncl && e <= max) || (!maxIncl && e < max));
        }
        else if(element.type() == typeid(unsigned short int)) {
            unsigned short int e = std::any_cast<unsigned short int>(element);
            return ((minIncl && e >= min) || (!minIncl && e > min)) && ((maxIncl && e <= max) || (!maxIncl && e < max));
        }
        else if(element.type() == typeid(int)) {
            int e = std::any_cast<int>(element);
            return ((minIncl && e >= min) || (!minIncl && e > min)) && ((maxIncl && e <= max) || (!maxIncl && e < max));
        }
        else if(element.type() == typeid(unsigned int)) {
            unsigned int e = std::any_cast<unsigned int>(element);
            return ((minIncl && e >= min) || (!minIncl && e > min)) && ((maxIncl && e <= max) || (!maxIncl && e < max));
        }
        else if(element.type() == typeid(long int)) {
            long int e = std::any_cast<long int>(element);
            return ((minIncl && e >= min) || (!minIncl && e > min)) && ((maxIncl && e <= max) || (!maxIncl && e < max));
        }
        else if(element.type() == typeid(unsigned long int)) {
            unsigned long int e = std::any_cast<unsigned long int>(element);
            return ((minIncl && e >= min) || (!minIncl && e > min)) && ((maxIncl && e <= max) || (!maxIncl && e < max));
        }
        else if(element.type() == typeid(long long int)) {
            long long int e = std::any_cast<long long int>(element);
            return ((minIncl && e >= min) || (!minIncl && e > min)) && ((maxIncl && e <= max) || (!maxIncl && e < max));
        }
        else if(element.type() == typeid(unsigned long long int)) {
            unsigned long long int e = std::any_cast<unsigned long long int>(element);
            return ((minIncl && e >= min) || (!minIncl && e > min)) && ((maxIncl && e <= max) || (!maxIncl && e < max));
        }
        else if(element.type() == typeid(float)){
            float e = std::any_cast<float>(element);
            return ((minIncl && e >= min) || (!minIncl && e > min)) && ((maxIncl && e <= max) || (!maxIncl && e < max));
        }
        else if(element.type() == typeid(double)) {
            double e = std::any_cast<double>(element);
            return ((minIncl && e >= min) || (!minIncl && e > min)) && ((maxIncl && e <= max) || (!maxIncl && e < max));
        }
        else if(element.type() == typeid(long double)) {
            long double e = std::any_cast<long double>(element);
            return ((minIncl && e >= min) || (!minIncl && e > min)) && ((maxIncl && e <= max) || (!maxIncl && e < max));
        }
        else return false;
    }

    bool Intervall::_isSubset(const Q&) const { return true; }

    bool Intervall::_isSubset(const Intervall& intv) const {
        return (((intv.getMinInclude() || !minIncl) && min >= intv.getMin()) || (minIncl && !intv.getMinInclude() && min > intv.getMin()))
            && (((intv.getMaxInclude() || !maxIncl) && max <= intv.getMax()) || (maxIncl && !intv.getMaxInclude() && max > intv.getMax()));
    }

    /*bool Intervall::_isSubset(const AntiIntervall& aintv) const {
        return (max < aintv.getLow() || (max <= aintv.getLow() && !(maxIncl && !aintv.getLowInclude())))
            && (min > aintv.getHigh() || (min >= aintv.getHigh() && !(minIncl && !aintv.getHighInclude())));
    }*/

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
