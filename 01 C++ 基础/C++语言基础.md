## 1. 变量和基本类型
C++定义了一套包括算术类型（arithmetic type）和空类型（void）在内的基本数据类型。
### 1.1 算术类型
算术类型分为整形和浮点型。算术类型的尺寸（也就是该类型数据所占的比特数）在不同机器上有所差别。
![image.png](https://cdn.nlark.com/yuque/0/2022/png/362266/1653314959137-b5a4f70e-2c83-4c4b-af46-5b2633be352b.png#clientId=u628359cc-71ac-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=554&id=ub3cb7aa8&margin=%5Bobject%20Object%5D&name=image.png&originHeight=1108&originWidth=1990&originalType=binary&ratio=1&rotation=0&showTitle=false&size=517743&status=done&style=none&taskId=u587b03dd-83f9-4db5-b453-3f9f4c33776&title=&width=995)
布尔类型（bool）的取值是真（true）或假（false）。
char 的空间应确保可以存放机器基本字符集中任意字符对应的数字值。除去布尔型和扩展的字符型之外，其他整型可以划分为带符号的（signed）和无符号的（unsigned）两种。带符号类型可以表示正数、负数或0，无符号类型则仅能表示大于等于0的值。
类型 int、short、long 和 long long 都是带符号的，通过在这些类型名前添加 unsigned 就可以得到无符号类型，例如 unsigned long。类型 unsigned int 可以缩写为 unsigned。
**如何选择数据类型**

- 当明确知晓数值不可能为负时，选用无符号类型
- 使用 int 执行整数运算
- 使用int执行整数运算
- 执行浮点数运算选用double，这是因为float通常精度不够而且双精度浮点数和单精度浮点数的计算代价相差无几。
### 1.2 类型转换
当在程序的某处我们使用了一种类型而其实对象应该取另一种类型时，程序会自动进行类型转换。
```cpp
int main()
{
    bool b = 46;
    int i = b;
    i = 3.14;
    double pi = i;
    unsigned char c = -1;
    std::cout<<"b = " << b << std::endl;
    std::cout<<"i = " << i << std::endl;
    std::cout<<"pi = " << pi << std::endl;
    std::cout<<"c = " << c << std::endl;
    return 0;
}
// 输出结果
Hello.cpp:7:9: warning: implicit conversion from 'double' to 'int' changes value from 3.14 to 3 [-Wliteral-conversion]
    i = 3.14;
      ~ ^~~~
1 warning generated.
b = 1
i = 3
pi = 3
c = �
```
类型所能表示的值的范围决定了转换的过程：

- 当我们把一个非布尔类型的算术值赋给布尔类型时，初始值为0则结果为false，否则结果为true。
- 当我们把一个布尔值赋给非布尔类型时，初始值为false则结果为0，初始值为true则结果为1。
- 当我们把一个浮点数赋给整数类型时，进行了近似处理。结果值将仅保留浮点数中小数点之前的部分。
- 当我们把一个整数值赋给浮点类型时，小数部分记为0。如果该整数所占的空间超过了浮点类型的容量，精度可能有损失。
- 当我们赋给无符号类型一个超出它表示范围的值时，结果是初始值对无符号类型表示数值总数取模后的余数。例如，8比特大小的unsigned char可以表示0至255区间内的值，如果我们赋了一个区间以外的值，则实际的结果是该值对256取模后所得的余数。因此，把-1赋给8比特大小的unsigned char所得的结果是255。
-  当我们赋给带符号类型一个超出它表示范围的值时，结果是未定义的（undefined）。此时，程序可能继续工作、可能崩溃，也可能生成垃圾数据。

当从无符号数中减去一个值时，不管这个值是不是无符号数，我们都必须确保结果不能是一个负值。**即保证运算结束后数据类型符合定义。**
```cpp
for (size_t i = 10; i >= 0; i--)
{
    std::cout<<"i = " << i << std::endl;
}
```
来看看当u等于0时发生了什么，这次迭代输出0，然后继续执行for语句里的表达式。表达式--u从u当中减去1，得到的结果-1并不满足无符号数的要求，此时像所有表示范围之外的其他数字一样，-1被自动地转换成一个合法的无符号数。假设int类型占32位，则当u等于0时，--u的结果将会是4294967295。
字面值'A'表示的就是单独的字符A，而字符串"A"则代表了一个字符的数组，该数组包含两个字符：一个是字母A、另一个是空字符。
### 1.2 变量
C++中的每个变量都有其数据类型，数据类型决定着变量所占内存空间的大小和布局方式、该空间能存储的值的范围，以及变量能参与的运算。C++中的每个变量都有其数据类型，数据类型决定着变量所占内存空间的大小和布局方式、该空间能存储的值的范围，以及变量能参与的运算。
在对象创建时获取一个特定的值，我们称之为对象被初始化。
> C++中的每个变量都有其数据类型，数据类型决定着变量所占内存空间的大小和布局方式、该空间能存储的值的范围，以及变量能参与的运算。

注意：未初始化的变量含有一个不确定的值，使用未初始化变量的值是一种错误的编程行为并且很难调试。
#### 变量的声明和定义
为了允许把程序拆分成多个逻辑部分来编写，C++语言支持分离式编译（separatecompilation）机制，该机制允许将程序分割为若干个文件，每个文件可被独立编译。
为了支持分离式编译，C++ 语言将声明和定义区分开来。声明（declaration）使得名字为程序所知，一个文件如果想使用别处定义的名字则必须包含对那个名字的声明。而定义（definition）负责创建与名字关联的实体。
为了支持分离式编译，C++语言将声明和定义区分开来。声明（declaration）使得名字为程序所知，一个文件如果想使用别处定义的名字则必须包含对那个名字的声明。而定义（definition）负责创建与名字关联的实体。如果想声明一个变量而非定义它，就在变量名前添加关键字extern，而且不要显式地初始化变量：
```cpp
   extern int i;	// 声明 i
   int j;		// 声明并定义 j
```
任何包含了显式初始化的声明即成为定义。
#### 复合类型
符合类型是指基于其他类型定义的类型。 本节介绍：引用和指针。
**引用**
为对象起了另外一个名字，引用类型引用另外定义一种类型。定义引用需要在变量前添加 &。
```cpp
int main()
{
    int i = 42;
    int &j = i;
    int value = i;
    i = 100;
    std::cout << i << "," << j << "," << value << std::endl;
    return 0;
}
// 输出结果：100,100,42
```
一般初始化变量时，初始值会被拷贝到新建的对象中。定义引用时，程序把引用和初始值绑在一起，而不是将初始值拷贝给应用。定义了一个引用之后，对其进行的所有操作都是在与之绑定的对象上进行的。
**指针**
指针是指向另外一种符合类型。这点与引用类型相似，但是也有不同的地方：

- 指针本身是一个对象，允许对指针赋值和拷贝。同时在指针生命周期内指针可以指向不同的对象；
- 指针无需在定义时赋初值，和其它内置类型一样，如果没有被初始化，将得到一个不确定的值。

指针的定义格式：`*d`其中 d 是变量名，* 定义为一个指针。指针存放对象的地址，要想获取地址使用操作符：&。
```cpp
int main()
{
    int i = 42;
    int *p = &i;    // p 存放变量 i 的地址，或者说 p 是指向 i 的指针，*p 标识对应的值
    std::cout << i << "," << *p << std::endl;
    return 0;
}
```
指针的四种状态：

- 指向一个对象；
- 指向紧邻对象所占用空间的下一个位置；
- 空指针，没有指向任何对象；
- 无效指针，上述情况的其他值；

![image.png](https://cdn.nlark.com/yuque/0/2022/png/362266/1653401143127-9d0a93b7-fee2-41f0-8498-453fdc720ea8.png#clientId=u832429af-4d4e-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=192&id=ufc3c3ddc&margin=%5Bobject%20Object%5D&name=image.png&originHeight=384&originWidth=1714&originalType=binary&ratio=1&rotation=0&showTitle=false&size=353945&status=done&style=none&taskId=u4958b030-77a8-445d-a48c-62b6d5461b2&title=&width=857)
![image.png](https://cdn.nlark.com/yuque/0/2022/png/362266/1653401389419-e9bcc47b-8c83-4713-8b7a-8388ff4d48c6.png#clientId=u832429af-4d4e-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=151&id=uefc78319&margin=%5Bobject%20Object%5D&name=image.png&originHeight=302&originWidth=1806&originalType=binary&ratio=1&rotation=0&showTitle=false&size=112323&status=done&style=none&taskId=u8ca81297-de68-41a7-9a8f-4314e84aed8&title=&width=903)
**const 定义常量**
```cpp
const int i = 42;
```
### 1.3 类型别名
类型别名是某种类型的同义词，用于复杂的类型变得简单、方便使用。定义关键字 `typedef`
```cpp
typedef double wage;	// wage 是 double 的同义词
```
### 1.4 自定义数据结构
定义自定义数据结构使用 `struct`关键字。
```cpp
struct Student {
    std::string name;
    double grade;
    int age;
};
```
### 1.5 常见术语

- #define是一条预处理指令，用于定义一个预处理变量。
- #endif是一条预处理指令，用于结束一个#ifdef或#ifndef区域。
- #ifdef是一条预处理指令，用于判断给定的变量是否已经定义。
- #ifndef是一条预处理指令，用于判断给定的变量是否尚未定义。
## 2. 字符串、向量和数组
### 2.1 标准库函数 string
#### 命名空间 using 声明
通过 `using`可以方便引入命名控件，格式：using namespace::name;
```cpp
using std::cin;
int main()
{
    std::string s1 = "hello";
    cin >> s1;
    std::cout << s1 <<std::endl;
    return 0;
}
```
### 2.2 标准库函数 vector
标准库类型 vector 表示对象的集合，其中所有对象的类型都相同。集合中的每个对象都有一个与之对应的索引，索引用于访问对象。
使用 vector 需要引入对应的头文件。`#inclue <vector>`
```cpp
#include <iostream>
#include <vector>
using std::vector;
using std::string;

int main()
{
    vector<string> aritcal = {"a", "b"};
    
    //方法二，使用迭代器将容器中数据输出 
    vector<int>::iterator it;//声明一个迭代器，来访问vector容器，作用：遍历或者指向vector容器的元素 
    for(it=obj.begin();it!=obj.end();it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}
```
基本函数实现：

- vector()：创建一个空的 vector
- vector(int size)：创建一个元素格式为 size 的 vector
- void push_back(x)：尾部增加一个元素 x
- iterator insert(iterator it, const x)：向量中迭代器前增加一个元素 x
- iterator erase(iterator it)：删除向量中的指定元素
- clear：清空当前向量
### 2.3 数组
数组与 `vector`类似，但是又不同。相似的地方是都是用来存放类型相同的对象容器。不同的是数组大小确定不变，不能随意向数组中增加元素。
数组的定义格式：`a[d]`，其中 `a`是数组名，d 是数组的维度大小。
```cpp
int arr[10];
```

- 不允许把数组直接拷贝给其它数组作为原始值，不能用于赋值；
- 数组大小不能修改
- 数组元素的访问从索引 0 开始

**数组与指针**
在 C++ 中使用数组的时候编译器一般会把它转换成指针。通常使用取地址符来获取指向一个对象的指针。
```cpp
int main()
{
    int *arr[10];   // arr 是含有 10 个整形指针的数组
    int (*pArray)[10];  //pArray 是指向一个含有 10 个整数的数组
    arr[0] = 1;     // 错误，运行时报错：error: incompatible integer to pointer conversion assigning to 'int *' from 'int'
    *pArray[0] = 1; // 正确
    
    string numbers[] = {"one","two","three"};
    string *p = &numbers[0];    // p 是指向 numbers 的第一个数组
    string *p2 = numbers;   // 等价于 *p2 = &numbers[0]
    return 0;
}
```
**使用 new 关键字创建动态数组**
```cpp
int *arr = new int[10];
```
## 3. 运算符与语句
基本的算术运算符和逻辑运算符就不做过多介绍，这里介绍相比于其它开发语言而言特殊的运算符。
### 3.1 成员访问运算符
点运算符和箭头运算符都可以用于访问成员变量。示例如下：
```cpp
int main()
{
    string s1 = "helloworld", *p = &s1;
    auto n = s1.size();
    int n1 = (*p).size();       // 运行指针 p 指向对象的 size 方法
    int n2 = p->size();     // 等同于 (*p).size()
    std::cout << n << "," << n1 << "," << n2 << std::endl;
    return 0;
}
```
### 3.2 函数与指针
指向函数的指针成为函数指针。函数在程序编译时被分配一个入口地址，这个函数的入口地址就被称为函数的指针。通常函数指针的用途是把指针作为参数传递到其它函数，用来作为函数的传导。
```cpp
int txt_size(int x, int y) {
    return x + y;
}

int main(int argc, char** argv)
{
    int (*p)(int,int);  // p 是指向有两个整型参数函数的函数指针
    p = txt_size;
    int c = (*p)(1,2);
    std::cout << c << std::endl;
    return 0;
}
```
在上面的示例中，我们可以看到定义函数指针的格式：

- `type (*p)(paramsType)`：跟函数的声明类似，只是在函数名通过括号圈起来添加 *；
- `type *p(paramsType)`：这种定义是返回指针的函数，返回值是一个指针。
## 4. 类和结构体
面向对象的三大特征：继承、封装、多态。这些都离不开类这个载体。
### 4.1 类的定义
格式如下：
```cpp
class <类名> {
    public:
    <成员函数或数据成员>
    protected:   
    <成员函数或数据成员>
    private:
    <成员函数或数据成员>
}
```
例如我们定义一个学生类：
```cpp
class Student {
    public:
        int number;
        int setScore(int score);
    protected:
        char name[10];
    private:
        int score;
};
```
类的声明由类头和类体组成。类头由关键字 `class`开头，然后是类名。

- 类的声明以分号结尾，因为类的声明也是一条语句；
- 类的组成由数据成员和成员函数组成。
- 公有成员访问权限符（public）：既可以被本类中的成员函数访问，也可以被类的作用域内的其他函数访问
- 私有成员访问权限符（private）：成员只能被该类中的成员函数访问，类外的其他函数则不能（友元类除外，关于友元类后文会有介绍）。
- 保护成员访问权限符（protected）：成员只能被该类的成员函数或派生类（有关基类和派生类的概念将在后面介绍）的成员函数访问。
- 如果类中的定义没有指定访问权限修饰符，则默认为私有的。

一般情况下，数据成员通常是私有的，成员函数通常一部分是公有，一部分是私有的。公有的成员函数可以在类外被访问，也称为类的接口。
**成员函数定义**
类的成员函数定义格式如下：
```cpp
返回值类型 类名::函数名(参数)
{
    函数体实现
}
```
示例：
```cpp
int Student::setScore(int score) 
{
    this->age = score;
}
```
双冒号“::”是域运算符，它主要用于类的成员函数的定义，用它来标识某个成员函数是属于哪个类的。该运算符在此的使用格式如下：<类名> :: <函数名> <(参数表)>
### 4.2 构造函数
构造函数用于初始化变量和对象。当对象被创建时，构造函数自动被执行调用。改造函数的名字与类名相同，没有返回值和类型。
示例：
```cpp
class Carea {
    private:
        int width, height;
    public:
        Carea(int, int);
        int area();
};

// 定义构造函数
Carea::Carea(int width, int height)
{
    this->width = width;
    this->height = height;
}

int Carea::area()
{
    return width * height;
}

int main(int argc, char** argv)
{
    int width = 2, height = 4;
    Carea rect1(width, height);
    std::cout << rect1.area() << std::endl;
    return 0;
}
```
### 4.3 析构函数
构造函数的主要功能是在创建对象时，对对象做初始化操作。而析构函数与构造函数相反，是在对象被删除前由系统自动执行它做清理工作。析构函数与构造函数类似的是：析构函数也与类同名，但在名字前面有一个“～”符号，即取反运算符，析构函数没有返回类型和返回值。
析构函数也是在对象销毁时由系统调用。析构函数特别适用于当一个对象被动态分配内存空间，而在对象被销毁希望释放它所占用的空间的时候。
```cpp
Carea::~Carea()
{
    delete width;   // 释放 width 占用的内存资源
    delete height;
}
```
### 4.4 友元函数
在C++中，为了使类的私有成员和保护成员能够被其他类或其他成员函数访问，引入了友元的概念。例如，可以将客户定义为类的“朋友”，如果客户成为类的“朋友”，就可以直接存取类的保护成员和私有成员。类的“朋友”称为类的友元，友元可以是一个类的成员函数、一个普通函数或另外一个类。
### 4.5 继承
在 `C++`中继承的格式如下：
```cpp
class 派生类名 : (继承方式)基类名
{
    派生类成员;
}
```
## 5. 命名空间
C++中采用的是单一的全局变量命名空间，在这单一的空间中，如果有两个变量或函数的名字完全相同，就会出现冲突。命名空间是为了解决C++中的变量、函数的命名冲突而引入的一种机制，其主要思路是将变量定义在一个不同名字的命名空间中。
### 5.1 命名空间的定义
命名空间用关键字 namespace 来定义，定义格式如下：
```cpp
namespace命名空间名
{
    命名空间声明内容
}
```
示例：
```cpp
namespace antway 
{
    void print();
    string name;
}
```
### 5.2 命名空间的引用 using
使用 `using`声明可以在不需要加前缀 `“namespace_name:: ”`的情况下访问命名空间中的成员。`using`声明同其他声明的行为一样有一个作用域，它引入的名字从该声明开始直到其所在的域结束都是可见的。
注意：
`using`声明的最后必须是以命名空间中的成员名、函数或变量结尾，而不能是命名空间名。
## 6. 文件操作
文件是相关数据的集合。计算机中的程序、数据、文档通常都以文件形式存放在外存储器中。通常使用一个文件的步骤如下：

- 文件是相关数据的集合。计算机中的程序、数据、文档通常都以文件形式存放在外存储器中。
- 其后，使用文件流对象的成员函数，将数据写入到文件中或从文件中读取数据。
- 关闭已打开的文件，即将文件流对象与文件脱离联系。

C/C++ 把每一个文件都看成是一个有序的字节流，每个文件都是以 **文件结束标志**（EOF）结束，如果要操作某个文件，程序应该首先打开该文件，每当一个文件被打开后（请记得关闭打开的文件），该文件就和一个流关联起来，这里的流实际上是一个字节序列。
### 6.1 基本操作
在 `c++`中对于文件的操作需要先添加 `#include <fstream>`预处理命令。由它提供的输入文件流类 `ifstream`、输出文件流类 `ofstream`和输入输出文件流类 `fstream`定义了用户所需要的文件流对象，然后利用该对象调用相应类中的成员函数，按照一定的方式来操作文件。
操作文件的三大类：

- `ofstream`：写操作
- `ifstream`：读操作
- `fstream`：读写操作

文件打开的方式：

- ios::in 为读文件而打开文件
- ios::out 为写文件而打开文件
- ios::ate 初始位置：文件尾
- ios::app 追加方式写文件
- ios:: trunc 如果文件存在先删除，再创建
- ios::binary 二进制方式
```cpp
#include <fstream>
using namespace std;  // 两个类型都在 std 命名空间里

ifstream fin("data.in");
ofstream fout("data.out");

int main(void) {
  /*
  中间的代码改变 cin 为 fin ，cout 为 fout 即可
  */
  fin.close();
  fout.close();
  return 0;
}
```
### 6.2 文件基本使用

- 打开文件，将文件指针指向文件，决定打开文件类型；
- 对文件进行读、写操作（比赛中主要用到的操作，其他一些操作暂时不写）；
- 在使用完文件后，关闭文件。

**freopen 函数**
```cpp
FILE* freopen(const char* filename, const char* mode, FILE* stream);
```
参数说明

- filename: 要打开的文件名
- mode: 文件打开的模式，表示文件访问的权限
- stream: 文件指针，通常使用标准文件流 (stdin/stdout) 或标准错误输出流 (stderr)
- 返回值：文件指针，指向被打开文件
#### 文件打开格式（选读）

- r：以只读方式打开文件，文件必须存在，只允许读入数据 **（常用）**
- r+：以读/写方式打开文件，文件必须存在，允许读写数据
- rb：以只读方式打开二进制文件，文件必须存在，只允许读入数据
- rb+：以读写方式打开二进制文件，文件必须存在，允许读写数据
- rt+：以读写方式打开文本文件，允许读写
- w：以只写方式打开文件，文件不存在会新建文件，否则清空内容，只允许写入数据 **（常用）**
- w+：以读/写方式打开文件，文件不存在将新建文件，否则清空内容，允许读写数据
- wb：以只读方式打开二进制文件，文件不存在将会新建文件，否则清空内容，只允许写入数据
- wb+：以读写方式打开二进制文件，文件不存在将新建文件，否则清空内容，允许读写数据
- a：以附加方式打开只写文件，文件不存在将新建文件，写入数据将被附加在文件末尾（保留 EOF 符）
- a+：以附加方式打开只写文件，文件不存在将新建文件，写入数据将被附加在文件末尾（不保留 EOF 符）
- at+：以读写方式打开文本文件，写入数据将被附加在文件末尾
- ab+：以读写方式打开二进制文件，写入数据将被附加在文件末尾
```cpp
freopen("data.in", "r", stdin);
// data.in 就是读取的文件名，要和可执行文件放在同一目录下
```
类似的函数为 fopen。
```cpp
int main(int argc, char** argv)
{
    char data[100];
    FILE *in;
    in = fopen("Hello.cpp", "r");
    
    if (in != NULL) 
    {
        printf("Failed to open file");
    }

    while(fgets(data, 100, in)) {
        printf("%s", data);
    }

    std::cout<<data<<std::endl;
    return 0;
}
```
## 7. 高级用法
### 7.1 智能指针类型
在 C++11 中引入了 3 个智能指针类型：

- std::unique_ptr<T> ：独占资源所有权的指针。
- std::shared_ptr<T> ：共享资源所有权的指针。
- std::weak_ptr<T> ：共享资源的观察者，需要和 std::shared_ptr 一起使用，不影响资源的生命周期
#### 1. std::unique_ptr<T>
创建独占资源所有权，使用 str::unique_ptr 对资源管理时，离开 unique_ptr 对象作用域时，就会自动释放资源。
```cpp
// 使用裸指针
int* p = new int(10);
delete p;  // 要记得释放内存
// 离开 uptr 的作用域的时候自动释放内存
std::unique_ptr<int> uptr = std::make_unique<int>(20);
std::unique_ptr<int> uptr = std::make_unique<int>(20);
```
#### 2. std::shared_ptr<T> 
std::shared_ptr 其实就是对资源做引用计数——当引用计数为 0 的时候，自动释放资源。
```cpp
std::shared_ptr<int> sptr = std::make_shared<int>(200);
assert(sptr.use_count() == 1);  // 此时引用计数为 1
{   
    std::shared_ptr<int> sptr1 = sptr;
    assert(sptr.get() == sptr1.get());
    assert(sptr.use_count() == 2);   // sptr 和 sptr1 共享资源，引用计数为 2
}   
assert(sptr.use_count() == 1);   // sptr1 已经释放
```
### 7.2 std::queue<type>
队列模板类，定义在 <queue> 头文件中，是一种先进先出的数据结构。
```cpp
int main(int argc, char** argv)
{
    std::queue<int> myQueue;
    myQueue.push(1);
    std::cout<< myQueue.size() << std::endl;
    return 0;
}
```

- queue::emplace() 用于在队列容器中插入或放置新元素；
### 7.3 GUARDED_BY 和 EXCLUDES 关键字
GUARDED_BY
GUARDED_BY 是数据成员的属性，该属性声明数据成员受给定功能保护。对数据的读操作需要共享访问，而写操作则需要互斥访问。该 GUARDED_BY 属性声明线程必须先锁定 listener_list_mutex 才能对其进行读写 listener_list，从而确保增量和减量操作是原子的。
EXCLUDES
EXCLUDES 是函数或方法的属性，该属性声明调用方不拥有给定的功能。该注释用于防止死锁。许多互斥量实现都不是可重入的，因此，如果函数第二次获取互斥量，则可能发生死锁。在上面代码中的EXCLUDES表示的意思是：调用listener_disconnect()函数的调用用不能拥有listener_list_mutex锁。
