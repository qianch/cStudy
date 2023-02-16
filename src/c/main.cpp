#include <stdio.h>
#include <iostream>
using namespace std;

int main(void) {
	cout << "Hello CMake!" << endl;
	int a = 1;
	int* b = &a;
	int c = a++;
	int d = ++a;
	cout << "a:" << a << endl;
	cout << "*b:" << *b << endl;
	cout << "c:" << c << endl;
	cout << "d:" << d << endl;
	return 0;
}