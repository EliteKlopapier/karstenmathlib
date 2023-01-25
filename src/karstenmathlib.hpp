#include <type_traits>
#include <string>
//#include <functional>
#include <tgmath.h>

namespace kml {

    class Q;
    class AntiIntervall;
    class UniversalSet;
    class EmptySet;

    class Set {
    public:
        bool isInfinite() const;
        std::string getId() const;
        virtual bool isEmpty() const = 0;
        template <typename T> bool contains(const T);
        bool isSubset(const Set&) const;
        bool isProperSubset(const Set&) const;
        bool isSuperset(const Set&) const;
        bool isProperSuperset(const Set&) const;
        virtual std::string toString() = 0;
        virtual std::string toStringASCII() = 0;
        bool operator<=(const Set&);
        bool operator==(const Set&);
    protected:
        virtual bool _isSubset(const Set&) const = 0;
        bool isinf;
        std::string id;
    };

    class Intervall : public Set {
    public:
        Intervall(double, double, bool = true, bool = true);
        double getMin() const;
        double getMax() const;
        bool getMinInclude() const;
        bool getMaxInclude()const ; 
        bool isEmpty() const;
        bool contains(double);
        bool contains(float);
        bool contains(int);
        bool contains(long int);
        bool contains(long long int);
        template <typename T> bool contains(const T element) { return false; }
        std::string toString();
        std::string toStringASCII();
    private:
        bool _isSubset(const Q&) const;
        bool _isSubset(const Intervall&) const;
        bool _isSubset(const AntiIntervall&) const;
        bool _isSubset(const Set&) const;
        double min;
        double max;
        bool minIncl;
        bool maxIncl;
    };

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
        template <typename T> bool contains(const T element) { return false; }
        std::string toString();
        std::string toStringASCII();
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

    class ComplementarySet : public Set {
    public:
        bool isEmpty() const;
        std::string toString();
        std::string toStringASCII();
        template <typename T> bool contains(const T);
        static UniversalSet Complementary(const EmptySet&);
        static EmptySet Complementary(const UniversalSet&);
        static Set Complementary(const ComplementarySet&);
        static AntiIntervall Complementary(const Intervall&);
        static Intervall Complementary(const AntiIntervall&); 
        static ComplementarySet Complementary(const Set&);
        Set getComplementOf();
    private:
        ComplementarySet(const Set&);
        bool _isSubset(const Set&) const;
        const Set& complementOf;
    };

    /*class CustomSet : public Set {
    public:
        CustomSet(bool, std::function<bool(int)>, std::function<bool(const Set&)>, std::string = "custom");
        template <typename T> bool contains(const T element) { return false; }
        bool isSubset(const Set&);
    private:
        std::function<bool(int)> containsL;
        std::function<bool(const Set&)> subsetL;
    };*/

    class EmptySet : public Set {
    public:
        template <typename T> bool contains(const T) { return false; }
        EmptySet() { isinf = false; id = "empty"; }
        bool isEmpty() const { return true; }
        std::string toString() { return "Ø"; }
        std::string toStringASCII() { return "{}"; }
    private:
        bool _isSubset(const Set&) const { return true; }
    };
    
    class UniversalSet : public Set {
    public:
        template <typename T> bool contains(const T) { return true; }
        UniversalSet() { isinf = true; id = "universal"; }
        bool isEmpty() const { return false; }
        std::string toString() { return "𝕌"; }
        std::string toStringASCII() { return "U"; }
    private:
        bool _isSubset(const Set&) const { return false; }
    };

    // Set of rational numbers
    class Q : public Set {
    public:
        template <typename T> bool contains(const T) { return std::is_arithmetic<T>::value; }
        Q() { isinf = true; id = "q"; }
        bool isEmpty() const { return false; }
        std::string toString() { return "ℚ"; }
        std::string toStringASCII() { return "Q"; }
    private:
        bool _isSubset(const Set&) const { return false; } //...
    };

    // Set of integers
    class Z : public Set {
    public:
        template <typename T> bool contains(const T element) { return std::is_arithmetic<T>::value && std::round(element) == element; }
        Z() { isinf = true; id = "z"; }
        bool isEmpty() const { return false; }
        std::string toString() { return "ℤ"; }
        std::string toStringASCII() { return "Z"; }
    private:
        bool _isSubset(const Set& set) const { return set.getId() == "q"; }
    };

    // Set of natural numbers without zero
    class N : public Set {
    public:
        template <typename T> bool contains(const T element) { return std::is_arithmetic<T>::value && std::round(element) == element && element > 0; }
        N() { isinf = true; id = "n"; }
        bool isEmpty() const { return false; }
        std::string toString() { return "ℕ"; }
        std::string toStringASCII() { return "N"; }
    private:
        bool _isSubset(const Set& set) const { return set.getId() == "q" || set.getId() == "z" || set.getId() == "n0"; }
    };

    // Set of natural numbers including zero
    class N0 : public Set {
    public:
        template <typename T> bool contains(const T element) { return std::is_arithmetic<T>::value && std::round(element) == element && element >= 0; }
        N0() { isinf = true; id = "n0"; }
        bool isEmpty() const { return false; }
        std::string toString() { return "ℕ₀"; }
        std::string toStringASCII() { return "N0"; }
    private:
        bool _isSubset(const Set& set) const { return set.getId() == "q" || set.getId() == "z"; }
    };
}