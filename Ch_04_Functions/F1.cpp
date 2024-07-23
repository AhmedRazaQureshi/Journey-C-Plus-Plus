//Functions (User defined) & Fx.n Overloading

#include <iostream>
using namespace std;

//Prototypes
int add(int&, int&);
int add(int&, int&, int&); 

//Main function
int main()
{
    //Function Overloading
    int num1 = 2;
    int num2 = 3;
    int num3 = 1;
    cout << add(num1, num2) << endl;
    cout << add(num1, num2, num3) <<endl;

    //Function overriding is achieved using classes in C++
    
    return 0;
}

//Other functions
int add(int& a, int& b)
{
    return (a + b);
}

int add(int& a, int& b, int& c)  //Overloading on add()
{
    return (a+b+c);
}
