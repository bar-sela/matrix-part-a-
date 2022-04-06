#ifndef MATRIX_HPP
#define MATRIX_HPP
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;

namespace zich {
    class Matrix {
    private:
        vector<double> _elements;
        int _row;
        int _col;
    public:
        Matrix() {} 
        Matrix(const vector<double> members, int row, int col)
        {
            this->setMatrix(members, row, col);
        }
        bool operator<(const Matrix&);
        bool operator<=(const Matrix&);
        Matrix operator-(const Matrix&);
        Matrix& operator-=(const Matrix&);
        Matrix& operator-();
        bool operator>(const Matrix&);
        bool operator>=(const Matrix&);
        bool operator==(const Matrix&);
        bool operator!=(const Matrix&);
        Matrix& operator++();
        Matrix& operator++(int);
       void setMatrix(const vector<double>& v, int row, int);
        Matrix operator*(const Matrix&);
        Matrix operator*(const double);
        friend Matrix operator*(double, Matrix&);
        friend ostream& operator<<(ostream&, Matrix const&);
        friend istream& operator>>(istream&, Matrix&);
        Matrix operator+(const Matrix&);
        Matrix& operator+=(const Matrix&);
        Matrix& operator+();
        Matrix& operator*=(const Matrix&);
        Matrix& operator*=(const double);
         Matrix& operator--();
        Matrix& operator--(int);
    
    };
}

#endif