//Concept: Commonly used string STL

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    //1: Length
    string s1 = "123 456 789";
    cout<<"Length: "<<s1.length()<<endl;

    //2: Reverse
    reverse(s1.begin(), s1.end());
    cout<<"Reverse: "<<s1<<endl;

    //3: Replace all occurences of a character
    char oldChar = ' ';
    char newChar = '_';
    replace(s1.begin(), s1.end(), oldChar, newChar);
    cout<<"Replaced string: "<<s1<<endl;

    //4: Convert string to upper case
    string s2 = "Hello World!";
    transform(s2.begin(),s2.end(),  s2.begin(),::toupper);
    cout<<"Upper cased: "<<s2<<endl;

    //5: Convert string to lower case
    transform(s2.begin(),s2.end(),  s2.begin(),::tolower);
    cout<<"Lower cased: "<<s2<<endl;

    //6: Check emptyness of string
    cout<<"Is empty? : "<<s2.empty()<<endl;

    //7: Insert character at the end
    s2.push_back('1');
    cout<<"After push_back: "<<s2<<endl;

    //8: Delete character at the end
    s2.pop_back();
    s2.pop_back();
    cout<<"After pop_back: "<<s2<<endl;

    //9: Find substring from a string
    int startingIndex = 3;
    int lengthOfSubstr = 5;
    string s3 = "0123456789";
    cout<<"Substring: "<<s3.substr(startingIndex, lengthOfSubstr)<<endl;

    //10: Compare two strings
    string s4 = "Qureshi";
    string s5 = "Quresha";
    int ans = s4.compare(s5);
    if(ans == 0)    cout<<"s4 Equals s5"<<endl;
    if(ans > 0)     cout<<"s4 greater than s5"<<endl;
    if(ans < 0)     cout<<"s4 smaller than s5"<<endl;

    //11: Find a target-substring in a given-string
    string s6 = "My name is Qureshi";
    string target = "Qureshi";
    if(  s6.find(target) == string::npos  )     cout<<"Not found"<<endl;
    else                                        cout<<"Found at: "<<s6.find(target)<<endl;

    //12: 



    return 0;
}
