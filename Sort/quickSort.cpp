/*
 *  this.FrankZhou
 *  快速排序
 */

#include "quickSort.h"
#include <cstdlib>

QSort::QSort() {
    cutoff = 10;
}

QSort::~QSort() {
}

void QSort::sort(int *nums, int size) {
    if (size < cutoff) {
        insertSort(nums,size);
    } else {
        quickSort(nums,0,size-1);
    }
}

int QSort::partition(int *nums, int left, int right) {
    int random =  rand()%(right-left+1)+left;
    int pivot = nums[random];
    int i = left-1, j = right+1;
    while (i < j) {
        while (nums[++i] < pivot);
        while (nums[--j] > pivot);
        if (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    return j;
}

void QSort::quickSort(int *nums, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = partition(nums,left,right);

    quickSort(nums,left,mid);
    quickSort(nums,mid+1,right);
}

void QSort::insertSort(int *nums, int size) {
    for (int i=1;i<size;i++) {
        // 待排序数
        int temp = nums[i];
        int j;
        for (j=i;j>0;j--) {
            if (temp < nums[j-1]) {
                // 移出空位
                nums[j] = nums[j-1];
            } else {
                break;
            }
        }
        nums[j] = temp;
    }
}