//
// Created by wenhan on 2021/1/26.
//

#ifndef SEQSTACK_SEQSTACK_H
#define SEQSTACK_SEQSTACK_H

const int MAX_SIZE = 1024;

// 数组模拟堆栈的顺序存储
// 数组右侧作为栈顶，无需频繁移动元素

class SeqStack {
private:
    void *data[MAX_SIZE]{};
    int size;
public:
    // 初始化方法使用无参数构造器代替！
    SeqStack();

    // 销毁使用析构函数代替！
    ~SeqStack();

    // 入栈
    void push_seqStack(void *data);

    // 返回栈顶元素
    void* top_seqStack();

    // 出栈
    void pop_seqStack();

    // 判断是否为空
    bool is_empty() const;

    // 返回栈中元素的个数
    int get_size() const;

    // 清空栈
    void clear_seqStack();

};


#endif //SEQSTACK_SEQSTACK_H
