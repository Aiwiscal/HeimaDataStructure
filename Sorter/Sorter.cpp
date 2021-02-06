//
// Created by wenhan on 2021/1/31.
//

#include "Sorter.h"

// 冒泡排序
// 比较次数为 n(n-1)/2, 移动次数为3n(n-1)/2
void Sorter::bubbleSort(int arr[], int length){
    for (int i = 0; i < length - 1; ++i) {
        bool flag = false;
        for (int j = length-1; j > i; --j) {
            if (arr[j] < arr[j-1]){
                flag = true;
                _swap(&arr[j], &arr[j-1]);
            }
        }
        if (!flag){
            break;
        }
    }
}

// 选择排序
// 比较次数为 n(n-1)/2, 移动次数为3(n-1)
void Sorter::selectSort(int *arr, int length) {
    // 选择排序通过减少交换次数来提升效率
    for (int i = 0; i < length; ++i) {
        int min = i;
        for (int j = i; j < length; ++j) {
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        _swap(&arr[i], &arr[min]);
    }
}

// 插入排序
// 最好情况：原始序列正序，需要比较(n-1)次，移动2(n-1)次，时间复杂度O(n)
// 最坏情况：原始序列倒序，需要比较(n-1)(n+2)/2次(2~n求和值)，移动(n-1)(n+4)/2次 ((2+1)~(n+1)求和值)
void Sorter::insertSort(int *arr, int length) {
    for (int i = 1; i < length; ++i) {
        if (arr[i] < arr[i-1]){
            int temp = arr[i];
            int j;
            for (j = i-1; j >= 0 && arr[j] > temp; --j) {
                arr[j+1] = arr[j];
            }
            arr[j+1] = temp;
        }

    }
}

// 希尔排序
void Sorter::shellSort(int *arr, int length) {
    int increase = length;
    do {
        increase = increase/3 + 1;
        for (int i = 0; i < increase; ++i) {
            for (int j = i+increase; j < length; j+=increase) {
                if (arr[j] < arr[j-increase]){
                    int temp = arr[j];
                    int k;
                    for (k = j-increase; k >=0 && arr[k] > temp; k-=increase) {
                        arr[k+increase] = arr[k];
                    }
                    arr[k+increase] = temp;
                }
            }
        }
    } while (increase > 1);

}

// 快速排序
// 分治法+挖坑填数，找基准数，经过移动使小于基准数的全部在左边，大于基准数的全部在右边
void Sorter::quickSort(int arr[], int start, int end) {
    if (start >= end){
        return;
    }
    int pivotPos = _partition(arr, start, end);
    quickSort(arr, start, pivotPos - 1);
    quickSort(arr, pivotPos + 1, end);
}

void Sorter::mergeSort(int *arr, int start, int end, int temp[]) {
    if (start >= end){
        return;
    }
    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid, temp);
    mergeSort(arr, mid + 1, end, temp);
    _merge(arr, start, end, mid, temp);
}

void Sorter::heapSort(int *arr, int length) {
    // 初始化堆，大顶堆
    for (int i = length/2-1; i >= 0; --i) {
        _adjust(arr, i, length);
    }
    // 交换堆顶元素和最后一个元素
    for (int i = length-1; i >= 0; --i) {
        _swap(&arr[0], &arr[i]);
        _adjust(arr, 0, i);
    }
}

void Sorter::_swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Sorter::_partition(int *arr, int start, int end) {
    int pivot = arr[start];
    int pivotPos = start;
    int i = start, j = end;
    while (i < j){
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if (i >= j) break;
        _swap(&arr[i], &arr[j]);
    }
    arr[pivotPos] = arr[j];
    arr[j] = pivot;
    return j;
}

void Sorter::_merge(int *arr, int start, int end, int mid, int *temp) {
    int i_start = start;
    int j_start = mid + 1;
    int i_end = mid;
    int j_end = end;
    int pos = start;
    while (i_start <= i_end && j_start <= j_end){
        if (arr[i_start] < arr[j_start]){
            temp[pos] = arr[i_start];
            i_start++;
            pos++;
        } else{
            temp[pos] = arr[j_start];
            j_start++;
            pos++;
        }
    }
    while (i_start <= i_end){
        temp[pos] = arr[i_start];
        i_start++;
        pos ++;
    }
    while (j_start <= j_end){
        temp[pos] = arr[j_start];
        j_start++;
        pos++;
    }
    for (int i = start; i <= end; ++i) {
        arr[i] = temp[i];
    }

}

// arr:待调整数组    index: 待调整结点下标  length：数组长度
// 自上向下调整，外围调用从下向上，只有这样才能确保能找到结点正确的位置
void Sorter::_adjust(int *arr, int index, int length) {
    while ((2*index+1) < length){
        int lchild = 2*index + 1;
        int rchild = lchild + 1;
        int maxChild = (rchild < length && arr[rchild] > arr[lchild])?rchild:lchild;
        if (arr[index] >= arr[maxChild]) break;
        _swap(&arr[index], &arr[maxChild]);
        index = maxChild;
    }
}