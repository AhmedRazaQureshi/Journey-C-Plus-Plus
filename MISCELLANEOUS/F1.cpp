//Basic idea of HashMap
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    string s = "ahmedrazaqureshi";

    //Creation
    map<char,int> freq;

    //Insertion
    for(int i=0; i<s.length(); i++)
    {
        char currChar = s[i];

        freq[currChar] += 1;
    }

    cout<<"Character frequencies: "<<endl;
    for(auto i: freq) 
        cout<<i.first<<" -> "<<i.second<<endl;


    //Checking presense of a key in hashmap
    unordered_map<int, string> myMap;
    myMap[1] = "one";
    myMap[2] = "two";
    myMap[3] = "three";

    int keyToFind = 2;
    if (myMap.find(keyToFind) != myMap.end()) 
        cout<<"Present"<<endl; 
    else 
        cout<<"Not present"<<endl;



    return 0;

}