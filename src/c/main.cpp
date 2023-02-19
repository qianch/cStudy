#include <stdio.h>
#include <iostream>
using namespace std;

int main(void) {
	cout << "Hello CMake!" << endl;
	int a, b;
	a = b = 3;
	cout << "a=" << a << " b=" << b << endl;
	if (a = 4)
		cout << "a is equal to 4." << endl;
	else
		cout << "a is not equal to 4." << endl;

	cout << "a=" << a << " b=" << b << endl;
	return 0;
}