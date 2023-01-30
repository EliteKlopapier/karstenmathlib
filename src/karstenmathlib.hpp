#include <type_traits>
#include <string>
//#include <functional>
#include <tgmath.h>
#include <memory>

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
        virtual std::unique_ptr<Set> clone() const = 0;
        virtual std::string toString() const = 0;
        virtual std::string toStringASCII() const = 0;
        bool operator<=(const Set&);
        bool operator>=(const Set&);
        bool operator<(const Set&);
        bool operator>(const Set&);
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
        virtual std::unique_ptr<Set> clone() const;
        std::string toString() const;
        std::string toStringASCII() const;
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

    class ComplementarySet : public Set {
    public:
        bool isEmpty() const;
        std::string toString() const;
        std::string toStringASCII() const;
        template <typename T> bool contains(const T);
        static std::unique_ptr<UniversalSet> Complementary(EmptySet&);
        static std::unique_ptr<EmptySet> Complementary(UniversalSet&);
        static std::unique_ptr<Set> Complementary(ComplementarySet&);
        static std::unique_ptr<AntiIntervall> Complementary(Intervall&);
        static std::unique_ptr<Intervall> Complementary(AntiIntervall&); 
        static std::unique_ptr<ComplementarySet> Complementary(Set&);
        std::unique_ptr<Set> getComplementOf();
        virtual std::unique_ptr<Set> clone() const;
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
        std::string toString() const { return "Ø"; }
        std::string toStringASCII() const { return "{}"; }
        virtual std::unique_ptr<Set> clone() const { return std::make_unique<EmptySet>(*this); }
    private:
        bool _isSubset(const Set&) const { return true; }
    };
    
    class UniversalSet : public Set {
    public:
        template <typename T> bool contains(const T) { return true; }
        UniversalSet() { isinf = true; id = "universal"; }
        bool isEmpty() const { return false; }
        std::string toString() const { return "𝕌"; }
        std::string toStringASCII() const { return "U"; }
        virtual std::unique_ptr<Set> clone() const { return std::make_unique<UniversalSet>(*this); }
    private:
        bool _isSubset(const Set&) const { return false; }
    };

    // Set of rational numbers
    class Q : public Set {
    public:
        template <typename T> bool contains(const T) { return std::is_arithmetic<T>::value; }
        Q() { isinf = true; id = "q"; }
        bool isEmpty() const { return false; }
        std::string toString() const { return "ℚ"; }
        std::string toStringASCII() const { return "Q"; }
        virtual std::unique_ptr<Set> clone() const { return std::make_unique<Q>(*this); }
    private:
        bool _isSubset(const Set&) const { return false; } //...
    };

    // Set of integers
    class Z : public Set {
    public:
        template <typename T> bool contains(const T element) { return std::is_arithmetic<T>::value && std::round(element) == element; }
        Z() { isinf = true; id = "z"; }
        bool isEmpty() const { return false; }
        std::string toString() const { return "ℤ"; }
        std::string toStringASCII() const { return "Z"; }
        virtual std::unique_ptr<Set> clone() const { return std::make_unique<Z>(*this); }
    private:
        bool _isSubset(const Set& set) const { return set.getId() == "q"; }
    };

    // Set of natural numbers without zero
    class N : public Set {
    public:
        template <typename T> bool contains(const T element) { return std::is_arithmetic<T>::value && std::round(element) == element && element > 0; }
        N() { isinf = true; id = "n"; }
        bool isEmpty() const { return false; }
        std::string toString() const { return "ℕ"; }
        std::string toStringASCII() const { return "N"; }
        virtual std::unique_ptr<Set> clone() const { return std::make_unique<N>(*this); }
    private:
        bool _isSubset(const Set& set) const { return set.getId() == "q" || set.getId() == "z" || set.getId() == "n0"; }
    };

    // Set of natural numbers including zero
    class N0 : public Set {
    public:
        template <typename T> bool contains(const T element) { return std::is_arithmetic<T>::value && std::round(element) == element && element >= 0; }
        N0() { isinf = true; id = "n0"; }
        bool isEmpty() const { return false; }
        std::string toString() const { return "ℕ₀"; }
        std::string toStringASCII() const { return "N0"; }
        virtual std::unique_ptr<Set> clone() const { return std::make_unique<N0>(*this); }
    private:
        bool _isSubset(const Set& set) const { return set.getId() == "q" || set.getId() == "z"; }
    };
}