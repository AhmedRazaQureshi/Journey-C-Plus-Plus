// Concept: Stack STL
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    // 1: Creation
    stack<int> st1;

    // 2: Initialization
    st1.push(30);
    st1.push(20);
    st1.push(10);

    // 3: Copying
    stack<int> st2 = st1;

    // 4: Accessing, Size
    cout << "Top: " << st1.top() << endl;
    cout << "Size: " << st1.size() << endl;

    // 5: Deletion
    st1.pop(); // Returns nothing
    cout << "New Top: " << st1.top() << endl;

    // 6: Emptyness check
    cout << "Is st1 empty? : " << st1.empty() << endl;

    // 7. Printing
    cout << "Elements of st1 : ";
    while (!st1.empty())
    {
        cout << st1.top() << ",";
        st1.pop();
    }
    cout << endl;

    // 8: Initialization w/o push
    vector<int> input = {1,2,3,4,5};
    stack<int, vector<int>> st3(input);
    cout<<"Top of st3: "<<st3.top()<<endl;



    // 9: Swap stacks
    vector<int> input2 = {6,7,8,9,10};
    stack<int, vector<int>> st4(input2);
    st3.swap(st4);
    cout<<endl;
    cout<<"Top of st3: "<<st3.top()<<endl;
    cout<<"Top of st4: "<<st4.top()<<endl;


    return 0;
}