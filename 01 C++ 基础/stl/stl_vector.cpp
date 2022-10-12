#include <iostream>
#include <list>
#include <vector>

using namespace std;


void printValues(std::vector<int> values) {
    for (auto it = values.begin(); it != values.end(); it++) {
        std::cout << *it << " " << std::endl;
    }
}

int main() {
    std::vector<int> values{1, 12, 3, 4, 52, 5};
    std::vector<double> values1(20); // 创建指定大小的 values
    // 在尾部追加元素
    values.push_back(6);
    values.push_back(7);
    printValues(values);
    // 在指定位置添加元素
    values.insert(values.begin(), 100);
    printValues(values);
    return 0;
}