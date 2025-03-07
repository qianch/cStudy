﻿#include <iostream>
using namespace std;
void change1(int n);
void change2(int &n);
void change3(int *n);

struct Student
{
	string name;
	int age;
};

class cStudent
{
public:
	string name;
	int age;
	cStudent();
	~cStudent();

private:

};

cStudent::cStudent()
{
}

cStudent::~cStudent()
{
}

void printStudent1(Student s);
void printStudent2(Student &s);
void printStudent3(Student *s);
void change(cStudent cs);

int main()
{
	int n = 10;
	cout << "实参的地址" << &n << endl;
	change1(n);
	cout << "after change1() n=" << n << endl;
	change2(n);
	cout << "after change2() n=" << n << endl;
	int* m = &n;
	cout << m << endl;
	change3(&n);
	cout << "after change3() n=" << n << endl;

	Student s1 = { "张三",12 };
	printStudent1(s1);
	cout << "源结构体的变量：" << "姓名：" << s1.name.data() << "年龄：" << s1.age << endl;

	Student s2 = { "张三",12 };
	printStudent2(s2);
	cout << "源结构体的变量：" << "姓名：" << s2.name.data() << "年龄：" << s2.age << endl;

	Student s3 = { "张三",12 };
	printStudent3(&s3);
	cout << "源结构体的变量：" << "姓名：" << s3.name.data() << "年龄：" << s3.age << endl;

	Student * s4 = new Student();
	s4->name = "王五";
	s4->age = 10;
	printStudent3(s4);
	cout << "源结构体的变量：" << "姓名：" << s4->name.data() << "年龄：" << s4->age << endl;

	cStudent cs;
	cs.name = "AA";
	cs.age = 22;
	change(cs);
	cout << "cs：" << "姓名：" << cs.name.data() << "年龄：" << cs.age << endl;

	return true;
}

// 值传递
void change1(int n)
{
	// 显示的是拷贝的地址而不是源地址
	cout << "值传递--函数操作地址" << &n << endl;
	n++;
}

// 引用传递
void change2(int &n)
{
	n = 20;
	cout << "引用传递--函数操作地址" << &n << endl;
	n++;
}
// 指针传递
void change3(int *n)
{
	cout << "指针传递--函数操作地址 " << n << endl;
	*n = *n + 1;
}

void printStudent1(Student s)
{
	s.age = 18;
	s = { "张三三",22 };
	cout << "采用值传递的方式：" << "姓名：" << s.name.data() << "年龄：" << s.age << endl;
}

void printStudent2(Student& s)
{
	s.age = 18;
	cout << "采用引用传递的方式：" << "姓名：" << s.name.data() << "年龄：" << s.age << endl;
}

void printStudent3(Student* s)
{
	s->age = 18;
	cout << "采用指针传递的方式：" << "姓名：" << s->name.data() << "年龄：" << s->age << endl;
}

void change(cStudent cs) 
{
	cStudent cs1;
	cs1.name = "BB";
	cs1.age = 33;
	cs = cs1;
	cout << "cStudent：" << "姓名：" << cs.name.data() << "年龄：" << cs.age << endl;
};