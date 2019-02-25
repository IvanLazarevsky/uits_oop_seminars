#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() override {
        return M_PI * radius * radius;
    }

    double perimeter() override {
        return 2 * M_PI * radius;
    }
};

class Triangle : public Shape {
    double lengthA;
    double lengthB;
    double lengthC;

public:
    Triangle(double a, double b, double c) : lengthA(a), lengthB(b), lengthC(c) {}
    double area() override {
        double hp = lengthA + lengthB + lengthC;
        hp /= 2;

        return sqrt(hp*(hp - lengthA)*(hp-lengthB)*(hp-lengthC));
    }

    double perimeter() override {
        return lengthA + lengthB + lengthC;
    }
};

class Rectangle : public Shape {
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() override {
        return length * width;
    }

    double perimeter() override {
        return width * 2 + length * 2;
    }
};


int main() {
    Shape* shapes[] = { new Circle(2), new Triangle(3,4,5), new Rectangle(10,20)};

    for(Shape *s : shapes) {
        cout << s->perimeter() << " " << s->area() << endl;
    }
    return 0;
}
