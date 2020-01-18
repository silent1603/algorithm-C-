#include <iostream>
#ifndef RINGQUEUE_H 
#define RINGQUEUE_H

class QueueBluePrint
{
public:
    virtual int pop() = 0;
    virtual void push(int x) = 0;
    virtual void Init() = 0;
    virtual void Destroy() = 0;
};

class RingQueue : public QueueBluePrint
{
private:
    int pHead;
    int pTail;
    int numberOfElement;
    int sizeOfElement;
    int *arr;

public:
    RingQueue();
    RingQueue(int size);
    int pop() override;
    void push(int x) override;
    void Init() override;
    void Destroy() override;
    bool hasFull();
    bool isEmpty();
    void Display();
    void Input();
};
#endif // !1