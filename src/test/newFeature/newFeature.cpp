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

int main()
{
	// 推断x为整数型
	auto x = 10;
	// 推断str为字符串型
	auto str = "hello";
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
		std::cout << "not find" << target << std::endl;
	}
	// 使用Lambda表达式打印每个元素
	std::for_each(numbers.begin(), numbers.end(), [](int num)
				  { std::cout << num << std::endl; });

	std::thread t(printMessage);
	std::cout << "hello from main thread!" << std::endl;
	t.join();
	std::cout << "函数返回类型推导：" << func(4) << std::endl;
	std::cout << "模板函数返回类型推导：" << func(3.4) << std::endl;
	std::cout << "模板函数返回类型推导：" << func("template") << std::endl;
	return 0;
}