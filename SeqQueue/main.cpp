#include <iostream>
#include "SeqQueue.h"

typedef struct PERSON{
    char name[64];
    int age;
}Person;

int main() {
    // 创建队列
    SeqQueue queue;

    // 创建数据
    Person p1 = {"aaa", 10};
    Person p2 = {"bbb", 20};
    Person p3 = {"ccc", 30};
    Person p4 = {"ddd", 40};
    Person p5 = {"eee", 50};

    // 数据入队列
    queue.push_seqQueue(&p1);
    queue.push_seqQueue(&p2);
    queue.push_seqQueue(&p3);
    queue.push_seqQueue(&p4);
    queue.push_seqQueue(&p5);

    // 输出队尾元素
    auto backPerson = (Person*)queue.back_seqQueue();
    std::cout << "Name:" << backPerson->name << " Age:" << backPerson->age << std::endl;

    // 输出
    while (queue.get_size() > 0){
        // 取队头元素
        auto p = (Person*)queue.front_seqQueue();
        std::cout << "Name:" << p->name << " Age:" << p->age << std::endl;
        // 从队头弹出元素
        queue.pop_seqQueue();
    }
    // 自动调用析构函数

    return 0;
}
