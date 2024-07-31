//Concept: Character Arrays

#include <iostream>
#include <limits> // Include this header for numeric_limits
using namespace std;

int main()
{
    //1. Basics of character arrays
    char c1[100];
    cout<<"c1: ";
    cin.getline(c1, 100);    //Read with spaces
    cout<<c1<<endl<<endl;

    char c2[10];
    cout<<"c2: ";
    cin>>c2;                //Read w/o spaces
    cout<<c2<<endl<<endl;

    char* c3 = new char[100];
    cout<<"c3: ";
    cin>>c3;
    cout<<c3<<endl<<endl;

    char* c4 = (char*) malloc(100*sizeof(char));
    cout<<"c4:";
    cin>>c4;
    cout<<c4<<endl<<endl;

    char c5[] = "1234";
    cout<<c5<<endl<<endl;



    //2. Basics of strings
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear buffer for getline()

    string s1;
    cout<<"s1: ";
    getline(cin, s1);        //Read with spaces
    cout<<s1<<endl<<endl;

    string s2;
    cout<<"s2: ";
    cin>>s2;
    cout<<s2<<endl<<endl;    //Read w/o spaces

    return 0;
}