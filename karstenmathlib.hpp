
//#include <functional>
#include "src/Set.hpp"
#include "src/Intervall.hpp"
#include "src/AntiIntervall.hpp"
#include "src/ComplementarySet.hpp"
#include "src/EmptySet.hpp"
#ifndef UNIVERSALSET 
    #define UNIVERSALSET
    #include "src/UniversalSet.hpp"
#endif
#include "src/N.hpp"
#include "src/N0.hpp"
#include "src/Z.hpp"
#include "src/Q.hpp"



    

    /*class CustomSet : public Set {
    public:
        CustomSet(bool, std::function<bool(int)>, std::function<bool(const Set&)>, std::string = "custom");
        template <typename T> bool contains(const T element) { return false; }
        bool isSubset(const Set&);
    private:
        std::function<bool(int)> containsL;
        std::function<bool(const Set&)> subsetL;
    };*/

    
    