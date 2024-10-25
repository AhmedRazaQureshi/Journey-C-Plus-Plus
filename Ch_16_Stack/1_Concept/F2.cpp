// Concept: Stack implement using Array
#include <iostream>
using namespace std;

class Stack
{
    private:
    int* arr;
    int top;
    int size;

    public:
    Stack(int _size)
    {
        this->arr = new int[_size];
        this->size = _size;
        this->top = -1;
    }

    void push(int data)
    {
        if(size - (top+1) <= 0)
        {
            cout<<"Overflow"<<endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        top--;
    }

    int getTop()
    {
        if(top == -1)
        {
            cout<<"Empty stack"<<endl;
        }
        return arr[top];
    }

    int getSize()
    {
        return top+1;
    }

    bool isEmpty()
    {
        if(top == -1)
            return true;
        return false;
    }
};

int main()
{
    Stack st1(10);
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);
    st1.push(100);

    cout<<"Size: "<<st1.getSize()<<endl;
    cout<<"Top: "<<st1.getTop()<<endl;

    return 0;
}