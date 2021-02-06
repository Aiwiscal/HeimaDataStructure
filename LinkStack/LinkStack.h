//
// Created by wenhan on 2021/1/26.
//

#ifndef LINKSTACK_LINKSTACK_H
#define LINKSTACK_LINKSTACK_H

// 链式栈的结点
typedef struct LINKNODE{
    struct LINKNODE* next;
}LinkNode;

// 链式栈
// 头部作为栈顶，可直接插入或删除，无需遍历
class LinkStack {
private:
    LinkNode head{};
    int size;
public:
    // 初始化方法使用无参数构造器代替！
    LinkStack();

    // 销毁栈使用析构函数代替！
    ~LinkStack();

    // 入栈
    void push_linkStack(LinkNode* data);

    // 出栈
    void pop_linkStack();

    // 返回栈顶元素
    LinkNode* top_linkStack() const;

    // 返回栈元素个数
    int get_size()const;

    // 清空栈
    void clear_linkStack();


};


#endif //LINKSTACK_LINKSTACK_H
