/*
 *  this.FrankZhou
 *  链接栈
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
class linkStack: public stack<T> {
private:
    struct node {
        T data;
        node* next;
        node(const int &item,node* n=nullptr): data(item),next(n) {};
        node(): next(nullptr) {};
        ~node() {};
    };
    // 链接栈不需要头节点，当栈为空的时候，栈顶指针为nullptr
    node* head;
public:
    linkStack();
    ~linkStack();
    void push(const T &item);
    T pop();
    bool isEmpty() const;
    T top() const;
};

template <class T>
linkStack<T>::linkStack() {
    head = nullptr;
}

template <class T>
linkStack<T>::~linkStack() {
    node* temp;

    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void linkStack<T>::push(const T &item) {
    head = new node(item,head);
}

template <class T>
T linkStack<T>::pop() {
    node* temp = head;
    head = head->next;
    T data = temp->data;
    delete temp;

    return data;
}

template <class T>
bool linkStack<T>::isEmpty() const {
    return head == nullptr;
}

template <class T>
T linkStack<T>::top() const {
    return head->data;
}

int main() {
    linkStack<int> stk;

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
