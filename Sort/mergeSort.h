/*
 *  this.FrankZhou
 *  归并排序
 */
#ifndef DATASTRUCTURE_MERGESORT_H
#define DATASTRUCTURE_MERGESORT_H

class Merge {
private:
    int *temp;
public:
    Merge();
    ~Merge();
    void sort(int nums[],int size);
    void sort(int nums[],int low,int high);
    void merge(int nums[],int low,int mid,int high);
    void merge2(int nums[],int low,int mid,int high);
};

#endif //DATASTRUCTURE_MERGESORT_H
