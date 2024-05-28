#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>

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
	// 推断x为整数型
	auto x = 10;

	std::string s("Hello");
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);
	std::cout << s.c_str() << std::endl;

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
	auto y = [&r = x, x = x + 1]() -> int
	{
		r += 2;
		return x * x;
	}();
	std::cout << "x = " << x << " y = " << y << std::endl;

	// 定义 a 数组，当前数组长度为 0，但和普通数组不同的是，此数组 a 可以根据存储数据的数量自动变长。
	std::vector<int> a;
	// 向数组 a 中添加 10 个元素
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	// 还可以手动调整数组 a 的大小
	a.resize(100);
	a[90] = 100;
	// 还可以直接删除数组 a 中所有的元素，此时 a 的长度变为 0
	a.clear();
	// 重新调整 a 的大小为 20，并存储 20 个 -1 元素。
	a.resize(20, -1);
	return 0;
}