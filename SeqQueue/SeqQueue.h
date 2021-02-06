//
// Created by wenhan on 2021/1/27.
//

#ifndef SEQQUEUE_SEQQUEUE_H
#define SEQQUEUE_SEQQUEUE_H

const int MAX_SIZE = 1024;


class SeqQueue {
private:
    void* data[MAX_SIZE]{};
    int size;

public:
    // 初始化使用无参数构造器代替
    SeqQueue();

    // 销毁使用析构函数代替
    ~SeqQueue();

    // 入队
    void push_seqQueue(void* data);

    // 返回队头元素
    void* front_seqQueue();

    // 出队
    void pop_seqQueue();

    // 返回队尾元素
    void* back_seqQueue();

    // 返回大小
    int get_size() const;

    // 清空队列
    void clear_seqQueue();



};


#endif //SEQQUEUE_SEQQUEUE_H
