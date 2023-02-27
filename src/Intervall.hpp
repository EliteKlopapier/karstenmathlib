#ifndef INTERVALL
    #define INTERVALL
    #include "AntiIntervall.hpp"
    #include "Set.hpp"
    #include <string>
    #include <memory>

namespace kml {
    class Q;
    class AntiIntervall;

    class Intervall : public Set {
    public:
        Intervall(double, double, bool = true, bool = true);
        double getMin() const;
        double getMax() const;
        bool getMinInclude() const;
        bool getMaxInclude()const ; 
        bool isEmpty() const;
        bool contains(const std::any&);
        virtual std::unique_ptr<Set> clone() const;
        std::string toString() const;
        std::string toStringASCII() const;
    private:
        bool _isSubset(const Q&) const;
        bool _isSubset(const Intervall&) const;
        //bool _isSubset(const AntiIntervall&) const;
        bool _isSubset(const Set&) const;
        double min;
        double max;
        bool minIncl;
        bool maxIncl;
    };
}

#endif // ifndef INTERVALL