//
// Created by wenhan on 2021/1/26.
//

#include <iostream>
#include "LinkStack.h"


// 初始化方法使用无参数构造器代替！
LinkStack::LinkStack(){
    head.next = nullptr;
    size = 0;
}

LinkStack::~LinkStack() {
    // 结点中没有使用new创建的元素，无需处理
    std::cout << "free LinkStack!" << std::endl;
}

// 入栈
void LinkStack::push_linkStack(LinkNode* data){
    if (data == nullptr){
        return;
    }
    data ->next = head.next;
    head.next = data;
    size ++;
}

// 出栈
void LinkStack::pop_linkStack(){
    if (size == 0){
        return;
    }

    // 第一个有效结点
    LinkNode *pNext = head.next;
    head.next = pNext->next;
    size --;

}

// 返回栈顶元素
LinkNode* LinkStack::top_linkStack() const{
    if (size == 0){
        return nullptr;
    }
    return head.next;
}

// 返回栈元素个数
int LinkStack::get_size()const{
    return size;
}

// 清空栈
void LinkStack::clear_linkStack(){
    if (size == 0){
        return;
    }
    head.next = nullptr;
    size = 0;
}
