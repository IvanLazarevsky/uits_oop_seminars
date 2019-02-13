#include <iostream>
#include <cmath>
#include <assert.h>
using namespace std;
// Самоуправляемость, абстракция данных, инварианты

class Point {
private:
    double x;
    double y;
public:
    Point(double a, double b) : x(a), y(b) {
//        x = a;
//        y = b;
    }

    void print() {
        cout << x << " " << y << endl;
    }

    double getX() {
        return x;
    }

    double getR();

    double getPhi();

    double getY() {
        return y;
    }
};


//class Person {
//public:
//    string getFirstName();
//    string getLastName();
//    int getAge() { return getCurrentYear() - birthYear; }
//private:
//    int birthYear;
//};

enum class Month {
    JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


class Date {
public:
    Month getMonth() { return month; }
    int getDay() { return day; }
    int getYear() { return year; }

    void setDay(int day);
    void setYear(int year);
    void setMonth(Month month);
    void print();

    Date(int day, Month month, int year);
private:
    int day;
    Month month;
    int year;
};

void Date::setDay(int day)
{
    assert(day <= daysInMonth[int(this->month)]);
    this->day = day;
}

void Date::setYear(int year)
{
    assert(year > 0);
    this->year = year;
}

void Date::setMonth(Month month)
{
    assert(this->day <= daysInMonth[int(month)]);
    this->month = month;
}

void Date::print()
{
    cout << day << "-" << int(month) + 1 << "-" << year << "\n";
}

Date::Date(int day, Month month, int year)
{
    this->month = month;
    assert(day >= 1 && day <= daysInMonth[int(month)]);
    assert(year > 0);
    this->day = day;
    this->year = year;
}





//int Person::getAge() {
//    return getCurrentYear() - birthYear;
//}

int main() {
    Date date(31, Month::OCT, 1993);
    date.setMonth(Month::NOV);
    date.print();

    return 0;
}


