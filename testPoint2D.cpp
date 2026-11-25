#include <iostream>
#include "Point2D.h"

using namespace std;

int main() {
	cout << boolalpha;

	Point2D a(0, 0);
	Point2D b(1, 1);

	cout << "a = " << a << "; b = " << b << endl;
	cout << "d(a,b) = " << Point2D::distance(a, b) << endl;
	cout << "a==b --> " << (a == b) << endl;
	cout << "a!=b --> " << (a != b) << endl;
	cout << endl;

	a = b;

	cout << "a = " << a << "; b = " << b << endl;
	cout << "d(a,b) = " << Point2D::distance(a, b) << endl;
	cout << "a==b --> " << (a == b) << endl;
	cout << "a!=b --> " << (a != b) << endl;

	return 0;
}
