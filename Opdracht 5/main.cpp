#include "matrix.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	Matrix m(3, 3);
	m.setElement(1, 1, 1.0);
	m.setElement(2, 1, 1.0);
	Matrix n(3, 3);
	n.setElement(1, 1, 2.0);
	n.setElement(1, 2, 2.0);
	Matrix y = m * n;
	cout << "M" << endl;
	m.printContents();
	cout << "N" << endl;
	n.printContents();
	cout << "M * N" << endl;
	y.printContents();
	m.dispose();
	n.dispose();
	y.dispose();
	return 0;
}


