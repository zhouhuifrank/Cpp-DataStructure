/*
 *  this.FrankZhou
 *  归并排序
 */
#ifndef DATASTRUCTURE_QUICKSORT_H
#define DATASTRUCTURE_QUICKSORT_H

class QSort {
private:
    // 阈值 数据量小于cutoff使用插入排序 数据量大于cutoff使用快速排序
    int cutoff;
    int partition(int nums[],int left,int right);
public:
    QSort();
    ~QSort();
    void sort(int nums[],int size);
    void quickSort(int nums[],int left,int right);
    void insertSort(int nums[],int size);
};

#endif //DATASTRUCTURE_QUICKSORT_H
