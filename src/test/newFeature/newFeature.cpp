#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>

void printMessage();

int main()
{
    auto x = 10;        // 推断x为整数型
    auto str = "hello"; // 推断str为字符串型

    std::vector<int> numbers = {1, 2, 3, 4, 5};

	//排序
	std::sort(numbers.begin(),numbers.end(),[](int a,int b){
		return a > b;
	});

	//查找
	int target = 4;
	auto it = std::find(numbers.begin(), numbers.end(), target);
	if (it != numbers.end()) {
		std::cout << "find:" << target << ",index:" << std::distance(numbers.begin(), it) << std::endl;
	}
	else {
		std::cout << "not find" << target << std::endl;
	}
	// 使用Lambda表达式打印每个元素
	std::for_each(numbers.begin(), numbers.end(), [](int num)
	{
		std::cout << num << std::endl;
	});

    std::thread t(printMessage);
    std::cout << "hello from main thread!" << std::endl;
    t.join();

    return 0;
}

// 线程函数
void printMessage()
{
    std::cout << "hello from thread!" << std::endl;
}