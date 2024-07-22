#include <iostream>

using namespace std;

int main()
{
    //Pattern_01: Solid Rectangle (5x7)
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<7; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<endl<<endl;



    //Pattern_02: Hollow Rectangle (5x7)
    for(int i=0; i<5; i++)
    {
        if(i==0 || i==(5-1))
        {
            for(int j=0; j<7; j++)
                cout<<"*";

            cout<<endl;
        }
        else
        {
            cout<<"*";
            for(int j=1; j<(7-1); j++)
                cout<<" ";
            cout<<"*";

            cout<<endl;
        }       
    }
    cout<<endl<<endl;



    //Pattern_03: Half Pyramid (5x5)
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<=i; j++)
            cout<<"*";
        
        cout<<endl;
    }
    cout<<endl<<endl;



    //Pattern_04: Inverted Half Pyramid (5x5)
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<(5-i); j++)
            cout<<"*";

        cout<<endl;
    }
    cout<<endl<<endl;



    //Pattern_05: Numeric Half Pyramid (5x5)
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<=i; j++)
            cout<<(j+1);

        cout<<endl;
    }
    cout<<endl<<endl;



    //Pattern_06: Inverted Numeric Half Pyramid (5x5)
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<(5-i); j++)
            cout<<(j+1);
        
        cout<<endl;
    }
    cout<<endl<<endl;



    //Pattern_07: Numeric Full Pyramid (n=5)
    for(int i=0; i<5; i++)
    {
        //Spaces
        for(int j=0; j < ((5-i) - 1); j++)
            cout<<" ";

        
        //Characters
        for(int j=0; j < ((2*i) + 1) ; j++)
        {
            cout<<
        }
            

    }
    //Pattern_08: Numeric Hollow Pyramid
    

    return 0;
}