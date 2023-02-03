/*
 *  this.FrankZhou
 *  单链表模板类
 */
#ifndef DATASTRUCTURE_SINGLELINKEDLIST_H
#define DATASTRUCTURE_SINGLELINKEDLIST_H

#include <iostream>

template <class E>
class linkedList {
public:
    virtual void clear() = 0;
    virtual int length() const = 0;
    virtual bool isEmpty() const = 0;
    virtual void insert(int i,const E &item) = 0;
    virtual void remove(int i) = 0;
    virtual int search(const E &item) const = 0;
    virtual E visit(int i) const = 0;
    virtual void traverse() const = 0;
};


template <class E>
class singleLinkedList: public linkedList<E> {
private:
    struct node {
        E data;
        node* next;
        node(const E &x, node* n = nullptr): data(x),next(n) {};
        node(const E &x): data(x),next(nullptr) {};
        ~node() {};
    };

    node* head;
    int currentLength;
    node* find(int i);
public:
    singleLinkedList();
    ~singleLinkedList();
    void clear();
    int length() const;
    bool isEmpty() const;
    void insert(int i,const E &item);
    void remove(int i);
    int search(const E &item) const;
    E visit(int i) const;
    void traverse() const;
};

#endif //DATASTRUCTURE_SINGLELINKEDLIST_H
