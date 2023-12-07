#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>

void printMessage();

int main()
{
    auto x = 10;        // 推断x为整数型
    auto str = "Hello"; // 推断str为字符串型

    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (int num : numbers)
    {
        std::cout << num << " ";
    }

    for (auto num : numbers)
    {
        std::cout << num << " ";
    }

    // 使用Lambda表达式打印每个元素
    std::for_each(numbers.begin(), numbers.end(), [](int num)
                  { std::cout << num << " "; });

    std::thread t(printMessage);
    std::cout << "Hello from main thread!" << std::endl;
    t.join();

    return 0;
}

// 线程函数
void printMessage()
{
    std::cout << "Hello from thread!" << std::endl;
}