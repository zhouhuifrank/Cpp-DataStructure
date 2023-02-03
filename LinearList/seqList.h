/*
 *  this.FrankZhou
 *  顺序表模板类
 */
#ifndef DATASTRUCTURE_SEQLIST_H
#define DATASTRUCTURE_SEQLIST_H

#include <iostream>

// list抽象类
template <class T>
class list {
public:
    virtual void clear() = 0;
    virtual int length() const = 0;
    virtual bool isEmpty() const = 0;
    virtual void insert(int i,const T &item) = 0;
    virtual void remove(int i) = 0;
    virtual int search(const T &item) const = 0;
    virtual T visit(int i) const = 0;
    virtual void traverse() const = 0;
};

// 模板类
template <class T>
class seqList: public list<T> {
private:
    T *data;
    int currentLength;
    int maxSize;
    // 动态扩容函数
    void doubleSpace();
public:
    seqList(int initSize=10);
    ~seqList();
    void clear();
    int length() const;
    bool isEmpty() const;
    void insert(int i,const T &item);
    void remove(int i);
    int search(const T &item) const;
    T visit(int i) const;
    void traverse() const;
};

// 实现
template <class T>
void seqList<T>::doubleSpace() {
    T *temp = data;

    // 重新申请一块内存
    maxSize *= 2;
    data = new T[maxSize];
    for (int i = 0;i < currentLength;i++) {
        data[i] = temp[i];
    }
    delete [] temp;
}

template <class T>
seqList<T>::seqList(int initSize) {
    data = new int[initSize];
    maxSize = initSize;
    currentLength = 0;
}

template <class T>
seqList<T>::~seqList() {
    delete [] data;
}

template <class T>
void seqList<T>::clear() {
    currentLength = 0;
}

template <class T>
int seqList<T>::length() const {
    return currentLength;
}

template <class T>
bool seqList<T>::isEmpty() const {
    return currentLength == 0;
}

template <class T>
void seqList<T>::insert(int i, const T &item) {
    if (currentLength == maxSize) {
        doubleSpace();
    }

    int pos;
    for (pos = currentLength;pos > i;pos--) {
        data[pos] = data[pos-1];
    }
    data[pos] = item;
    currentLength++;
}

template <class T>
void seqList<T>::remove(int i) {
    if (isEmpty()) {
        return;
    }

    int pos;
    for (pos = i;i < currentLength-1;pos++) {
        data[pos] = data[pos+1];
    }
    currentLength--;
}

template <class T>
int seqList<T>::search(const T &item) const {
    int i;
    for (i = 0;i < currentLength && data[i] != item;i++);

    // 元素不存在
    if (i == currentLength) return -1;

    return i;
}

template <class T>
T seqList<T>::visit(int i) const {
    return data[i];
}

template <class T>
void seqList<T>::traverse() const {
    for (int i = 0;i < currentLength;i++) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;
}


#endif //DATASTRUCTURE_SEQLIST_H
