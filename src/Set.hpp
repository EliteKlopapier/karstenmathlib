#ifndef SET
    #define SET
    #include <memory>
    #include <string>

namespace kml {
    class ComplementarySet;
    class Set {
    public:
        friend class ComplementarySet;
        bool isInfinite() const;
        std::string getId() const;
        virtual bool isEmpty() const = 0;
        template <typename T> bool contains(const T); // { return false; }
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