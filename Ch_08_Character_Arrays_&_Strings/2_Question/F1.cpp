//Question: On basic STL functions implementation

#include <iostream>
using namespace std;

//Ques#01: Find length of a string w/o STL
int findLength(string& s)
{
    int i=0;
    while(s[i] != '\0')
        i++;

    return i;
}


//Ques#02: Reverse a string 
string findReverse(string& s)
{
    int i=0;
    int j=s.length()-1;

    while(i <= j)
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }

    return s;
}


//Ques#03: Replace all occurences of a character
string findReplacement(string& s, char oldChar, char newChar)
{
    for(int i=0; i<s.length(); i++)
        if(s[i] == oldChar)
            s[i] = newChar;

    return s;
}


//Ques#04: Palindrome checker
bool isPalindrome(string& s)
{
    for(int i=0, j=s.length()-1; i <= j; i++, j--)
        if(s[i] != s[j])
            return false;

    return true;
}


//Ques#05: Convert string to upper case
string toUpper(string& s)
{
    for(int i=0; i<s.length(); i++)
        if('a'<=s[i] && s[i]<='z')
            s[i] = (s[i] - 'a') + 'A';

    return s;
}


//Ques#06: Convert string to lower case
string toLower(string& s)
{
    for(int i=0; i<s.length(); i++)
        if('A'<=s[i] && s[i]<='Z')
            s[i] = (s[i] - 'A') + 'a';

    return s;
}


//Ques#07: Compare 3 strings
bool threeStringComparison(string& s1, string& s2, string& s3)
{
    if(s1.length() != s2.length() ||
       s1.length() != s3.length() ||
       s2.length() != s3.length()    
       )
            return false;
    
    //Lengths to pakka barabar hi hain sabki
    for(int i=0; i<s1.length(); i++)
    {
        if(s1[i] != s2[i] ||
           s1[i] != s3[i] ||
           s2[i] != s3[i]
           )
                return false;
    }

    return true;
}


int main()
{
    //Ques#01: Find length of a string w/o STL
    string s1 = "123 456 789";
    cout<<"Length: "<<findLength(s1)<<endl;

    //Ques#02: Reverse a string 
    cout<<"Reverse: "<<findReverse(s1)<<endl;

    //Ques#03: Replace all occurences of a character
    char oldChar = ' ';
    char newChar = '_';
    cout<<"Replaced string: "<<findReplacement(s1, oldChar, newChar)<<endl;

    //Ques#04: Palindrome checker
    string s2 = "1234321";
    cout<<"Is palindrome? : "<<isPalindrome(s2)<<endl;

    //Ques#05: Convert string to upper case
    string s3 = "Hello Wolrd!";
    cout<<"Upper cased: "<<toUpper(s3)<<endl;

    //Ques#06: Convert string to lower case
    cout<<"Lower cased: "<<toLower(s3)<<endl;

    //Ques#07: Compare 3 strings
    string s4 = "ABCD";
    string s5 = "ABCD";
    string s6 = "ABCD";
    cout<<"Are 3 string equal: "<<threeStringComparison(s4,s5,s6)<<endl;

    return 0;
}