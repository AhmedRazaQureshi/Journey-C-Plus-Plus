// Vector basics
#include <iostream>
#include <vector>
using namespace std;

/* 
1. Vector operations:

v.push_back(5);  -> Inserts 5 at the end
v[0] = 20;       -> Modifies v[0]
v.pop_back();    -> Deletes element at the end
v.size();        -> Returns number of elements currently stored in v
v.capacity();    -> Returns number of elements v can hold before it needs to allocate more memory
v.clear();       -> Deletes all elements in v
v.front();       -> Returns first element
v.back();        -> Returns last element
v.empty();       -> 1=>Yes Empty  0=>Not Empty
v.begin();       -> Returns address of v[0];
v.end()-1;       -> Returns address of v[n-1];



2. Vector iterators: Pointer to an address of an element of vector

vector<int> :: iterator p;
p = v.begin();   -> Points to v[0]
p = v.begin()+2; -> Points to v[2]
p = v.end()-1    -> Points to v[n-1]


3. Miscellaneous
vector<int> v(10, -3);  -> Size 10, all elements -3
vector<int> v(10);      -> Size 10, all elements 0

*/

int main()
{   
    //Printing v's elements through iterator
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> :: iterator p;
    cout<<"Printing v1 through iterator: "<<endl;
    for(p = v1.begin(); p != v1.end(); p++)
        cout<<(*p)<<", ";
    cout<<endl<<endl;



    //2D Vectors
    int rows = 4;
    int cols = 3;
    vector<vector<int>> v2(rows, vector<int>(cols, -1));



    //2D Vector with dynamic rows
    vector<int> row1 = {1,2,3};
    vector<int> row2 = {4,5};
    vector<int> row3 = {6};

    vector<vector<int>> v3;
    v3.push_back(row1);
    v3.push_back(row2);
    v3.push_back(row3);
    
    cout<<"Printing v3: "<<endl;
    for(auto i: v3)
    {
        for(auto j: i)
            cout<<j<<",";
        cout<<endl;
    }
    cout<<endl;
        
    return 0;
}