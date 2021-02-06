//
// Created by wenhan on 2021/1/31.
//

#ifndef SORTER_SORTER_H
#define SORTER_SORTER_H

class Sorter {
public:
    static void bubbleSort(int arr[], int length);

    static void selectSort(int arr[], int length);

    static void insertSort(int arr[], int length);

    static void shellSort(int arr[], int length);

    static void quickSort(int arr[], int start, int end);

    static void mergeSort(int arr[], int start, int end, int temp[]);

    static void heapSort(int arr[], int length);

private:
    static void _swap(int* a, int* b);
    // 快速排序使用
    static int _partition(int arr[], int start, int end);

    // 归并排序使用
    static void _merge(int arr[], int start, int end, int mid, int temp[]);

    // 堆排序使用
    static void _adjust(int arr[], int index, int length);
};


#endif //SORTER_SORTER_H
