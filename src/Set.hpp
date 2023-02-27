#ifndef SET
    #define SET
    #include <memory>
    #include <string>
    #include <any>

namespace kml {
    class ComplementarySet;
    class Set {
    public:
        friend class ComplementarySet;
        bool isInfinite() const;
        std::string getId() const;
        virtual bool isEmpty() const = 0;
        virtual bool contains(const std::any&) = 0; // { return false; }
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
}

#endif // ifndef SET