//
// Created by 邓士伟 on 2022/10/12.
//

#include "map"
#include "iostream"

using namespace std;

int main() {
    std::map<int, int> maps;
    maps[1] = 1;
    maps[2] = 2;
    for (auto val = maps.begin(); val != maps.end(); val++) {
        std::cout << "key = " << val->first << ",value = " << val->second << std::endl;
    }
    return 0;
}
