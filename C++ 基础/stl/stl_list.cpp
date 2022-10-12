#include <iostream>
#include <list>
using namespace std;


void printList(std::list<int> lls) {
    for (std::list<int>::iterator it = lls.begin(); it != lls.end(); it++)
    {
        std::cout << *it << " " << std::endl;
    }  
}

int main(int argc, char** argv) {
    std::list<int> agesList;
    // 添加元素
    agesList.push_back(1);
    agesList.push_back(2);
    // 在头部位置添加元素
    agesList.push_front(3);
    // 在容器尾部添加元素
    agesList.push_back(4);
    // 打印出：3 1 2 4
    printList(agesList);
    // 弹出最后一个值
    agesList.pop_back();
    // 打印出：3 1 2 
    printList(agesList);
    // 弹出第一个值
    agesList.pop_front();
    // 判断是否为空
    agesList.empty();
    return 0;
}