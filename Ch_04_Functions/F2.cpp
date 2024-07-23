//Function overriding

#include <iostream>
using namespace std;

class Animal
{
    public:
    void eat()
    {
        cout<<"Animal is eating"<<endl;
    }

    void sleep()
    {
        cout<<"Animal is sleeping"<<endl;
    }
};

class Dog : public Animal
{
    public:
    void eat()  //Overriding on eat()
    {
        cout<<"Dog is eating"<<endl;
    }
};


int main()
{
    Dog d1;

    d1.eat();
    d1.sleep();

    return 0;
}
