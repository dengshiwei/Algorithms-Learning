//
// Created by 邓士伟 on 2022/10/12.
//

#include "array"
#include "iostream"

using namespace std;

int main() {
    std::array<int, 4> values{};
    // 初始化数组赋值
    for (int i = 0; i < values.size(); i++) {
        values.at(i) = i;
    }

    values.size();  // 大小
    values.empty(); // 是否为空
    values.begin(); // iterator 遍历
    for (auto val = values.begin(); val != values.end(); val++) {
        std::cout << *val << " " << std::endl;
    }
    return 0;
}
