#include <bits/stdc++.h>
using namespace std;
// 手写队列模板
template <class T>
class FQueue {
  protected:
    struct InQueueNode {
        T data;
        InQueueNode *next;
        InQueueNode(T val) : data(val), next(nullptr) {}
    };
    InQueueNode *pHead;
    InQueueNode *pTail;
    int count;

  public:
    FQueue() : pHead(nullptr), pTail(nullptr), count(0) {}
    bool empty() const { return count == 0; }
    size_t size() const { return count; }
    T head() const { return pHead->data; }
    T tail() const { return pTail->data; }
    void push(T data) {
        if (pHead == nullptr) {
            pHead = pTail = new InQueueNode(data);
            count++;
            return;
        }
        pTail->next = new InQueueNode(data);
        pTail = pTail->next;
        count++;
    }
    void pop() {
        if (pHead == nullptr) {
            cout << "Error: Empty queue!" << endl;
            return;
        }
        InQueueNode *tmp = pHead;
        pHead = pHead->next;
        if (pHead == nullptr)
            pTail = nullptr;
        delete tmp;
        count--;
    }
};