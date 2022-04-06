#include "Matrix.hpp"
#include "Matrix.hpp"
using namespace std;


namespace zich {
	vector<double> a = { 0 };
	Matrix q;

	bool Matrix::operator==(const Matrix&) { return true; }
	bool Matrix::operator!=(const Matrix&) { return true; }
	Matrix Matrix::operator+(const Matrix&) { return q; }
	Matrix& Matrix::operator+=(const Matrix&) { return q; }
	Matrix& Matrix::operator+() { return *this; }
	Matrix Matrix::operator-(const Matrix&) { return q; }
	Matrix& Matrix::operator-=(const Matrix&) { return *this; }
	Matrix& Matrix::operator-() { return *this; }
	bool Matrix::operator>(const Matrix&) { return true; }
	bool Matrix::operator>=(const Matrix&) { return true; }
	bool Matrix::operator<(const Matrix&) { return true; }
	bool Matrix::operator<=(const Matrix&) { return true; }
	Matrix& Matrix::operator++() { return q; }
	Matrix& Matrix::operator++(int) { return q; }
	Matrix& Matrix::operator--() { return q; }
	Matrix& Matrix::operator--(int) { return q; }
	Matrix Matrix::operator*(const Matrix&) { return q; }
	Matrix Matrix::operator*(const double) { return q; }
	Matrix operator*(double, Matrix&) { return q; }
	Matrix& Matrix::operator*=(const Matrix&) { return q; }
	Matrix& Matrix::operator*=(const double) { return q; }
	ostream& operator<<(ostream& os, Matrix const&) { return os; }
	istream& operator>>(istream& is, Matrix&) { return is; }


	void Matrix::setMatrix(const vector<double>& m, int row, int col)
	{
		this->_elements = m;
		this->_row = row;
		this->_col = col;
	}


}