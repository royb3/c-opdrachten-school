#ifndef MATRIX_H
#define MATRIX_H

class Matrix{
	double *contents; 
public:
	int numberOfColumns;
	int numberOfRows;
	Matrix(int, int);
	void dispose();
	void setElement(int, int, double);
	double getElement(int, int);
	void printContents();
	Matrix operator+(Matrix n);
	Matrix operator*(Matrix n);
};

#endif
