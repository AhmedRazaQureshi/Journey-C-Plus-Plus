#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //1: Hello World
    cout << "Hello World" << endl;

    //2: Variables
    int validName;
    int _validName;
    
    //3: Data Types
    bool n1 = true;          //1 B
    short n2 = 10;           //2 B
    char n3 = 'A';           //1 B (-128 to 127)
    unsigned char n4 = 255;  //1 B (0 to 255)
    int n5 = -10;            //4 B
    unsigned n6 = 10;        //4 B
    long n7 = 1000;          //4 B
    long long n8 = 10000;    //8 B
    float n9 = 1.23;         //4 B
    double n10 = 1.2345;      //8 B
    string n11 = "Qureshi";  //24 B
    
    cout<<n1<<" "<<n2<<" "<<n3<<" "<<n4<<" "<<n5<<" "<<n6<<" "<<n7<<" "<<n8<<" "<<n9<<" "<<n10<<" "<<n11<<endl; 

    return 0;
}
