/*
 *  this.FrankZhou
 *  节点类实现类
 *  双向链表实现类
 *  LRUCaches实现类
 */

#include "LRUCache.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <unordered_map>

// Node节点实现类
Node::Node(int key, int value, Node *prev, Node *next) {
    this->key = key;
    this->value = value;
    this->prev = prev;
    this->next = next;
}

Node::Node() {
    this->prev = nullptr;
    this->next = nullptr;
}

Node::~Node() {
}


// DoubleLinkList双向链表实现类
Node* DoubleLinkList::move(int i) const {

}

DoubleLinkList::DoubleLinkList() {

}

DoubleLinkList::~DoubleLinkList() {

}

bool DoubleLinkList::isEmpty() const {

}

int DoubleLinkList::length() const {

}

void DoubleLinkList::addFromLast(int key, int value) {

}

void DoubleLinkList::removeFromFirst() {

}

void DoubleLinkList::remove() {

}

// LRUCache实现类
void LRUCache::makeRecently(int key) {

}

void LRUCache::addRecently(int key, int value) {

}

void LRUCache::deleteKey(int key) {

}

void LRUCache::removeLeastRecently() {

}

LRUCache::LRUCache(int capacity) {

}

LRUCache::~LRUCache() noexcept {

}

int LRUCache::get(int key) const {

}

void LRUCache::put(int key, int value) {

}
