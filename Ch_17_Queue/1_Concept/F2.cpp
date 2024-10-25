//CONCEPT: Deque STL
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    //1. Creation & Insertion
    deque<int> dq1;
    dq1.push_front(1); //1
    dq1.push_front(2); //2, 1
    dq1.push_back(3); //2, 1, 3
    dq1.push_back(4); //2, 1, 3, 4
    cout<<"Front: "<<dq1.front()<<endl;
    cout<<"Back: "<<dq1.back()<<endl;
    cout<<"Is empty ? : "<<dq1.empty()<<endl;
    cout<<endl;

    //2. Deletion
    dq1.pop_back();  //2, 1, 3
    dq1.pop_front(); //1, 3
    cout<<"Front: "<<dq1.front()<<endl;
    cout<<"Back: "<<dq1.back()<<endl;
    cout<<endl;

    //3. Swap
    deque<int> dq2({7,8,9});
    dq1.swap(dq2);
    cout<<"dq1 :--"<<endl;
    cout<<"Front: "<<dq1.front()<<endl;
    cout<<"Back: "<<dq1.back()<<endl;
    cout<<"dq2 :--"<<endl;
    cout<<"Front: "<<dq2.front()<<endl;
    cout<<"Back: "<<dq2.back()<<endl;


    

    return 0;
}