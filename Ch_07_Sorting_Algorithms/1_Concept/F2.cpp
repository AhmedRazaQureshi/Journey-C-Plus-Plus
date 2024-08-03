//Concept: Sort using STL
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//2.1: Custom comparator for v2
bool cmpForV2(int a, int b)
{
    return a > b; //DESC.
}

//2.2: Custom comparator for s2
bool cmpForS2(string a, string b)
{
    //Based on length of string (DESC.)
    return a.length() > b.length(); 
}

//2.3: Custom comparator for p2 
bool cmpForP2(pair<int,string> a, pair<int,string> b)
{
    //Based on p2.second && DESC. lexicographic order of the string
    string sA = a.second;
    string sB = b.second;

    int n = min(sA.length(), sB.length());

    for(int i=0; i<n; i++)
        if(sA[i] > sB[i])
            return true;       

    return false;    
}


int main()
{
    //1: Sort in ascending order
    vector<int> v1 = {2,5,1,3,9,6,4,8,7};
    vector<string> s1 = {"xyz","pqr","def","abc"};
    vector<pair<int,string>> p1 = {{3,"abc"}, {1,"xyz"}, {2,"pqr"}, {4,"def"}, {5,"ijk"}};
    string name = "AhmedRazaQureshi";
    
    sort(v1.begin(), v1.end());
    cout<<"V1 (inc): ";
    for(auto i: v1) cout<<i<<", ";
    cout<<endl;

    sort(s1.begin(), s1.end());
    cout<<"S1 (inc): ";
    for(auto i: s1) cout<<i<<", ";
    cout<<endl;

    sort(p1.begin(), p1.end());
    cout<<"P1 (based on p1.first in inc.): ";
    for(auto i: p1) cout<<i.first<<"--"<<i.second<<" , ";
    cout<<endl;

    sort(name.begin(), name.end());
    cout<<"Name (inc): "<<name<<endl;


    
    cout<<"----------------------------------------------"<<endl;


    //2: Sort in descending order (or any other order) [CUSTOM COMPARATOR]
    vector<int> v2 = {2,5,1,3,9,6,4,8,7};
    vector<string> s2 = {"abcd","x","pqr","uv"};
    vector<pair<int,string>> p2 = {{3,"abc"}, {1,"xyz"}, {2,"pqr"}, {4,"def"}, {5,"ijk"}};

    sort(v2.begin(), v2.end(), cmpForV2);
    cout<<"V2 (dec.): ";
    for(auto i: v2) cout<<i<<", ";
    cout<<endl;

    sort(s2.begin(), s2.end(), cmpForS2);
    cout<<"S2 (based on string length in DESC.): ";
    for(auto i: s2) cout<<i<<", ";
    cout<<endl;

    sort(p2.begin(), p2.end(), cmpForP2);
    cout<<"P2 (based in p2.second && DESC. lexicographic): ";
    for(auto i: p2) cout<<i.first<<"--"<<i.second<<" , ";
    cout<<endl;


    //3: Sort in descending by using STL
    vector<int> data = {3,5,1,7,2,6,9,4,8};
    sort(data.rbegin(), data.rend());
    cout<<"Data (DESC. by STL): ";
    for(auto i: data) cout<<i<<", ";
    


    return 0;
}