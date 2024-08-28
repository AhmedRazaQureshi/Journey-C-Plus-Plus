//Concept: Classes, Objects

#include <bits/stdc++.h>
using namespace std;


//1. Class definition
class Animal
{
    //2. Access modifier
    public:

    //3. Data members
    string name;
    int age;


    //4. Member functions
    void eat()
    {
        cout<<this->name<<" is eating.."<<endl;
    }

    void sleep()
    {
        cout<<this->name<<" is sleeping.."<<endl;
    }
};

int main()
{
    //5. Object declaration
    Animal a1;                //Static
    Animal* a2 = new Animal;  //Dynamic


    //6. Object initialization
    a1.name = "Cat";
    a1.age = 8;

    a2->name = "Dog";
    a2->age = 12;


    //7. Accessing Object's DATA & BEHAVIOUR
    cout<<"Name: "<<a1.name<<endl;
    cout<<"Age: "<<a1.age<<endl;

    cout<<"Name: "<<a2->name<<endl;
    cout<<"Age: "<<a2->age<<endl;

    a1.eat();
    a1.sleep();

    a2->eat();
    a2->sleep();

    //a2->name  is  (*a2).name

    //8. Freeing dynamic object's memory
    delete a2;

    return 0;
}