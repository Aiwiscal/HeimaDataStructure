#include <iostream>
#include "LinkList.h"

// 自定义数据类型
typedef struct PERSON{
    char name[64];
    int age;
    int score;
}Person;

// 打印函数

void myPrint(void *data){
    auto *p = (Person *)data;
    std::cout << "Name:" << p->name << " Age:" << p->age << " Score:" << p->score << std::endl;
}

int main() {

    // 创建链表
    LinkList list;

    // 创建数据
    Person p1 = {"aaa", 18, 100};
    Person p2 = {"bbb", 19, 99};
    Person p3 = {"ccc", 20, 101};
    Person p4 = {"ddd", 17, 97};
    Person p5 = {"eee", 16, 59};

    // 数据插入链表

    list.insert_linkList(0, &p1);
    list.insert_linkList(0, &p2);
    list.insert_linkList(0, &p3);
    list.insert_linkList(0, &p4);
    list.insert_linkList(0, &p5);

    // 打印
    list.print_linkList(myPrint);

    list.remove_linkList_pos(3);

    // 打印
    std::cout << "----------------------" << std::endl;
    list.print_linkList(myPrint);

    // 返回第一个结点
    std::cout << "---------查找结果-------------" << std::endl;
    auto ret = (Person *)list.get_front();
    std::cout << "Name:" << ret->name << " Age:" << ret->age << " Score:" << ret->score << std::endl;

    // 查找(新增测试)
    std::cout << "----------------------" << std::endl;
    int pos = list.find_linkList(&p3);
    std::cout << "Name:" << p3.name << " Age:" << p3.age << " Score:" << p3.score << std::endl;
    std::cout << "pos: " << pos << std::endl;
    int size = list.get_size();
    std::cout << "size: " << size << std::endl;

    // 自动调用LinkList析构函数 销毁

    return 0;
}
