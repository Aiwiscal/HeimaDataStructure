#include <iostream>
#include <ctime>
#include "Sorter.h"
#include <sys/timeb.h>

// timeb 解释：https://www.cnblogs.com/wanghao111/archive/2009/05/25/1489018.html

const int MAX_SIZE = 100000;
void printArray(int arr[], int length){
    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

long getSystemTime(){
    struct timeb tb{};
    ftime(&tb);
    return tb.time * 1000 + tb.millitm;
}

int main() {

    int* arr = new int[MAX_SIZE];
    std::srand((unsigned int)time(nullptr));
    for (int i = 0; i < MAX_SIZE; ++i) {
        arr[i] = std::rand() % MAX_SIZE;
    }
    std::cout << "排序前：" << std::endl;
//    printArray(arr, MAX_SIZE);
    long t_start = getSystemTime();
    Sorter::bubbleSort(arr, MAX_SIZE);
    long t_end = getSystemTime();
    std::cout << "冒泡排序" << MAX_SIZE << "个元素，所需时间：" << (t_end - t_start) << std::endl;
    std::cout << "排序后：" << std::endl;
//    printArray(arr, MAX_SIZE);


    for (int i = 0; i < MAX_SIZE; ++i) {
        arr[i] = std::rand() % MAX_SIZE;
    }

    std::cout << "排序前：" << std::endl;
//    printArray(arr, MAX_SIZE);
    t_start = getSystemTime();
    Sorter::selectSort(arr, MAX_SIZE);
    t_end = getSystemTime();
    std::cout << "选择排序" << MAX_SIZE << "个元素，所需时间：" << (t_end - t_start) << std::endl;
    std::cout << "排序后：" << std::endl;
//    printArray(arr, MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; ++i) {
        arr[i] = std::rand() % MAX_SIZE;
    }
    std::cout << "排序前：" << std::endl;
//    printArray(arr, MAX_SIZE);
    t_start = getSystemTime();
    Sorter::insertSort(arr, MAX_SIZE);
    t_end = getSystemTime();
    std::cout << "插入排序" << MAX_SIZE << "个元素，所需时间：" << (t_end - t_start) << std::endl;
    std::cout << "排序后：" << std::endl;
//    printArray(arr, MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; ++i) {
        arr[i] = std::rand() % MAX_SIZE;
    }
    std::cout << "排序前：" << std::endl;
//    printArray(arr, MAX_SIZE);
    t_start = getSystemTime();
    Sorter::shellSort(arr, MAX_SIZE);
    t_end = getSystemTime();
    std::cout << "希尔排序" << MAX_SIZE << "个元素，所需时间：" << (t_end - t_start) << std::endl;
    std::cout << "排序后：" << std::endl;
//    printArray(arr, MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; ++i) {
        arr[i] = std::rand() % MAX_SIZE;
    }
    std::cout << "排序前：" << std::endl;
//    printArray(arr, MAX_SIZE);
    t_start = getSystemTime();
    Sorter::quickSort(arr, 0, MAX_SIZE-1);
    t_end = getSystemTime();
    std::cout << "快速排序" << MAX_SIZE << "个元素，所需时间：" << (t_end - t_start) << std::endl;
    std::cout << "排序后：" << std::endl;
//    printArray(arr, MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; ++i) {
        arr[i] = std::rand() % MAX_SIZE;
    }
    int* temp = new int[MAX_SIZE];
    std::cout << "排序前：" << std::endl;
//    printArray(arr, MAX_SIZE);
    t_start = getSystemTime();
    Sorter::mergeSort(arr, 0, MAX_SIZE-1, temp);
    t_end = getSystemTime();
    std::cout << "归并排序" << MAX_SIZE << "个元素，所需时间：" << (t_end - t_start) << std::endl;
    std::cout << "排序后：" << std::endl;
//    printArray(arr, MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; ++i) {
        arr[i] = std::rand() % MAX_SIZE;
    }
    std::cout << "排序前：" << std::endl;
//    printArray(arr, MAX_SIZE);
    t_start = getSystemTime();
    Sorter::heapSort(arr, MAX_SIZE);
    t_end = getSystemTime();
    std::cout << "堆排序" << MAX_SIZE << "个元素，所需时间：" << (t_end - t_start) << std::endl;
    std::cout << "排序后：" << std::endl;
//    printArray(arr, MAX_SIZE);

    delete[] temp;
    delete[] arr;
    return 0;
}
