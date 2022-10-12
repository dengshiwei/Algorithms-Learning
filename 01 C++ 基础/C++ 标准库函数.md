C++ 标准模板库的核心包括以下三个组件：

| 组件 | 描述 |
| --- | --- |
| 容器（Containers） | 容器是用来管理一类对象的集合。C++ 提供了各种不同类型的容器，比如 deque、queue、list、vector、map、set 等。 |
| 算法（Algorithms） | 算法作用于容器。它们提供了执行各种操作的方式，包括对容器内容执行初始化、排序、搜索和转换等操作。 |
| 迭代器（iterators） | 迭代器用于遍历对象集合的元素。这些集合可能是容器，也可能是容器的子集。 |

关于更多 STL 知识可以参照：[http://c.biancheng.net/stl/stl_basic/](http://c.biancheng.net/stl/stl_basic/)
## 1. 序列式容器
STL 序列式容器是指不会对存储的元素进行排序，元素排列的顺序取决于存储它们的顺序。主要由 array、vector、deque、list 和 forward_list 容器组成。
### 1.1 <list> 容器
STL list 容器又称为双向链表容器，该容器的底层是以双向链表形式存在。这样对于 list 而言就无法像 array、vector 和 deque 支持任意位置的元素访问，只能从第一个开始往下遍历找到指定位置。但是 list 可以实现在任意位置的插入和删除。
list 容器的使用：
```cpp
#include <list>
using namespace std;
```
list 模板类提供的所有成员函数以及各自的功能：

| 成员函数 | 功能 |
| --- | --- |
| begin() | 返回指向容器中第一个元素的双向迭代器。 |
| end() | 返回指向容器中最后一个元素所在位置的下一个位置的双向迭代器。 |
| rbegin() | 返回指向最后一个元素的反向双向迭代器。 |
| rend() | 返回指向第一个元素所在位置前一个位置的反向双向迭代器。 |
| cbegin() | 和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。 |
| cend() | 和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。 |
| crbegin()  | 和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。 |
| crend() | 和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。 |
| empty() | 判断容器中是否有元素，若无元素，则返回 true；反之，返回 false。 |
| size() | 返回当前容器实际包含的元素个数。 |
| max_size() | 返回容器所能包含元素个数的最大值。这通常是一个很大的值，一般是 232-1，所以我们很少会用到这个函数。 |
| front() | 返回第一个元素的引用。 |
| back() | 返回最后一个元素的引用。 |
| assign() | 用新元素替换容器中原有内容。 |
| emplace_front() | 在容器头部生成一个元素。该函数和 push_front() 的功能相同，但效率更高。 |
| push_front() | 在容器头部插入一个元素。 |
| pop_front() | 删除容器头部的一个元素。 |
| emplace_back() | 在容器尾部直接生成一个元素。该函数和 push_back() 的功能相同，但效率更高。 |
| push_back() | 在容器尾部插入一个元素。 |
| pop_back() | 删除容器尾部的一个元素。 |
| emplace() | 在容器中的指定位置插入元素。该函数和 insert() 功能相同，但效率更高。 |
| insert()  | 在容器中的指定位置插入元素。 |
| erase() | 删除容器中一个或某区域内的元素。 |
| swap() | 交换两个容器中的元素，必须保证这两个容器中存储的元素类型是相同的。 |
| resize() | 调整容器的大小。 |
| clear() | 删除容器存储的所有元素。 |
| splice() | 将一个 list 容器中的元素插入到另一个容器的指定位置。 |
| remove(val) | 删除容器中所有等于 val 的元素。 |
| remove_if() | 删除容器中满足条件的元素。 |
| unique() | 删除容器中相邻的重复元素，只保留一个。 |
| merge() | 合并两个事先已排好序的 list 容器，并且合并之后的 list 容器依然是有序的。 |
| sort() | 通过更改容器中元素的位置，将它们进行排序。 |
| reverse() | 反转容器中元素的顺序。 |

使用的示例代码：
```cpp
#include <iostream>
#include <list>
using namespace std;

int main(int argc, char** argv) {
    std::list<int> agesList;
    // 添加元素
    agesList.push_back(1);
    agesList.push_back(2);
    // 在头部位置添加元素
    agesList.push_front(3);
    // 在容器尾部添加元素
    agesList.push_back(4);
    std::cout << "size = " << agesList.size() <<std::endl;

    for (std::list<int>::iterator it = agesList.begin(); it != agesList.end(); it++)
    {
        std::cout << *it << " " << std::endl;
    }    
}
```
### 1.2 <array> 容器
array 容器是 C++ 11 标准中新增的序列容器，简单地理解，它就是在 C++ 普通数组的基础上，添加了一些成员函数和全局函数。
依赖的头文件：
```cpp
#include "array"

using namespace std;
```
使用示例比较简单：
```cpp
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

```
在 array 容器中，访问容器中的元素，可通过 [index] 或 at(index) 指定下标访问。
### 1.3 <vector> 容器
vector 容器是 STL 中最常用的容器之一，它和 array 容器非常类似，都可以看做是对 C++ 普通数组的“升级版”。不同之处在于，array 实现的是静态数组（容量固定的数组），而 vector 实现的是一个动态数组，即可以进行元素的插入和删除，在此过程中，vector 会动态调整所占用的内存空间，整个过程无需人工干预。
vector 常被称为向量容器，因为该容器擅长在尾部插入或删除元素，在常量时间内就可以完成，时间复杂度为O(1)；而对于在容器头部或者中部插入或删除元素，则花费时间要长一些（移动元素需要耗费时间），时间复杂度为线性阶O(n)。
**创建 vector 容器**


**vector 常用方法**

| 函数成员 | 函数功能 |
| --- | --- |
| begin() | 返回指向容器中第一个元素的迭代器。 |
| end() | 返回指向容器最后一个元素所在位置后一个位置的迭代器，通常和 begin() 结合使用。 |
| rend() | 返回指向第一个元素所在位置前一个位置的迭代器。 |
| cbegin() | 和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。 |
| size() | 返回实际元素个数。 |
| max_size() | 返回元素个数的最大值。这通常是一个很大的值，一般是 232-1，所以我们很少会用到这个函数。 |
| capacity() | 返回当前容量。 |
| empty() | 判断容器中是否有元素，若无元素，则返回 true；反之，返回 false。 |
| reserve() | 增加容器的容量。 |
| at() | 使用经过边界检查的索引访问元素。 |
| front() | 返回第一个元素的引用。 |
| back() | 返回最后一个元素的引用。 |
| data() | 返回指向容器中第一个元素的指针。 |
| push_back() | 在序列的尾部添加一个元素。 |
| pop_back() | 移出序列尾部的元素。 |
| insert() | 在指定的位置插入一个或多个元素。 |
| erase() | 移出一个元素或一段元素。 |
| clear() | 移出所有的元素，容器大小变为 0。 |
| swap() | 交换两个容器的所有元素。 |
| emplace() | 在指定的位置直接生成一个元素。 |
| emplace_back() | 在序列尾部生成一个元素。 |

示例代码：
```cpp
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
```
## 2. 关联式容器
使用关联式容器存储的元素，都是一个一个的“键值对”（ <key,value> ），这是和序列式容器最大的不同。除此之外，序列式容器中存储的元素默认都是未经过排序的，而使用关联式容器存储的元素，默认会根据各元素的键值的大小做升序排序。
C++ STL 标准库提供了 4 种关联式容器，分别为 map、set、multimap、multiset。

| 关联式容器名称 | 特点 |
| --- | --- |
| map | 定义在 <map> 头文件中，使用该容器存储的数据，其各个元素的键必须是唯一的（即不能重复），该容器会根据各元素键的大小，默认进行升序排序（调用 std::less<T>）。 |
| set | 定义在 <set> 头文件中，使用该容器存储的数据，各个元素键和值完全相同，且各个元素的值不能重复（保证了各元素键的唯一性）。该容器会自动根据各个元素的键（其实也就是元素值）的大小进行升序排序（调用 std::less<T>）。 |
| multimap | 定义在 <map> 头文件中，和 map 容器唯一的不同在于，multimap 容器中存储元素的键可以重复。 |
| multiset | 定义在 <set> 头文件中，和 set 容器唯一的不同在于，multiset 容器中存储元素的值可以重复（一旦值重复，则意味着键也是重复的）。 |

### 2.1 <map> 容器
map 容器存储的都是 pair 对象，也就是用 pair 类模板创建的键值对。在使用 map 容器存储多个键值对时，该容器会自动根据各键值对的键的大小，按照既定的规则进行排序。
**常见方案**

| 成员方法 | 功能 |
| --- | --- |
| begin() | 返回指向容器中第一个（注意，是已排好序的第一个）键值对的双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。 |
| end() | 返回指向容器最后一个元素（注意，是已排好序的最后一个）所在位置后一个位置的双向迭代器，通常和 begin() 结合使用。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。 |
| rbegin() | 返回指向最后一个（注意，是已排好序的最后一个）元素的反向双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。 |
| rend() | 返回指向第一个（注意，是已排好序的第一个）元素所在位置前一个位置的反向双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。 |
| cbegin() | 和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。 |
| cend() | 和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。 |
| crbegin() | 和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。 |
| crend() | 和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。 |
| find(key) | 在 map 容器中查找键为 key 的键值对，如果成功找到，则返回指向该键值对的双向迭代器；反之，则返回和 end() 方法一样的迭代器。另外，如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。 |
| lower_bound(key) | 返回一个指向当前 map 容器中第一个大于或等于 key 的键值对的双向迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。 |
| upper_bound(key) | 返回一个指向当前 map 容器中第一个大于 key 的键值对的迭代器。如果 map 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。 |
| equal_range(key) | 该方法返回一个 pair 对象（包含 2 个双向迭代器），其中 pair.first 和 lower_bound() 方法的返回值等价，pair.second 和 upper_bound() 方法的返回值等价。也就是说，该方法将返回一个范围，该范围中包含的键为 key 的键值对（map 容器键值对唯一，因此该范围最多包含一个键值对）。 |
| empty()  | 若容器为空，则返回 true；否则 false。 |
| size() | 返回当前 map 容器中存有键值对的个数。 |
| max_size() | 返回 map 容器所能容纳键值对的最大个数，不同的操作系统，其返回值亦不相同。 |
| operator[] | map容器重载了 [] 运算符，只要知道 map 容器中某个键值对的键的值，就可以向获取数组中元素那样，通过键直接获取对应的值。 |
| at(key) | 找到 map 容器中 key 键对应的值，如果找不到，该函数会引发 out_of_range 异常。 |
| insert() | 向 map 容器中插入键值对。 |
| erase() | 删除 map 容器指定位置、指定键（key）值或者指定区域内的键值对。后续章节还会对该方法做重点讲解。 |
| swap() | 交换 2 个 map 容器中存储的键值对，这意味着，操作的 2 个键值对的类型必须相同。 |
| clear() | 清空 map 容器中所有的键值对，即使 map 容器的 size() 为 0。 |
| emplace() | 在当前 map 容器中的指定位置处构造新键值对。其效果和插入键值对一样，但效率更高。 |
| emplace_hint() | 在本质上和 emplace() 在 map 容器中构造新键值对的方式是一样的，不同之处在于，使用者必须为该方法提供一个指示键值对生成位置的迭代器，并作为该方法的第一个参数。 |
| count(key) | 在当前 map 容器中，查找键为 key 的键值对的个数并返回。注意，由于 map 容器中各键值对的键的值是唯一的，因此该函数的返回值最大为 1。 |

示例代码：
```cpp
int main() {
    std::map<int, int> maps;
    maps[1] = 1;
    maps[2] = 2;
    for (auto val = maps.begin(); val != maps.end(); val++) {
        std::cout << "key = " << val->first << ",value = " << val->second << std::endl;
    }
    return 0;
}
```
### 2.2 <set> 容器
使用 set 容器存储的各个键值对，要求键 key 和值 value 必须相等。
**set 定义**
```cpp
std::set<std::string> myset;
```
