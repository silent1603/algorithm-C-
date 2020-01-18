#include "RingQueue.h"

RingQueue::RingQueue() : pHead(-1), pTail(0), numberOfElement(0), sizeOfElement(5), arr(nullptr)
{
}

RingQueue::RingQueue(int size) : pHead(-1), pTail(0), numberOfElement(0), arr(nullptr)
{
    this->sizeOfElement = sizeOfElement;
}

int RingQueue::pop()
{
    if (isEmpty())
    {
        std::cout << "queue is empty" << std::endl;
        return -1;
    }
    int item = 0;
    item = *(arr + pHead);
    pHead = ++pHead % sizeOfElement;
    numberOfElement--;
    return item;
}

void RingQueue::push(int x)
{
    if (hasFull())
    {
        std::cout << "queue is full" << std::endl;
        return;
    }
    if (isEmpty())
    {
        pHead++;
        *(arr + pHead) = x;
    }
    else
    {
        pTail = ++pTail % sizeOfElement;
        *(arr + pTail) = x;
    }
    std::cout << "pHead: " << pHead << std::endl;
    std::cout << "pTail: " << pTail << std::endl;

    numberOfElement++;
}

void RingQueue::Init()
{
    arr = new int[numberOfElement];
}

void RingQueue::Destroy()
{
    delete[] arr;
    arr = nullptr;
    pHead = -1;
    pTail = 0;
    sizeOfElement = 5;
    numberOfElement = 0;
}
bool RingQueue::hasFull()
{
    return numberOfElement == sizeOfElement ? true : false;
}
bool RingQueue::isEmpty()
{
    return pHead == -1 ? true : false;
}
void RingQueue::Display()
{
    for (int i = pHead, j = 0; j < numberOfElement; j++, i = (++i) % sizeOfElement)
    {

        std::cout << "i : " << i << " value : " << *(arr + i) << " ";
        std::cout << "" << std::endl;
    }
}

void RingQueue::Input()
{
    std::cout << "input size of queue: " << std::endl;
    int size = 0;
    std::cin >> size;
    this->sizeOfElement = size;
    Init();
    for (int i = 0; i < sizeOfElement; i++)
    {
        std::cout << "input value at " << i << ": ";
        int number = 0;
        std::cin >> number;
        std::cout << "" << std::endl;
        push(number);
    }
    std::cout << "pop value is : " << pop() << std::endl;
    Display();
}
