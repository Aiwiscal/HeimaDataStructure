//
// Created by wenhan on 2021/1/27.
//

#include <iostream>
#include "SeqQueue.h"

// 初始化使用无参数构造器代替
SeqQueue::SeqQueue(){
    for (auto & i : data) {
        i = nullptr;
    }
    size = 0;
}

// 销毁使用析构函数代替
SeqQueue::~SeqQueue(){
    // 数组所用数组未使用new创建，无需显式释放
    std::cout << "free SeqQueue!" << std::endl;
}

// 入队
void SeqQueue::push_seqQueue(void* value){
    // 数组左边当做队头
    // 防止与成员变量data重名，入参名改为value
    if (value == nullptr){
        return;
    }
    if (size == MAX_SIZE){
        return;
    }
    data[size] = value;
    size++;

}

// 返回队头元素
void* SeqQueue::front_seqQueue(){
    if (size == 0){
        return nullptr;
    }
    return data[0];
}

// 出队
void SeqQueue::pop_seqQueue(){
    if (size == 0){
        return;
    }
    for (int i = 0; i < size - 1; ++i) {
        data[i] = data[i+1];
    }
    size --;
}

// 返回队尾元素
void* SeqQueue::back_seqQueue(){
    if (size == 0){
        return nullptr;
    }
    return data[size-1];
}

// 返回大小
int SeqQueue::get_size() const{
    return size;
}

// 清空队列
void SeqQueue::clear_seqQueue(){
    if (size == 0){
        return;
    }
    size = 0;
}