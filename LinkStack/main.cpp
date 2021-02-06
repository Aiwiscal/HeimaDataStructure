#include <iostream>
#include "LinkStack.h"
#include <cstring>

typedef struct PERSON{
    LinkNode node;
    char name[64];
    int age;
}Person;

int main() {
    // 创建栈
    LinkStack stack;

    // 创建数据
    Person p1, p2, p3, p4, p5;
    strcpy(p1.name, "aaa");
    strcpy(p2.name, "bbb");
    strcpy(p3.name, "ccc");
    strcpy(p4.name, "ddd");
    strcpy(p5.name, "eee");

    p1.age = 10;
    p2.age = 20;
    p3.age = 30;
    p4.age = 40;
    p5.age = 50;

    // 入栈
    stack.push_linkStack((LinkNode*)&p1);
    stack.push_linkStack((LinkNode*)&p2);
    stack.push_linkStack((LinkNode*)&p3);
    stack.push_linkStack((LinkNode*)&p4);
    stack.push_linkStack((LinkNode*)&p5);

    while (stack.get_size() > 0){
        // 取出栈顶元素
        auto *p = (Person *)stack.top_linkStack();
        std::cout << "Name:" << p->name << " Age:" << p->age << std::endl;
        // 弹出栈顶元素
        stack.pop_linkStack();
    }

    // 自动析构，销毁stack

    return 0;
}
