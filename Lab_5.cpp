#include <iostream>

class Hourglass {
private:
    int a;
    int b;

public:
    Hourglass() : a(0), b(0) {}
    Hourglass(int a, int b) : a(a), b(b) {}

    int getA() const { return a; }
    int getB() const { return b; }

    void setA(int a) { this->a = a; }
    void setB(int b) { this->b = b; }

    int calculateArea() const { return a * b; }

    Hourglass operator+(const Hourglass& other) const {
        Hourglass result;
        result.a = this->a + other.a;
        result.b = this->b + other.b;
        return result;
    }

    Hourglass& operator++() {
        ++a;
        ++b;
        return *this;
    }

    Hourglass operator++(int) {
        Hourglass temp = *this;
        ++(*this);
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, const Hourglass& hourglass) {
        os << "a = " << hourglass.a << ", b = " << hourglass.b << ", area = " << hourglass.calculateArea();
        return os;
    }
};

int main() {
    Hourglass h1;
    Hourglass h2(3, 5); 

    std::cout << "Hourglass 1: " << h1 << std::endl;
    std::cout << "Hourglass 2: " << h2 << std::endl;

    h1.setA(2);
    h1.setB(4);
    std::cout << "Hourglass 1 after setting values: " << h1 << std::endl;

    Hourglass h3 = h1 + h2;
    std::cout << "Hourglass 3 (h1 + h2): " << h3 << std::endl;

    ++h1;
    std::cout << "Hourglass 1 after pre-increment: " << h1 << std::endl;

    h2++;
    std::cout << "Hourglass 2 after post-increment: " << h2 << std::endl;

    return 0;
}
