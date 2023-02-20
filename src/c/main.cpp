#include <stdio.h>
#include <iostream>
using namespace std;

int abplus(int a, int b);
int(*abplus1)(int a, int b);
int main(void) {
	cout << "Hello CMake!" << endl;
	int a = 1;
	int* b = &a;
	int c = a++;
	int d = ++a;
	abplus1 = abplus;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "*b:" << *b << endl;
	cout << "c:" << c << endl;
	cout << "d:" << d << endl;
	cout << abplus1(a, *b) << endl;
	return 0;
}

int abplus(int a, int b) {
	return a + b;
}