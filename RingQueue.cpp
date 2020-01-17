#include <iostream>

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
    RingQueue() : pHead(-1), pTail(0), numberOfElement(0), sizeOfElement(5), arr(nullptr)
    {
    }

    RingQueue(int size) : pHead(-1), pTail(0), numberOfElement(0), arr(nullptr)
    {
        this->sizeOfElement = sizeOfElement;
    }

    int pop() override
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

    void push(int x) override
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
        std::cout << "pHead: "<<pHead << std::endl;
        std::cout << "pTail: "<<pTail << std::endl;
       
        numberOfElement++;
    }

    void Init() override
    {
        arr = new int[numberOfElement];
    }

    void Destroy() override
    {
        delete[] arr;
        arr = nullptr;
        pHead = -1;
        pTail =0;
        sizeOfElement = 5;
        numberOfElement = 0;

    }
    bool hasFull()
    {
        return numberOfElement == sizeOfElement ? true: false;
    }
    bool isEmpty()
    {
        return pHead == -1 ? true:false;
    }
    void Display()
    {
        for(int i = pHead, j = 0 ;j < numberOfElement;j++,i =(++i) % sizeOfElement )
        {

            std::cout<<"i : "<<i << " value : " <<*(arr+i) << " ";
             std::cout << "" << std::endl;
        }
       
    }

    void Input()
    {
        std::cout << "input size of queue: " << std::endl;
        int size = 0;
        std::cin>>size;
        this->sizeOfElement = size;
        Init();
        for(int i = 0 ; i < sizeOfElement;i++)
        {
            std::cout << "input value at "<<i<<": " ;
            int number =0;
            std::cin>>number;
            std::cout<<""<<std::endl;
            push(number);
        }
        std::cout << "pop value is : "<< pop() << std::endl;
        Display();
    }
};

int main(int argc, const char **argv)
{
    RingQueue ringQueue;
    ringQueue.Input();
    return 0;
}