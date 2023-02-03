/*
 *  this.FrankZhou
 *  双链表
 */
#ifndef DATASTRUCTURE_DOUBLELINKEDLIST_H
#define DATASTRUCTURE_DOUBLELINKEDLIST_H

#include <iostream>

template <class E>
class doubleLinkedList: public list<E> {
private:
    struct node {
        E data;
        node* prev;
        node* next;
        node(const E &x,node* p=nullptr,node* n=nullptr): data(x),prev(p),next(n) {};
        node (const E &x): data(x),prev(nullptr),next(nullptr) {};
        ~node() {};
    };

    node* head;
    node* tail;
    int currentLength;
    node* find(int i);
public:
    doubleLinkedList();
    void clear();
    int length() const;
    void insert(int i,const E &item);
    void remove(int i);
    int search(const E &item) const;
    E visit(int i) const;
    void traverse() const;
    ~doubleLinkedList();
};

#endif //DATASTRUCTURE_DOUBLELINKEDLIST_H
