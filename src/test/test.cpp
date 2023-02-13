#include <iostream>
using namespace std;

int previous_number_1(int a);
int previous_number_2(int* a);
int previous_number_3(int& a);

int main() {
	int a = 20;
	int* b = &a;
	int& c = a;
	int d = a;
	c++;
	cout << "a:" << a << endl << "b:" << b << endl << "c:" << c << endl << "d:" << d << endl << endl
		<< "*b:" << *b << endl << "&b:" << &b << endl << "&a:" << &a << endl << "&c:"<< &c << endl << endl;

	int num = 10;
	int&& e = 10;
	++e;
	cout << "num:"<< num << " e:" << e << endl << "&e:" << &e << endl;


	int i = 20;
	int* j = &i;
	int k = previous_number_1(i);
	cout << "i:" << i  << " *j:" << *j  << " k:" << k << endl;

    k = previous_number_2(j);
	cout << "i:" << i << " *j:" << *j << " k:" << k << endl;

	k = previous_number_3(i);
	cout << "i:" << i << " *j:" << *j << " k:" << k << endl;

	return 0;
}

int previous_number_1(int a) {
	return --a;
}

int previous_number_2(int *a) {
	return --(*a);
}

int previous_number_3(int& a) {
	return --a;
}