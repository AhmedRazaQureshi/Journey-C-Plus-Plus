// Concept: Two Stacks in One Array
#include <iostream>
using namespace std;

class Stack
{
    private:
    int* arr;
    int size;
    int top1;
    int top2;

    public:
    Stack(int _size)
    {
        this->arr = new int[_size](); //0 se init
        this->size = _size;

        top1 = -1;
        top2 = size;
    }

    void push1(int data)
    {
        if(top2 - top1 == 1)
        {
            cout<<"Overflow"<<endl;
            return;
        }
        top1++;
        arr[top1] = data;
    }

    void push2(int data)
    {
        if(top2 - top1 == 1)
        {
            cout<<"Overflow"<<endl;
            return;
        }
        top2--;
        arr[top2] = data;
    }

    void pop1()
    {
        if(top1 == -1)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        top1--;
    }

    void pop2()
    {
        if(top2 == size)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        top2++;
    }

    void print()
    {
        for(int i=0; i<size; i++)
            cout<<arr[i]<<", ";
        cout<<endl;
    }
};

int main()
{
    Stack st1(10);

    st1.push1(5);
    st1.push1(6);
    st1.push1(7);
    st1.print();

    st1.push2(1);
    st1.push2(2);
    st1.push2(3);
    st1.print();

    st1.push1(8);
    st1.push1(9);
    st1.push1(10);
    st1.push1(11);
    st1.print();

    st1.push2(4);
    

    return 0;
}