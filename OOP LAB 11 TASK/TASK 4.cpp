#include <iostream>

using namespace std;

template<typename T>
class Base {
protected:
    T a, b;
public:
    Base(T x, T y) : a(x), b(y) {}

    T multiply() {
        return a * b;
    }
};

template<typename T>
class Derived : public Base<T> {
    T c, d;
public:
    Derived(T x, T y, T m, T n) : Base<T>(x, y), c(m), d(n) {}

    T multiplyDerived() {
        return c * d;
    }
};

int main() {
    Derived<int> obj(2, 3, 4, 5);
    cout << obj.multiply() << endl;
    cout << obj.multiplyDerived() << endl;
    return 0;
}

