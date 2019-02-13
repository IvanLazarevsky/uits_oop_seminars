#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cassert>
#include <fstream>
using namespace std;

int currentYear = 2019;

class String {
public:
    String operator+(const String& other) const {
        String res("");
        res += *this;
        res += other;
        return res;
    }
    // INVARIANT
    char get(int index) const {
        assert(index >= 0 && index < size_);
        return buffer_[index];
    };

    void print() const {
        cout << buffer_ << endl;
    }

    int size() const { return size_; }

    String& operator+=(const String& other) {
        char* new_buf = new char[size() + other.size() + 1];
        for(int i = 0; i < size_; ++i) {
            new_buf[i] = this->get(i);
        }

        for(int i = 0; i < other.size(); ++i) {
            new_buf[size_ + i] = other.get(i);
        }

        int new_size = size() + other.size();
        new_buf[new_size + 1] = '\0';

        size_ = new_size;
        delete [] buffer_;
        buffer_ = new_buf;

        return *this;
    }

    // RULE OF THREE
    explicit String(const char* str) {
        size_ = strlen(str);
        buffer_ = new char[size_ + 1];
        strcpy(buffer_, str);
    }

    // Initializer list
    String(const String& other) : buffer_(new char[other.size() + 1]), size_(other.size()) {
        size_ = other.size();
        buffer_ = new char[size_+1];
        strcpy(buffer_, other.buffer_);
    }

    String& operator=(const String& other) {
        delete [] buffer_;
        size_ = other.size();
        buffer_ = new char[size_+1];
        strcpy(buffer_, other.buffer_);
        return *this;
    }

    ~String() {
        delete [] buffer_;
    }

private:
    char* buffer_;
    int size_;
};

class Person {
    string firstName;
    string lastName;

public:
    Person(const string &firstName, const string &lastName) : firstName(firstName), lastName(lastName) {
        this->firstName = firstName;
    }
};

//int main()
//{
//    ifstream infile("fdfd");

//    return 0;
//}
