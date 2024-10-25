// CONCEPT: Circular Queue implementation (using array)
#include <iostream>
#include <limits.h>
using namespace std;

class CirQue
{
    public:
    int* cq;
    int front;
    int rear;
    int capacity;

    CirQue(int _cap)
    {
        capacity = _cap;
        cq = new int[capacity];
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        if( (rear+1)%capacity == front)
        {
            cout<<"Overflow!!"<<endl;
            return;
        }

        if(rear == -1)
        {
            front = 0;
            rear = 0;
            cq[rear] = data;
            return;
        }

        rear = (rear+1)%capacity;
        cq[rear] = data;
    }

    void pop()
    {
        if(front == -1)
        {
            cout<<"Underflow!!"<<endl;
            return;
        }

        if(rear==front)
        {
            rear = -1;
            front = -1;
            return;
        }

        front = (front+1)%capacity;
    }

    int getFront()
    {
        if(front == -1)
            return INT_MAX;

        return cq[front];
    }

    int getBack()
    {
        if(rear == -1)
            return INT_MAX;

        return cq[rear];
    }

    bool isEmpty()
    {
        if(front == -1)
            return true;

        return false;
    }

    int getSize()
    {
        if(front == -1)
            return -1;

        return (rear-front+capacity)%capacity + 1;
    }

};

int main()
{
    CirQue cq1(5);
    cq1.push(10);
    cq1.push(20);
    cq1.push(30);
    cq1.push(40);
    cq1.push(50);

    cout<<"Front: "<<cq1.getFront()<<endl;
    cout<<"Back: "<<cq1.getBack()<<endl;
    cout<<"Size: "<<cq1.getSize()<<endl;
    cout<<"Is empty ? : "<<cq1.isEmpty()<<endl;
    cout<<endl;

    cq1.pop();
    cq1.pop();

    cq1.push(60);
    cq1.push(70);
    cout<<"Front: "<<cq1.getFront()<<endl;
    cout<<"Back: "<<cq1.getBack()<<endl;
    cout<<endl;






    return 0;
}
