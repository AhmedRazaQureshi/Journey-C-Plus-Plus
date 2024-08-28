//Concept: Destructors

#include <bits/stdc++.h>
using namespace std;

class Animal
{
    public:
    string name;
    int age;

    ~Animal()
    {
        cout<<"Destructor called"<<endl;
        //Delete yeh khud hi kr dega jab bhi call hoga tab
    }
};

int main()
{
    Animal a1;
    a1.name = "Cat";
    a1.age = 8;

    Animal* a2 = new Animal();
    a2->name = "Dog";
    a2->age = 12;

    //Manually destructor have to be called for object a2
    delete a2;


    return 0;
    //Automatically destructor is called for object a1
}