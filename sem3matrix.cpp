#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// b = a; Matrix b = a + c;

struct MatrixException {
    string message;
    MatrixException(const string& s) : message(s) {}
};

struct IncompatibleDimsException : public MatrixException {
    using MatrixException::MatrixException;
};

struct OutOfRange : public MatrixException {
    using MatrixException::MatrixException;
};

class Matrix {
    size_t N;
    size_t M;
    size_t size_;
    double* data;

    void checkBounds(size_t i, size_t j) const {
        if(i >= N || j >= M)
            throw OutOfRange{"Out of range " + to_string(i) + " " + to_string(j)};
    }
public:
    Matrix(size_t rows, size_t columns) : N(rows), M(columns), size_(N*M) {
        data = new double[size_];
        std::fill(data, data + size_, 0);
        //        for(size_t i = 0; i < size_; ++i)
        //            data[i] = 0;
    }

    Matrix(const Matrix& other) : N(other.N), M(other.M), size_(other.size_) {
        data = new double[size_];
        std::copy(other.data, other.data + other.size_, this->data);
    }

    void operator=(const Matrix& other) {
        delete [] data;
        N = other.N;
        M = other.M;
        size_ = other.size_;
        data = new double[size_];
        std::copy(other.data, other.data + other.size_, this->data);
    }

    size_t getRows() const { return N; }
    size_t getColumns() const { return M; }

    double& operator()(size_t i, size_t j) {
        checkBounds(i,j);
        return data[i * M + j];
    }

    double operator()(size_t i, size_t j) const {
        checkBounds(i,j);
        return data[i * M + j];
    }

    Matrix operator-() const {
        Matrix m(N,M);
        for(size_t i = 0; i < size_; ++i) {
            m.data[i] = -data[i];
        }
        return m;
    }

    friend Matrix operator+(const Matrix& a, const Matrix& b);

    ~Matrix() {
        delete [] data;
    }
};

Matrix operator+(const Matrix& a, const Matrix& b) {
    if(a.getRows() == b.getRows() && a.getColumns() == b.getColumns()) {
        Matrix res(a.getRows(), b.getColumns());
        for(size_t i = 0; i < a.size_; ++i)
            res.data[i] = a.data[i] + b.data[i];

       return res;
    }
    else
        throw IncompatibleDimsException{"Invalid dims for +"};
}


void printMatrix(const Matrix& m) {
    for(size_t i = 0; i < m.getRows(); ++i) {
        for(size_t j = 0; j < m.getColumns(); ++j) {
            cout << m(i,j) << " ";
        }
        cout << endl;
    }
}

template<class T>  bool in(T a, T b, T c) {
    return a >= b && a <= c;
}

int main()
{
    cout << in("hello", "file", "iron") << endl;

    return 0;
}
