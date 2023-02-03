#include "seqList.h"
#include "singleLinkedList.h"
#include "doubleLinkedList.h"
#include <iostream>

using namespace std;

int main() {
    // test seqList.cpp
    /*
    cout << "Hello SeqList" << endl;
    seqList<int> array(5);
    for (int i=0;i<5;i++) {
        array.insert(i,i+1);
    }

    array.traverse();
    cout << array.length() << endl;

    for (int i=0;i<4;i++) {
        array.insert(array.length()+i,20-i);
    }

    array.traverse();
    cout << array.length() << endl;

    cout << array.search(2) << endl;
    cout << array.visit(4) << endl;
    array.remove(8);
    array.traverse();
    cout << array.length() << endl;

    cout << "============================" << endl;
     */
    // test singleLinkedList.cpp
    cout << "Hello SingleLinkedList" << endl;
    singleLinkedList<int> array2;
    for (int i=0;i<5;i++) {
        array2.insert(i,i+1);
    }

    array2.traverse();
    cout << array2.length() << endl;
    cout << array2.visit(3) << endl;
    array2.remove(3);
    cout << array2.length() << endl;
    array2.traverse();
    for (int i=0;i<5;i++) {
        array2.insert(4+i,i+1);
    }
    array2.traverse();
    cout << array2.visit(7) << endl;
    cout << array2.search(3) << endl;

    array2.insert(2,99);
    array2.traverse();

    cout << "=============================" << endl;
    // test doubleLinkedList.cpp
    cout << "Hello doubleLinkedList" << endl;

    cout << "=============================" << endl;
    return 0;
}
