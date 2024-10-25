//CONCEPT: Linear Queue STL
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    //1. Creation
    queue<int> q1;

    //2. Insertion
    q1.push(10);
    q1.push(20);
    q1.push(30);
    cout<<"Front:"<<q1.front()<<endl;
    cout<<"Back:"<<q1.back()<<endl;
    cout<<endl;

    //3. Deletion
    q1.pop();
    cout<<"Front:"<<q1.front()<<endl;
    cout<<"Back:"<<q1.back()<<endl;
    cout<<endl;

    //4. Size & Emptyness
    cout<<"Size:"<<q1.size()<<endl;
    cout<<"Is empty? : "<<q1.empty()<<endl;
    cout<<endl;

    //5. Swap queues
    queue<int> q2({7,8,9});
    q2.swap(q1);
    cout<<"Front of q1:"<<q1.front()<<endl;
    cout<<"Back of q1:"<<q1.back()<<endl;
    cout<<"Front of q2:"<<q2.front()<<endl;
    cout<<"Back of q2:"<<q2.back()<<endl;
    cout<<endl;

    return 0;
}