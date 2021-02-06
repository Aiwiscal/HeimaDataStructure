//
// Created by wenhan on 2021/1/26.
//

#include <iostream>
#include "SeqStack.h"

// 初始化方法使用无参数构造器代替！
SeqStack::SeqStack(){
    for (auto & i : data) {
        i = nullptr;
    }
    size = 0;
}

// 销毁
SeqStack::~SeqStack() {
    std::cout << "free seq stack!" << std::endl;
}

// 入栈
void SeqStack::push_seqStack(void *value){
    // 防止与成员变量data冲突，改形参名为value
    if (value == nullptr){
        return;
    }
    if (size == MAX_SIZE){
        return;
    }
    data[size] = value;
    size ++;
}

// 返回栈顶元素
void* SeqStack::top_seqStack(){
    if (size == 0){
        return nullptr;
    }
    return data[size-1];
}

// 出栈
void SeqStack::pop_seqStack(){
    if (size == 0){
        return;
    }
    data[size-1] = nullptr;
    size--;
}

// 判断是否为空
bool SeqStack::is_empty() const{
    if (size == 0){
        return true;
    }
    return false;
}

// 返回栈中元素的个数
int SeqStack::get_size() const{
    return size;
}

// 清空栈
void SeqStack::clear_seqStack(){
    for (int i = 0; i < size; ++i) {
        data[i] = nullptr;
    }
    size = 0;
}
