//
// Created by wenhan on 2021/1/25.
//

#include <iostream>
#include "LinkList.h"

LinkList::LinkList(){
    head = new LinkNode;
    size = 0;
    // 头结点不保存数据信息
    head->data = nullptr;
    head->next = nullptr;
}

// 释放链表内存由析构函数代替
LinkList::~LinkList() {
    if (head == nullptr){
        return;
    }
    auto *pCurrent = head;
    while (pCurrent != nullptr){
        // 缓存下一个结点指针
        auto *pNext = pCurrent->next;
        delete pCurrent;
        pCurrent = pNext;
    }
    size = 0;
    std::cout << "free LinkList!" << std::endl;
}


// 指定位置插入
void LinkList::insert_linkList(int pos, void* data){
    if (head == nullptr){
        return;
    }
    if (data == nullptr){
        return;
    }
    // 友好处理，pos越界
    if (pos < 0 ||pos > size){
        pos = size;
    }
    //创建新结点
    auto * newNode = new LinkNode;
    newNode->data = data;
    newNode->next = nullptr;

    // 找结点
    // 辅助指针变量
    auto *pCurrent = head;
    for (int i = 0; i < pos; ++i) {
        pCurrent = pCurrent->next;
    }
    // 新结点入链表
    newNode->next = pCurrent->next;
    pCurrent->next = newNode;

    size++;
}

// 删除指定位置的值
void LinkList::remove_linkList_pos(int pos){
    if (head == nullptr){
        return;
    }
    if (pos < 0 || pos >= size){
        return;
    }
    auto *pCurrent = head;
    for (int i = 0; i < pos; ++i) {
        pCurrent = pCurrent->next;
    }
    auto *pDel = pCurrent->next;
    pCurrent->next = pDel->next;
    delete pDel;
    size --;
}

// 获得链表的长度
int LinkList::get_size() const{
    return size;
}

// 查找元素值位置
int LinkList::find_linkList(void* data){
    if (head == nullptr){
        return -1;
    }
    if (data == nullptr){
        return -1;
    }

    auto *pCurrent = head->next;
    int i = 0;
    while (pCurrent != nullptr){
        if (pCurrent->data == data){
            return i;
        }
        pCurrent = pCurrent->next;
        i++;
    }
    return -1;
}

// 返回第一个结点
void *LinkList::get_front(){
    return head -> next ->data;
}

// 打印
void LinkList::print_linkList(PRINTLINKNODE print){
    if (head == nullptr){
        return;
    }
    auto *pCurrent = head->next;
    while (pCurrent != nullptr){
        print(pCurrent->data);
        pCurrent = pCurrent ->next;
    }

}



