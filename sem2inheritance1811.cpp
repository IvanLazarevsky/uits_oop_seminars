#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double getArea() = 0;
};

class Rectangle : public Shape {
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double getArea() override {
        return length * width;
    }
};

class Triangle : public Shape {
    double lengthA;
    double lengthB;
    double lengthC;

public:
    Triangle(double a, double b, double c) : lengthA(a), lengthB(b), lengthC(c) {}
    double getArea() override {
        double hp = lengthA + lengthB + lengthC;
        hp /= 2;

        return sqrt(hp*(hp - lengthA)*(hp-lengthB)*(hp-lengthC));
    }
};


//int main() {
//    Shape* shapes[] = {new Triangle(3, 4, 5), new Rectangle(2,10), new Triangle(6, 8, 10)};

//    for(Shape* shape : shapes) {
//        cout << shape->getArea() << endl;
//    }
//    return 0;
//}
