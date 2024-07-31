#include <iostream>
#include <algorithm>
#include <thread>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include "spdlog/spdlog.h"
#include "spdlog/cfg/env.h"	 // support for loading levels from the environment variable
#include "spdlog/fmt/ostr.h" // support for user defined types
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/stopwatch.h"

// 线程函数
void printMessage()
{
	std::cout << "from thread!" << std::endl;
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

// 自定义一元谓词函数
bool mycomp(int i)
{
	return ((i % 2) == 1);
}

int main()
{
	spdlog::stopwatch sw;
	auto daily_logger = spdlog::daily_logger_mt("daily_logger", "logs/daily.txt", 2, 30);
	daily_logger->info("daily_logger");
	auto basic_logger = spdlog::basic_logger_mt("file_logger", "logs/basic_log.txt", true);
	basic_logger->info("basic_logger");
	auto async_file = spdlog::basic_logger_mt<spdlog::async_factory>("async_file_logger", "logs/async_log.txt");
	async_file->info("async_file");
	spdlog::info("stop_watch: {} seconds", sw);
	// every logger will receive messsage
	spdlog::apply_all([&](std::shared_ptr<spdlog::logger> l)
					  { l->info("apply_all"); });

	std::string s = "hello";
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);
	std::cout << s.c_str() << std::endl;
	// vector
	std::vector<int> numbers = {1, 2, 3, 4, 5};
	// sort
	std::sort(numbers.begin(), numbers.end(), [](int a, int b)
			  { return a > b; });
	// find
	int target = 4;
	auto it = std::find(numbers.begin(), numbers.end(), target);
	if (it != numbers.end())
	{
		std::cout << "find:" << target << ",index:" << std::distance(numbers.begin(), it) << std::endl;
	}

	// after cpp11
	for (int i : numbers)
	{
		std::cout << "after cpp11:" << i << std::endl;
	}

	std::vector<int>::iterator myItem = std::find_if(numbers.begin(), numbers.end(), mycomp);
	std::cout << "myItems:" << *myItem << std::endl;
	std::advance(myItem, 1);
	std::cout << "myItem advance 1:" << *myItem << std::endl;
	std::vector<int>::iterator newIt = std::prev(myItem, 1);
	std::cout << "newItem prev 2:" << *newIt << std::endl;

	// cpp14 Lambda print element
	std::for_each(numbers.begin(), numbers.end(), [](int num)
				  { std::cout << "cpp14 Lambda:" << num << std::endl; });

	std::thread t(printMessage);
	std::cout << "from main thread!" << std::endl;
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
	std::cout << "first:" << first << ",last:" << last << std::endl;
	first = 10;
	last = 20;
	std::cout << lst.front() << " " << lst.back() << std::endl;

	// map容器,默认为less升序,此处设置为greater降序
	std::map<std::string, std::string, std::greater<std::string>> myMap;
	// 调用 emplace() 方法，直接向 myMap 容器中指定位置构造新键值对
	myMap.emplace("A", "1");
	myMap.emplace("B", "2");
	myMap.emplace("C", "3");
	myMap["AA"] = "11";
	// 输出当前 myMap 容器存储键值对的个数
	std::cout << "myMap size==" << myMap.size() << std::endl;
	// 判断当前 myMap 容器是否为空
	if (!myMap.empty())
	{
		// 借助 myMap 容器迭代器，将该容器的键值对逐个输出
		for (auto i = myMap.begin(); i != myMap.end(); ++i)
		{
			spdlog::info("first:{},second:{}", i->first.data(), i->second.data());
		}
	}

	// 创建并初始化一个 unordered_map 容器，其存储的 <string,string> 类型的键值对
	std::unordered_map<std::string, std::string> my_uMap{
		{"D", "4"},
		{"E", "5"},
		{"F", "6"}};
	// 构建要添加的键值对
	std::pair<std::string, std::string> mypair("G", "7");
	// 创建接收 insert() 方法返回值的pair类型变量
	std::pair<std::unordered_map<std::string, std::string>::iterator, bool> ret;
	// 调用 insert() 方法的第一种语法格式
	ret = my_uMap.insert(mypair);
	// 调用 insert() 方法的第二种语法格式
	ret = my_uMap.insert(std::make_pair("H", "8"));
	// 查找指定键对应的值，效率比关联式容器高
	std::string str = my_uMap.at("D");
	std::cout << "str = " << str.data() << std::endl;
	// 使用迭代器遍历哈希容器，效率不如关联式容器
	for (auto iter = my_uMap.begin(); iter != my_uMap.end(); ++iter)
	{
		// pair 类型键值对分为 2 部分
		std::cout << iter->first.data() << " " << iter->second.data() << std::endl;
	}
	std::set<std::string> myset{"a", "b", "c"};
	std::cout << "myset.size:" << myset.size() << std::endl;

	std::vector<std::string> words{"one", "two", "two", "three", "two", "two", "two", "four", "five", "six", "seven", "eight"};
	// replace_copy
	std::vector<std::string> new_words;
	std::replace_copy(std::begin(words), std::end(words), std::back_inserter(new_words), std::string{"one"}, std::string{"0"});
	// adjacent_find 查找 2 个连续相等的元素
	std::vector<std::string>::iterator word = adjacent_find(words.begin(), words.end());
	if (word != words.end())
	{
		std::cout << "same word : " << *word << std::endl;
	}

	// STL unique
	auto end_iter = std::unique(std::begin(words), std::end(words));
	std::copy(std::begin(words), end_iter, std::ostream_iterator<std::string>{std::cout, " "});
	std::cout << std::endl;

	// STL rotate
	auto iter = std::rotate(std::begin(words), std::begin(words) + 3, std::end(words));
	std::copy(std::begin(words), std::end(words), std::ostream_iterator<std::string>{std::cout, " "});
	std::cout << std::endl
			  << "First element before rotation: " << *iter << std::endl;
	// STL move
	std::move(std::begin(words) + 2, std::end(words), std::begin(words));
	return 0;
}