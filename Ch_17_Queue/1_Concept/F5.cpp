// CONCEPT: Deque implementation (using array)
#include <iostream>
#include <limits.h>
using namespace std;

class Deque
{
    public:
    int* dq;
    int capacity;
    int front;
    int rear;

    Deque(int _cap)
    {
        capacity = _cap;
        dq = new int[capacity];
        front = -1;
        rear = -1;
    }

    void pushFront(int data)
    {
        if(front == 0)
        {
            cout<<"Front Overflow!!"<<endl;
            return;
        }

        if(front == -1)
        {
            front = 0;
            rear = 0;
            dq[front] = data;
            return;
        }

        front--;
        dq[front] = data;
    }

    void pushBack(int data)
    {
        if(rear == capacity-1)
        {
            cout<<"Rear Overflow!!"<<endl;
            return;
        }

        if(rear == -1)
        {
            front = 0;
            rear = 0;
            dq[rear] = data;
            return;
        }

        rear++;
        dq[rear] = data;
    }

    void popFront()
    {
        if(front == -1)
        {
            cout<<"Front Underflow!!"<<endl;
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

    void popBack()
    {
        if(rear == -1)
        {
            cout<<"Rear Underflow!!"<<endl;
            return;
        }

        if(front == rear)
        {
            front = -1;
            rear = -1;
            return;
        }

        rear--;
    }

    int getFront()
    {
        if(front == -1)
            return INT_MAX;

        return dq[front];
    }

    int getBack()
    {
        if(rear == -1)
            return INT_MAX;

        return dq[rear];
    }
    
    int getSize()
    {
        if(front == -1)
            return -1;

        return rear-front+1;
    }
};

int main()
{
    Deque dq1(5);
    dq1.pushBack(1); //1
    dq1.pushBack(2); //1, 2
    dq1.pushBack(3); //1, 2, 3
    dq1.pushBack(4); //1, 2, 3, 4

    dq1.popFront();  //2, 3, 4
    dq1.popFront();  //3, 4

    dq1.pushFront(7); //7, 3, 4
    dq1.pushFront(8); //8, 7, 3, 4

    cout<<"Front: "<<dq1.getFront()<<endl;
    cout<<"Back: "<<dq1.getBack()<<endl;
    cout<<"Size: "<<dq1.getSize()<<endl;
    cout<<endl;

    dq1.popFront(); //7, 3, 4
    dq1.popBack();  //7, 3
    cout<<"Front: "<<dq1.getFront()<<endl;
    cout<<"Back: "<<dq1.getBack()<<endl;
    cout<<endl;

    return 0;
}