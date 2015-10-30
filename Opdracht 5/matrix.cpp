
#include "matrix.h"
#include "iostream"
#include <memory>
using namespace std;

Matrix::Matrix(int numberOfColumns, int numberOfRows): numberOfRows(numberOfRows), numberOfColumns(numberOfColumns){
	int size = numberOfColumns * numberOfRows;
	contents = new double[size];
	for(int i = 0; i < size; contents[i] = 0, i++);
}

void Matrix::dispose(){
	delete contents;
}
void Matrix::printContents(){
	for(int i = 0; i < numberOfRows; i++) {
		for(int j = 0; j < numberOfColumns; j++) {
			int position = numberOfColumns * i + j;
			if(j == numberOfColumns - 1) {
				cout << contents[position] << endl;
			} else {
				cout << contents[position] << "\t";
			}
		}
	}
	return;
} 	

double Matrix::getElement(int row, int column) {
	return contents[numberOfRows*row+column];
}

void Matrix::setElement(int row, int column, double value) {
	contents[numberOfRows*row+column] = value;
}

Matrix Matrix::operator+(Matrix n) {
	Matrix sumOfMatrices(numberOfColumns, numberOfRows);
	for(int row = 0; row < numberOfRows; row++) {
		for(int column = 0; column < numberOfColumns; column++) {
			double sumOfElements = getElement(row, column) + n.getElement(row, column);
			sumOfMatrices.setElement(row, column, sumOfElements);
		}
	}
	return sumOfMatrices;
}

Matrix Matrix::operator*(Matrix n) {
	Matrix productOfMatrices(numberOfColumns > n.numberOfColumns ? n.numberOfColumns : numberOfColumns, numberOfRows > n.numberOfRows ? n.numberOfRows : numberOfRows);
	for(int row = 0; row < productOfMatrices.numberOfRows; row++) {
		for(int column = 0; column < productOfMatrices.numberOfColumns; column++) {
			double product = 0;
			for(int i = 0,j = 0; i < n.numberOfColumns && j < numberOfRows; j++, i++) {
				product += n.getElement(row, i) * getElement(j, column);
			}
			productOfMatrices.setElement(row, column, product);
		}
	}

	return productOfMatrices;
}














