//
// Created by wenhan on 2021/1/24.
//

#ifndef DYNAMICARRAY_DYNAMICARRAY_H
#define DYNAMICARRAY_DYNAMICARRAY_H
#include <iostream>
#include <string>
#include <cstdlib>


class DynamicArray {
private:
    int *pAddr;
    int size;
    int capacity;

public:
    DynamicArray();
    ~DynamicArray();
    void push_back_array(int value);
    void remove_array_pos(int pos);
    void remove_array_val(int value);
    void clear_array();
    int find_array(int value);
    void print_array();
    int get_capacity() const;
    int get_size() const;
    int at_array(int pos);
    bool at_array(int pos, int& value);

};


#endif //DYNAMICARRAY_DYNAMICARRAY_H
