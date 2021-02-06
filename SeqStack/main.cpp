#include <iostream>
#include "SeqStack.h"

typedef struct  PERSON{
    char name[64];
    int age;
}Person;

int main() {
    // 创建栈
    SeqStack stack;

    //创建数据
    Person p1 = {"aaa", 10};
    Person p2 = {"bbb", 20};
    Person p3 = {"ccc", 30};
    Person p4 = {"ddd", 40};
    Person p5 = {"eee", 50};

    // 入栈
    stack.push_seqStack(&p1);
    stack.push_seqStack(&p2);
    stack.push_seqStack(&p3);
    stack.push_seqStack(&p4);
    stack.push_seqStack(&p5);

    while (stack.get_size() > 0){
        // 访问栈顶元素
        auto *person = (Person *)stack.top_seqStack();
        std::cout << "Name:" << person->name << " Age:" << person->age << std::endl;
        // 弹出栈顶元素
        stack.pop_seqStack();
    }

    // 析构函数调用，释放内存
    return 0;
}
