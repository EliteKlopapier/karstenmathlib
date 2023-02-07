#ifndef ANTIINTERVALL 
    #define ANTIINTERVALL
    #include "Intervall.hpp"
    #include "Set.hpp"
    #include <string>
    #include <memory>

namespace kml {
    class Q;
    class Intervall;

    class AntiIntervall : public Set {
    public:
        AntiIntervall(double, double, bool = true, bool = true);
        double getLow() const;
        double getHigh() const;
        bool getLowInclude() const;
        bool getHighInclude() const; 
        bool isEmpty() const;
        bool contains(double);
        bool contains(float);
        bool contains(int);
        bool contains(long int);
        bool contains(long long int);
        template <typename T> bool contains(const T element) { return true; }
        virtual std::unique_ptr<Set> clone() const;
        std::string toString() const;
        std::string toStringASCII() const;
    private:
        bool _isSubset(const Q&) const;
        bool _isSubset(const Intervall&) const;
        bool _isSubset(const AntiIntervall&) const;
        bool _isSubset(const Set&) const;
        double low;
        double high;
        bool lowIncl;
        bool highIncl;
    };
}

#endif // ifndef ANTIINTERVALL