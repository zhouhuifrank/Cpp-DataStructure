/*
 *  this.FrankZhou
 *  归并排序实现类
 */

#include "mergeSort.h"

Merge::Merge() {
}

Merge::~Merge() {
}

void Merge::sort(int *nums, int size) {
    temp = new int[size];
    sort(nums,0,size-1);
}

void Merge::sort(int *nums, int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = low + ((high-low) >> 1);
    sort(nums,low,mid);
    sort(nums,mid+1,high);

    merge(nums,low,mid,high);
}

void Merge::merge(int *nums, int low, int mid, int high) {
    int left = low, right = mid+1;
    int k = 0;
    // 合并
    while (left <= mid && right <=high) {
        if (nums[left] < nums[right]) temp[k++] = nums[left++];
        else temp[k++] = nums[right++];
    }

    while (left <= mid) temp[k++] = nums[left++];
    while (right <= high) temp[k++] = nums[right++];

    // 复制到原数组
    for (int i=low,k=0;i<=high;i++) {
        nums[i] = temp[k++];
    }
}

void Merge::merge2(int *nums, int low, int mid, int high) {
    // 先需要归并的元素存入需要临时数组
    for (int i=low;i<=high;i++) {
        temp[i] = nums[i];
    }

    // 一个for循环中就可以完成归并
    int left = low,right = mid+1;
    for (int k = low;k<=high;k++) {
        if (left == mid+1) {
            // 左边数组已排序完成
            nums[k] = temp[right++];
        } else if (right == high+1) {
            // 右边数组已排序完成
            nums[k] = temp[left++];
        } else if (temp[left] < temp[right]) {
            nums[k] = temp[left++];
        } else {
            nums[k] = temp[right++];
        }
    }
}
