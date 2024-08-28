//Concept: Constructors

#include <bits/stdc++.h>
using namespace std;

class Animal
{
    public:
    string name;
    int age;

    //1. Non-parametrized constructor
    Animal()
    {
        cout<<endl<<"Constructor-1 called"<<endl<<endl;
        this->name = "---";
        this->age = 0;
    }

    //2. Parametrized constructor
    Animal(string _name, int _age)
    {
        cout<<endl<<"Constructor-2 called"<<endl<<endl;
        this->name = _name;
        this->age = _age;
    }

    //3. Copy constructor
    Animal(Animal& obj)
    {
        cout<<endl<<"Constructor-3 called"<<endl<<endl;
        this->name = obj.name;
        this->age = obj.age;        
    }

};

int main()
{
    //4. Object initialization using constructors
    Animal a1("Cat", 8);
    Animal* a2 = new Animal("Dog", 12);
    Animal a3;

    cout<<"a1 info :- "<<endl;
    cout<<"Name: "<<a1.name<<"\nAge: "<<a1.age<<endl;

    cout<<"a2 info :- "<<endl;
    cout<<"Name: "<<a2->name<<"\nAge: "<<a2->age<<endl;

    cout<<"a3 info :- "<<endl;
    cout<<"Name: "<<a3.name<<"\nAge: "<<a3.age<<endl;

    cout<<"--------------------------------------------"<<endl;

    //5. Copying an object into another
    Animal a4 = a1;
    Animal a5(a1);

    Animal* a6 = a2;
    Animal* a7(a2);

    cout<<"a4 info :- "<<endl;
    cout<<"Name: "<<a4.name<<"\nAge: "<<a4.age<<endl;

    cout<<"a5 info :- "<<endl;
    cout<<"Name: "<<a5.name<<"\nAge: "<<a5.age<<endl;

    cout<<"a6 info :- "<<endl;
    cout<<"Name: "<<a6->name<<"\nAge: "<<a6->age<<endl;

    cout<<"a7 info :- "<<endl;
    cout<<"Name: "<<a7->name<<"\nAge: "<<a7->age<<endl;


    delete a2;
    delete a6;
    delete a7;


    return 0;
}