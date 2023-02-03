/*
 *  this.FrankZhou
 *  单链表模板类
 */
#ifndef DATASTRUCTURE_SINGLELINKEDLIST_H
#define DATASTRUCTURE_SINGLELINKEDLIST_H

#include <iostream>

template <class T>
class linkedList {
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


template <class T>
class singleLinkedList: public linkedList<T> {
private:
    struct node {
        T data;
        node *next;
        node(const T &x, node *n = nullptr): data(x),next(n) {};
        node(): next(nullptr) {};
        ~node() {};
    };

    // head为虚拟结点(dummy)
    node* head;
    int currentLength;
    node* move(int i) const {
        node *p = head;
        while (i-- >= 0) {
            p = p->next;
        }
        return p;
    }
public:
    singleLinkedList();
    ~singleLinkedList();
    void clear();
    int length() const;
    bool isEmpty() const;
    void insert(int i,const T &item);
    void remove(int i);
    int search(const T &item) const;
    T visit(int i) const;
    void traverse() const;
};

template <class T>
singleLinkedList<T>::singleLinkedList() {
    head = new node();
    currentLength = 0;
}

template <class T>
singleLinkedList<T>::~singleLinkedList() {
    clear();
    delete head;
}

template <class T>
void singleLinkedList<T>::clear() {
    node *p = head->next, *q;

    head->next = nullptr;
    while (p) {
        q = p->next;
        delete q;
        p = q;
    }
    currentLength = 0;
}

template <class T>
int singleLinkedList<T>::length() const {
    return currentLength;
}

template <class T>
bool singleLinkedList<T>::isEmpty() const {
    return currentLength == 0;
}

template <class T>
void singleLinkedList<T>::insert(int i, const T &item) {
    if (i < 0 || i > currentLength) {
        return;
    }

    // i等于1时为头节点
    node *prev = move(i-1);
    prev->next = new node(item,prev->next);
    currentLength++;
}

template <class T>
void singleLinkedList<T>::remove(int i) {
    if (i < 0 || i >= currentLength) {
        return;
    }

    node *prev = move(i-1);
    node *temp = prev->next;
    prev->next = temp->next;
    delete temp;
    currentLength--;
}

template <class T>
int singleLinkedList<T>::search(const T &item) const {
    node *p = head->next;

    int count = 0;
    while (p != nullptr && p->data != item) {
        count++;
        p = p->next;
    }

    if (p == nullptr) {
        return -1;
    }

    return count;
}

template <class T>
T singleLinkedList<T>::visit(int i) const {
    return move(i)->data;
}

template <class T>
void singleLinkedList<T>::traverse() const {
    node *p = head->next;

    while (p != nullptr) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

#endif //DATASTRUCTURE_SINGLELINKEDLIST_H
