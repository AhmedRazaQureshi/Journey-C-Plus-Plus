//CONCEPT: Linear Queue implementation (using array)
#include <iostream>
#include <limits.h>
using namespace std;

class Queue
{
    public:
    int* q;
    int front;
    int rear;
    int size;

    Queue(int _size)
    {
        size = _size;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        if(rear+1 == size)
        {
            cout<<"Overflow!!"<<endl;
            return;
        }

        if(rear == -1)
        {
            front = 0;
            rear = 0;
            q[rear] = data;
            return;
        }

        rear++;
        q[rear] = data;
    }

    void pop()
    {
        if(front == -1)
        {
            cout<<"Underflow!!"<<endl;
            return;
        }

        if(front == rear)
        {
            front = -1;
            rear = -1;
            return;
        }

        front++;
    }

    int getFront()
    {
        if(front == -1)
        {
            cout<<"Queue is empty"<<endl;
            return INT_MAX;
        }
        
        return q[front];
    }

    int getBack()
    {
        if(rear == -1)
        {
            cout<<"Queue is empty"<<endl;
            return INT_MAX;
        }

        return q[rear];
    }

    bool isEmpty()
    {
        if(front == -1)
            return 1;

        return 0;
    }

    int getSize()
    {
        if(front == -1)
            return -1;

        return (rear-front+1);
    }

};

int main()
{
    Queue q1(10);
    q1.push(10);
    q1.push(20);
    q1.push(30);

    cout<<"Front: "<<q1.getFront()<<endl;
    cout<<"Back: "<<q1.getBack()<<endl;
    cout<<"Size: "<<q1.getSize()<<endl;
    cout<<endl;

    q1.pop();
    cout<<"Front: "<<q1.getFront()<<endl;
    cout<<"Back: "<<q1.getBack()<<endl;
    cout<<endl;

    cout<<"Is empty? : "<<q1.isEmpty()<<endl;

    return 0;
}