//Question: On Patterns

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
        int num;
        for(int j=0; j < ((2*i) + 1) ; j++)
        {   
            
            if(j==0 || j<(2*i + 1)/2 )
            {
                num = i+j+1;
                cout<<num++;
            }
                
            else
                cout<<num--;
        }

        //Next line
        cout<<endl;
    }
    cout<<endl<<endl;



    //Pattern_08: Numeric Hollow Pyramid
    for(int i=0; i<5; i++)
    {
        //Spaces-1
        for(int j=0; j < ((5-i) - 1); j++)
            cout<<" ";

        //Character-1  --  Spaces-2  --  Character-2
        int x=1;
        if( i==0 || i==(5-1) ) //First & Last Row
        {
            for(int j=0; j<=i; j++)
                cout<<x++<<" ";

            cout<<endl;
        }
        else //Rest of the other Rows
        {
            //Character-1
            cout<<"1";

            //Spaces
            for(int j=0; j<(2*i + 1)-2; j++)
                cout<<" ";

            //Character-2
            cout<<i+1;

            //Next line
            cout<<endl;
        }
    }
    cout<<endl<<endl;

    return 0;
}