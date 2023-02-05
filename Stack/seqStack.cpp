/*
 *  this.FrankZhou
 *  顺序栈模板类
 */

#include <iostream>

template <class T>
class stack {
public:
    virtual void push(const T &item) = 0;
    virtual T pop() = 0;
    virtual bool isEmpty() const = 0;
    virtual T top() const = 0;
    virtual ~stack() {};
};

template <class T>
class seqStack: public stack<T> {
private:
    T *data;
    int top_ptr;
    int maxSize;
    void doubleSpace();
public:
    seqStack(int initSize=10);
    ~seqStack();
    void push(const T &item);
    T pop();
    bool  isEmpty() const;
    T top() const;
};

template <class T>
void seqStack<T>::doubleSpace() {
    T *temp = data;

    data = new T[maxSize*2];
    for (int i=0;i<maxSize;i++) {
        data[i] = temp[i];
    }
    maxSize *= 2;
    delete [] temp;
}

template <class T>
seqStack<T>::seqStack(int initSize) {
    data = new T[initSize];
    maxSize = initSize;
    top_ptr = -1;
}

template <class T>
seqStack<T>::~seqStack() {
    delete [] data;
}

template <class T>
void seqStack<T>::push(const T &item) {
    if (top_ptr == maxSize-1) {
        doubleSpace();
    }
    data[++top_ptr] = item;
}

template <class T>
T seqStack<T>::pop() {
    return data[top_ptr--];
}

template <class T>
bool seqStack<T>::isEmpty() const {
    return top_ptr == -1;
}

template <class T>
T seqStack<T>::top() const {
    return data[top_ptr];
}

int main() {
    seqStack<int> stk;

    stk.push(2);
    std::cout << stk.top() << std::endl;
    stk.push(3);
    stk.push(7);
    std::cout << stk.top() << std::endl;
    stk.push(9);
    std::cout << stk.pop() << std::endl;
    std::cout << stk.top() << std::endl;

    return 0;
}