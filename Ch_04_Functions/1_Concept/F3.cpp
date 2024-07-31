//Overloading & Overriding on main()

#include <iostream>
using namespace std;

class A
{
    public:

    void main()
    {
        cout<<"Main-1 from Class A"<<endl;
    }
    
    void main(int x) //Overloading on main()
    {
        cout<<"Main-2 from Class A"<<endl;
    }
};

class B : public A
{
    public:

    void main() //Overriding on Main-1 of A
    {
        cout<<"Main-1 from B"<<endl;
    }

    //NOTE: Bring the overloaded main(int x) from class A into the scope of class B
    using A::main;

};

int main()
{
    A a;
    B b;

    a.main();
    a.main(10);

    b.main();
    b.main(20);
    
    return 0;
}