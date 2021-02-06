//
// Created by wenhan on 2021/1/24.
//

#include "DynamicArray.h"

DynamicArray::DynamicArray(){
    pAddr = nullptr;
    size = 0;
    capacity = 20;
    pAddr = new int[capacity];
}

// 销毁array使用析构函数代替
DynamicArray::~DynamicArray() {
    delete[] pAddr;
    std::cout << "free array!" << std::endl;
}
void DynamicArray::push_back_array(int value){
    if (pAddr == nullptr){
        return;
    }
    if (size == capacity){
        int *newAddr = new int[2*capacity];
        memcpy(newAddr, pAddr, capacity*sizeof(int));
        delete [] pAddr;
        pAddr = newAddr;
        capacity = capacity * 2;
    }
    pAddr[size] = value;
    size ++;
}
void DynamicArray::remove_array_pos(int pos){
    if (pAddr == nullptr){
        return;
    }
    if (pos < 0 || pos >= size){
        return;
    }
    for (int i = pos; i < size - 1; ++i) {
        pAddr[i] = pAddr[i+1];
    }
    size --;
}
void DynamicArray::remove_array_val(int value){
    if (pAddr == nullptr){
        return;
    }
    int pos = find_array(value);
    remove_array_pos(pos);
}

void DynamicArray::clear_array() {
    size = 0;
}

int DynamicArray::find_array(int value){
    if (pAddr == nullptr){
        return -1;
    }
    int pos = -1;
    for (int i = 0; i < size; ++i) {
        if (pAddr[i] == value){
            pos = i;
            break;
        }
    }
    return pos;
}
void DynamicArray::print_array(){
    if (pAddr == nullptr){
        return;
    }
    for (int i = 0; i < size; ++i) {
        std::cout << pAddr[i] << " ";
    }
    std::cout << std::endl;
}

int DynamicArray::get_capacity() const{
    return capacity;
}
int DynamicArray::get_size() const{
    return size;
}

int DynamicArray::at_array(int pos){
    return pAddr[pos];
}

bool DynamicArray::at_array(int pos, int& value){   // 视频中原始实现方式可变为更安全的方式
    if (pAddr == nullptr || pos >= size || pos >= capacity || pos < 0){
        return false;
    }
    value = pAddr[pos];
    return true;
}