#ifndef PRODUCT_FUNCTION
    #define PRODUCT_FUNCTION
    #include <functional>

namespace kml {
    template <typename T>
    T product(int min, int max, std::function<T(int)> f) {
        T p = 1;
        for(int i = min; i <= max; i++) {
            p *= f(i);
        }
        return p;
    }
    template <typename T>
    T product(std::vector<T> v) {
        std::function<T(int)> f = [v](int i){ return v[i]; };
        return product(0, (int)v.size(), f);
    }
}

#endif // ifndef PRODUCT_FUNCTION