//
// Created by wenhan on 2021/1/27.
//

#ifndef LINKQUEUE_LINKQUEUE_H
#define LINKQUEUE_LINKQUEUE_H

// 链式队列的结点
typedef struct LINKNODE{
    struct LINKNODE* next;
}LinkNode;

class LinkQueue {
private:
    LinkNode head{};
    int size;
public:
    // 初始化方法使用无参数构造器代替
    LinkQueue();

    // 销毁队列使用析构函数代替
    ~LinkQueue();

    // 入栈
    void push_linkQueue(LinkNode* data);

    // 返回队头元素
    void* front_linkQueue() const;

    // 出队
    void pop_linkQueue();

    // 返回队尾元素
    void* back_linkQueue();

    // 返回大小
    int get_size() const;

    // 清空队列
    void clear_linkQueue();


};


#endif //LINKQUEUE_LINKQUEUE_H
