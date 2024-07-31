//Question: On Strings

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


//Ques#01: Remove all adjacent duplicates in a string [TRICKY]
string removeAdjacentDuplicates(string& s)
{
    string ans = "";

    for(int i=0; i<s.length(); i++)
    {
        //Matching pada mila ans mein => pop karo
        if(!ans.empty() && ans.back() == s[i])
            ans.pop_back();
        else
            ans.push_back(s[i]);
    }

    return ans;
}


//Ques#02: Remove all occurences of the substring 'subStr' from the string 'source'
void removeSubstringOccurences(string& source, string& subStr)
{
    bool flag = true;
    while(flag)
    {
        if(source.find(subStr) == string::npos)
            flag = false;
        else
        {
            int index = source.find(subStr);
            source.erase(index, subStr.length());
        }
    }
}


//Ques#03: Find if given string canbecome pallindrome after deleting at most 1 character
bool isPallindromeConvertible(string s1)
{
        
}



int main()
{
    //Ques#01: Remove all adjacent duplicates in a string
    string s1 = "abbaca";  
    s1 = removeAdjacentDuplicates(s1);
    cout<<"After removal of adjacent duplicates: "<<s1<<endl;

    //Ques#02: Remove all occurences of the substring 'subStr' from the string 'source'
    string s2 = "daabcbaabcbc";
    string subStr = "abc";
    removeSubstringOccurences(s2, subStr);
    cout<<"After removal of subStr: "<<s2<<endl;

    //Ques#03: Find if given string canbecome pallindrome after deleting at most 1 character


    return 0;
}