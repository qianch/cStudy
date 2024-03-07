#include <iostream>
using namespace std;
void change1(int n);
void change2(int &n);
void change3(int *n);

struct Student
{
	string name;
	int age;
};

void printStudent1(Student s);
void printStudent2(Student *s);


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

	Student s = { "张三",12 };
	printStudent1(s);
	cout << "源结构体的变量：" << "姓名：" << s.name.data() << "年龄：" << s.age << endl;

	printStudent2(&s);
	cout << "源结构体的变量：" << "姓名：" << s.name.data() << "年龄：" << s.age << endl;

	Student * s2 = new Student();
	s2->name = "王五";
	s2->age = 10;
	printStudent2(s2);
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
	cout << "采用值传递的方式：" << "姓名：" << s.name.data() << "年龄：" << s.age << endl;
}

void printStudent2(Student* s)
{
	s->age = 18;
	cout << "采用值传递的方式：" << "姓名：" << s->name.data() << "年龄：" << s->age << endl;
}