﻿#include <iostream>
#include <algorithm>
#include <thread>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <map>

// 线程函数
void printMessage()
{
	std::cout << "hello from thread!" << std::endl;
}
// 函数返回类型推导
auto func(int i)
{
	return i;
}
// 模板支持返回值类型推导
template <typename T>
auto func(T t)
{
	return t;
}

// lambda类型推导
auto f = [](auto a)
{
	return a;
};

int main()
{
	std::string s = "Hello";
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);
	std::cout << s.c_str() << std::endl;
	// vector 动态数组
	std::vector<int> numbers = {1, 2, 3, 4, 5};
	// 排序
	std::sort(numbers.begin(), numbers.end(), [](int a, int b)
			  { return a > b; });
	// 查找
	int target = 4;
	auto it = std::find(numbers.begin(), numbers.end(), target);
	if (it != numbers.end())
	{
		std::cout << "find:" << target << ",index:" << std::distance(numbers.begin(), it) << std::endl;
	}
	else
	{
		std::cout << "not find:" << target << std::endl;
	}

	// before c++11
	for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
	{
		std::cout << "before cpp 11:" << *iter << std::endl;
	}

	// cpp11基于范围的for循环
	for (int i : numbers)
	{
		std::cout << "cpp11基于范围的for循环:" << i << std::endl;
	}

	// cpp14基于Lambda表达式打印每个元素
	std::for_each(numbers.begin(), numbers.end(), [](int num)
				  { std::cout << "cpp14 Lambda表达式:" << num << std::endl; });

	std::thread t(printMessage);
	std::cout << "hello from main thread!" << std::endl;
	t.join();
	std::cout << "函数返回类型推导：" << func(4) << std::endl;
	std::cout << "模板函数返回类型推导：" << func(3.4) << std::endl;
	std::cout << "模板函数返回类型推导：" << func("template") << std::endl;
	std::cout << "模板函数返回类型推导：" << func(1) << std::endl;
	// 对捕获的变量和引用进行初始化
	auto x = 0;
	auto y = [&r = x, x = x + 1]() -> int
	{
		r += 2;
		return x * x;
	}();
	std::cout << "x = " << x << " y = " << y << std::endl;

	// array 静态数组
	std::array<int, 4> values{};
	// 初始化 values 容器为 {0,1,2,3}
	for (unsigned int i = 0; i < values.size(); i++)
	{
		values.at(i) = i;
	}
	// 使用 get() 重载函数输出指定位置元素
	std::cout << std::get<3>(values) << std::endl;
	// 如果容器不为空，则输出容器中所有的元素
	if (!values.empty())
	{
		for (auto val = values.begin(); val < values.end(); val++)
		{
			std::cout << *val << " ";
		}
	}

	// deque容器
	std::deque<int> d(10, 5);
	// 使用迭代器遍历容器
	for (auto i = d.begin(); i < d.end(); i++)
	{
		std::cout << *i << " ";
	}

	// list容器
	std::list<int> lst{1, 2, 3, 4};
	int &first = lst.front();
	int &last = lst.back();
	std::cout << first << " " << last << std::endl;
	first = 10;
	last = 20;
	std::cout << lst.front() << " " << lst.back() << std::endl;

	// map容器,默认为less升序,此处设置为greater降序
	std::map<std::string, std::string, std::greater<std::string>> myMap;
	// 调用 emplace() 方法，直接向 myMap 容器中指定位置构造新键值对
	myMap.emplace("A", "1");
	myMap.emplace("B", "2");
	myMap.emplace("C", "3");
	// 输出当前 myMap 容器存储键值对的个数
	std::cout << "myMap size==" << myMap.size() << std::endl;
	// 判断当前 myMap 容器是否为空
	if (!myMap.empty())
	{
		// 借助 myMap 容器迭代器，将该容器的键值对逐个输出
		for (auto i = myMap.begin(); i != myMap.end(); ++i)
		{
			std::cout << i->first.data() << " " << i->second.data() << std::endl;
		}
	}
	return 0;
}