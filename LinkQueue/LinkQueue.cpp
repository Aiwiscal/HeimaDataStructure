//
// Created by wenhan on 2021/1/27.
//
#include <iostream>
#include "LinkQueue.h"

// 初始化方法使用无参数构造器代替
LinkQueue::LinkQueue(){
    head.next = nullptr;
    size = 0;
}

// 销毁队列使用析构函数代替
LinkQueue::~LinkQueue(){
    // 结点中没有使用new创建的元素，无需处理
    std::cout << "free LinkQueue!" << std::endl;
}

// 入栈
void LinkQueue::push_linkQueue(LinkNode* data){
    if (data == nullptr){
        return;
    }
    if (size == 0){
        head.next = data;
        size ++;
        return;
    }
    LinkNode *pCurrent = &head;
    for (int i = 0; i < size; ++i) {
        pCurrent = pCurrent->next;
    }
    pCurrent ->next = data;
    data->next = nullptr;
    size++;
}

// 返回队头元素
void* LinkQueue::front_linkQueue() const{
    if (size == 0){
        return nullptr;
    }
    return head.next;
}

// 出队
void LinkQueue::pop_linkQueue(){
    if (size == 0){
        return;
    }
    LinkNode *pNext = head.next;
    head.next = pNext->next;
    size --;
}

// 返回队尾元素
void* LinkQueue::back_linkQueue(){
    if (size == 0){
        return nullptr;
    }
    LinkNode *pCurrent = &head;
    for (int i = 0; i < size; ++i) {
        pCurrent = pCurrent->next;
    }
    return pCurrent;
}

// 返回大小
int LinkQueue::get_size() const{
    return size;
}

// 清空队列
void LinkQueue::clear_linkQueue(){
    if (size == 0){
        return;
    }
    head.next = nullptr;
    size = 0;
}