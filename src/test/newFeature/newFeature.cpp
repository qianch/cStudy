#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <array>

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

	//array
	std::array<int, 4> values{};
    //初始化 values 容器为 {0,1,2,3}
    for (int i = 0; i < values.size(); i++) {
        values.at(i) = i;
    }
    //使用 get() 重载函数输出指定位置元素
    std::cout << std::get<3>(values) << std::endl;
    //如果容器不为空，则输出容器中所有的元素
    if (!values.empty()) {
        for (auto val = values.begin(); val < values.end(); val++) {
            std::cout << *val << " ";
        }
    }
	return 0;
}