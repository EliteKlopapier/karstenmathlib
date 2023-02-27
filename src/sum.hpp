#ifndef SUM_FUNCTION
    #define SUM_FUNCTION
    #include <functional>
    #include <vector>

namespace kml {
    template <typename T>
    T sum(int min, int max, std::function<T(int)> f) {
        T s = 0;
        for(int i = min; i <= max; i++) {
            s += f(i);
        }
        return s;
    }
    template <typename T>
    T sum(std::vector<T> v) {
        std::function<T(int)> f = [v](int i){ return v[i]; };
        return sum(0, (int)v.size(), f);
    }
}

#endif // ifndef SUM_FUNCTION