//Concept: Getters, Setters, This keyword

#include <bits/stdc++.h>
using namespace std;

class Animal
{
    private:
    string name;

    public:
    int age;

    void setName(string _name)
    {
        this->name = _name;
    }

    string getName()
    {
        return this->name;
    }

};

int main()
{
    Animal a1;
    a1.setName("Cat");
    cout << "Name: " << a1.getName()<<endl;

    return 0;
}