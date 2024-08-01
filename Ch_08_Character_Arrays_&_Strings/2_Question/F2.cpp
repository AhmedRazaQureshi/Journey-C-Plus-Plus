//Question: On Strings

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;


//Ques#01: [TRICKY] Remove all adjacent duplicates in a string 
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


//Ques#03: [TRICKY] Find if given string canbecome pallindrome after deleting at most 1 character 
bool helperForIsPallindrome(string& s, int i, int j)
{
    while(i <= j)
    {
        if(s[i] != s[j])
            return false;

        i++;
        j--;
    }
    return true;
}

bool isPallindromeConvertible(string& s)
{
    int i=0;
    int j=s.length()-1;

    while(i <= j)
    {
        if(s[i] != s[j])
            return helperForIsPallindrome(s,i,j-1) || helperForIsPallindrome(s,i+1,j);
        else
            {i++; j--;}
    }

    return true;
}


//Ques#04: [TRICKY] Minimum time difference
int findMinTimeDiff(vector<string>& times)
{
    //Step-1: Convert HH:MM (string) to MM (int)
    vector<int> intMinutes;
    for(int i=0; i<times.size(); i++)
    {
        string currTime = times[i];

        int currHours = stoi(currTime.substr(0, 2));
        int currMinutes = stoi(currTime.substr(3, 2));

        currMinutes += (currHours*60); 
        intMinutes.push_back(currMinutes);
    }

    //Step-2: Sort intMinutes (taaki sirf adjacents hi compare karane padein)
    sort(intMinutes.begin(), intMinutes.end());

    //Step-3: Compare adjacents (last mein extremes also you compare)
    int minimumTimeDifference = INT_MAX;
    for(int i=1; i<intMinutes.size(); i++)
    {
        int currTimeDifference = abs(intMinutes[i-1] - intMinutes[i]);
        minimumTimeDifference = min(minimumTimeDifference, currTimeDifference);
    }
    //Ab extremes ko compare karao
    int diff_clockWise = abs(intMinutes[0] - intMinutes[intMinutes.size()-1]);
    int diff_antiClockWise = abs(1440 + intMinutes[0] - intMinutes[intMinutes.size()-1]);

    //Step-3: Final answer
    minimumTimeDifference = min(minimumTimeDifference, min(diff_clockWise, diff_antiClockWise));

    return minimumTimeDifference;
}


//Ques#05: [TRICKY] Count total pallindromic substrings in given string
int helperForCountPallindrome(string& s, int i, int j)
{
    int count = 0;
    while(i>=0 && j<s.length() && (s[i]==s[j]))
    {
        count++;
        i--;
        j++;
    }
    return count;
}
int countPallindromicSubstrings(string& s)
{
    int count = 0;
    //Har ek character k around expand krna hai(2 tareeke se)
    for(int i=0; i<s.length(); i++)
    {
        //Counting Odd length pallindromes
        count += helperForCountPallindrome(s, i, i);
        //Counting Evem length pallindromes
        count += helperForCountPallindrome(s, i, i+1);
    }
    return count;
}


//Ques#06: [TRICKY] Make largest number (by concatenation)
bool cmp_06(int a, int b)
{
    string num1 = to_string(a); //3
    string num2 = to_string(b); //30

    if( num1+num2 > num2+num1 ) //3,30 > 30,3
        return true;
    else
        return false;
}

string findLargestByConcat(vector<int>& nums)
{
    //nums -> 3,30,34,5,9
    sort(nums.begin(), nums.end(), cmp_06);
    //nums -> 9,5,34,3,30

    string ans = "";
    for(int i=0; i<nums.size(); i++)
        ans += to_string(nums[i]);

    //Edge case
    if(ans[0] == '0')
        return "0";

    return ans;
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
    string s3 = "leverl";
    cout<<"Is pallindrome convertible? : "<<isPallindromeConvertible(s3)<<endl;

    //Ques#04: Minimum time difference
    vector<string> times = {"12:10","10:15","13:15","17:20","18:00","19:47","23:59"};
    cout<<"Minimum time diff: "<<findMinTimeDiff(times)<<endl;

    //Ques#05: Count total pallindromic substrings in given string
    string s4 = "noon";
    cout<<"Total pallindromic substrings are: "<<countPallindromicSubstrings(s4)<<endl;

    //Ques#06: Make largest number (by concatenation)
    vector<int> s5 = {3,30,34,5,9};
    cout<<"Largest number by concatenation: "<<findLargestByConcat(s5)<<endl;

    //Ques#07: 



    return 0;
}