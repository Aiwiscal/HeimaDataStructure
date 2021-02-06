//
// Created by wenhan on 2021/1/25.
//

#ifndef LINKLIST_LINKLIST_H
#define LINKLIST_LINKLIST_H

//链表结点
typedef struct LINKNODE{
    void* data; // 指向任意类型的数据
    struct LINKNODE* next;
}LinkNode;

// 打印函数指针
typedef void(*PRINTLINKNODE)(void*);

class LinkList {
private:
    LinkNode *head;
    int size;
public:
    // 初始化使用无参数构造器代替！
    LinkList();

    // 释放链表内存由析构函数代替！
    ~LinkList();

    // 指定位置插入
    void insert_linkList(int pos, void* data);

    // 删除指定位置的值
    void remove_linkList_pos(int pos);

    // 获得链表的长度
    int get_size() const;

    // 查找元素值位置
    int find_linkList(void* data);

    // 返回第一个结点
    void *get_front();


    // 打印
    void print_linkList(PRINTLINKNODE print);


};


#endif //LINKLIST_LINKLIST_H
