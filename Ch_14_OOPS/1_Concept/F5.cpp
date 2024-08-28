//Concept: Encapsulation
#include <bits/stdc++.h>
using namespace std;

class Animal
{
    private:
    string name;

    public:
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
    cout<<a1.getName();

    return 0;
}