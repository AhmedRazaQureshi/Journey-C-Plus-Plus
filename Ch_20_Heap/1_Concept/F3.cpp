// Concept: Heap STL (priority_queue)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //1. MaxHeap
    priority_queue<int> pq;
    pq.push(5);
    pq.push(1);
    pq.push(4);
    pq.push(2);
    pq.push(3);
    pq.push(6);

    cout<<"Top: "<<pq.top()<<endl;

    pq.pop();
    cout<<"Top: "<<pq.top()<<endl;

    cout<<"Size: "<<pq.size()<<endl;

    cout<<"Is-Empty: "<<pq.empty()<<endl;

    cout<<"____________________________________"<<endl;

    //2. MinHeap
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(5);
    pq2.push(1);
    pq2.push(4);
    pq2.push(2);
    pq2.push(3);
    pq2.push(6);

    cout<<"Top: "<<pq2.top()<<endl;

    pq2.pop();
    cout<<"Top: "<<pq2.top()<<endl;

    cout<<"Size: "<<pq2.size()<<endl;

    cout<<"Is-Empty: "<<pq2.empty()<<endl;



    return 0;
}