#include <iostream>
using namespace std;

class Number {
public:
    int value;
    Number(int v) : value(v) {}

    Number& operator--() {
        value *= 4;
        return *this;
    }

    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }

    void display() {
        cout << value << endl;
    }
};
