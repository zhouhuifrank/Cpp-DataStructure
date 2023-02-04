/*
 *  this.FrankZhou
 *  并查集模板类
 */

#include <iostream>

class disJointSet {
private:
    // parent指向每个结点父结点的指针
    int *parent;
    // 维护每个集合的大小
    int *size;
    // 集合的个数
    int count;
    int find(int x);
public:
    disJointSet(int initSize);
    ~disJointSet();
    void merge(int p,int q);
    bool isConnected(int p,int q);
    int getCount();
};

int disJointSet::find(int x) {
    if (parent[x] != x) {
        // 不是根结点，则递归
        parent[x] = find(parent[x]);
    }

    return parent[x];
}

disJointSet::disJointSet(int initSize) {
    parent = new int[initSize];
    size = new int[initSize];
    count = initSize;
    for (int i=0;i<initSize;i++) {
        // 根结点的父亲指针指向自己
        parent[i] = i;
        size[i] = 1;
    }
}

disJointSet::~disJointSet() {
    delete [] parent;
    delete [] size;
}

void disJointSet::merge(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    if (rootP == rootQ) return;
    // 把Q所属的集合连接到P所属集合下
    parent[rootQ] = rootP;
    size[rootP] += size[rootQ];
    count--;
}

bool disJointSet::isConnected(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    return rootQ == rootP;
}

int disJointSet::getCount() {
    return count;
}

int main() {
    disJointSet djs(10);
    djs.merge(1,2);
    std::cout << djs.getCount() << std::endl;
    djs.merge(2,3);
    djs.merge(5,6);
    std::cout << djs.getCount() << std::endl;
    std::cout << djs.isConnected(1,3) << std::endl;
    djs.merge(3,4);
    djs.merge(4,5);
    std::cout << djs.getCount() << std::endl;

    return 0;
}