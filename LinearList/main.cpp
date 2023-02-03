#include "seqList.h"
#include "singleLinkedList.h"
#include "doubleLinkedList.h"
#include <iostream>

using namespace std;

int main() {
    // test seqList.cpp
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

    // test singleLinkedList.cpp
    cout << "Hello SingleLinkedList" << endl;

    cout << "=============================" << endl;
    // test doubleLinkedList.cpp
    cout << "Hello doubleLinkedList" << endl;

    cout << "=============================" << endl;
    return 0;
}
