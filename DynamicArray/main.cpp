#include <iostream>
#include "DynamicArray.h"


int test_01(){
    DynamicArray dynamicArray;
    std::cout << "数组容量：" << dynamicArray.get_capacity() << std::endl;
    std::cout << "数组大小：" << dynamicArray.get_size() << std::endl;
    for (int i = 0; i < 30; ++i) {
        dynamicArray.push_back_array(i);
    }
    std::cout << "数组容量：" << dynamicArray.get_capacity() << std::endl;
    std::cout << "数组大小：" << dynamicArray.get_size() << std::endl;

    dynamicArray.print_array();

    dynamicArray.remove_array_pos(0);
    dynamicArray.remove_array_val(27);
    dynamicArray.print_array();

    int pos = dynamicArray.find_array(5);
    std::cout << "5查找到：pos："<< pos << " " << dynamicArray.at_array(pos) << std::endl;

    //测试 at_array 安全实现
    int value = 0;
    pos = 100;
    bool ret = dynamicArray.at_array(pos, value);
    if (!ret){
        std::cout << "查找 pos " << pos << " 失败！" << std::endl;
    }else{
        std::cout << "查找 pos " << pos << " 成功！值为 " << value << std::endl;
    }

    pos = 26;
    ret = dynamicArray.at_array(pos, value);
    if (!ret){
        std::cout << "查找 pos " << pos << " 失败！" << std::endl;
    }else{
        std::cout << "查找 pos " << pos << " 成功！值为 " << value << std::endl;
    }

//    dynamicArray.free_array();
    return 0;
}

int main() {
    test_01();
    return 0;
}
