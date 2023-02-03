/*
 *  this.FrankZhou
 *  双链表
 */
#ifndef DATASTRUCTURE_DOUBLELINKEDLIST_H
#define DATASTRUCTURE_DOUBLELINKEDLIST_H

#include <iostream>

template <class T>
class doubleList {
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
class doubleLinkedList: public doubleList<T> {
private:
    struct node {
        T data;
        node* prev;
        node* next;
        node(const T &x,node* p=nullptr,node* n=nullptr): data(x),prev(p),next(n) {};
        node (): prev(nullptr),next(nullptr) {};
        ~node() {};
    };

    node* head;
    node* tail;
    int currentLength;
    node* move(int i) const {
        node *p = head;

        while (i-- >= 0) {
            p = p->next;
        }
        return p;
    }
public:
    doubleLinkedList();
    ~doubleLinkedList();
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
doubleLinkedList<T>::doubleLinkedList() {
    // head的prev和tail和next指向nullptr，不为循环链表
    head = new node;
    head->next = tail = new node;
    tail->prev = head;
    currentLength = 0;
}

template <class T>
doubleLinkedList<T>::~doubleLinkedList() {
    clear();
    delete head;
    delete tail;
}

template <class T>
void doubleLinkedList<T>::clear() {
    node *p = head->next, *q;

    head->next = nullptr;
    while (p) {
        q = p->next;
        delete p;
        p = q;
    }

    tail->prev = nullptr;
    currentLength = 0;
}

template <class T>
int doubleLinkedList<T>::length() const {
    return currentLength;
}

template <class T>
bool doubleLinkedList<T>::isEmpty() const {
    return currentLength == 0;
}

template <class T>
void doubleLinkedList<T>::insert(int i, const T &item) {
    if (i < 0 || i > currentLength) {
        return;
    }

    node *pos = move(i);
    node *temp = new node(item,pos->prev,pos);
    pos->prev->next = temp;
    pos->prev = temp;

    currentLength++;
}

template <class T>
void doubleLinkedList<T>::remove(int i) {
    if (i < 0 || i >= currentLength) {
        return;
    }

    node *pos = move(i);
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;

    delete pos;
    currentLength--;
}

template <class T>
int doubleLinkedList<T>::search(const T &item) const {
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
T doubleLinkedList<T>::visit(int i) const {
    return move(i)->data;
}

template <class T>
void doubleLinkedList<T>::traverse() const {
    node *p = head->next;

    while (p != tail) {
        std::cout << p->data << " ";
        p = p->next;
    }

    std::cout << std::endl;
}

#endif //DATASTRUCTURE_DOUBLELINKEDLIST_H
