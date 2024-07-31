//main() with arguments

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//argument count, argument value
int main(int argc, char* argv[])  //(or) char** argv
{
    cout<<"Argument count: "<<argc<<endl;
    cout<<"Argument values: ";
    for(int i=0; i<argc; i++)
        cout<<argv[i]<<", ";

    cout<<endl;

    return 0;
}
//NOTE: How to run this program :-
// $ g++ F4.cpp
// $ ./a.out Ahmed Raza Qureshi

//OUTPUT: 
//Argument count: 4
//Argument values: ./a.out, Ahmed, Raza, Qureshi, 