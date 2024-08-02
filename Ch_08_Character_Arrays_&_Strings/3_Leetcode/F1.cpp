#include <bits/stdc++.h>
using namespace std;

// LEETCODE: 58. Length of last word
int lengthOfLastWord(string s)
{
    int last = s.length() - 1;

    // Move 'last' to the index of the last non-space character
    while (last >= 0 && s[last] == ' ')
        last--;

    int first = last;

    // Move 'first' to the index before the first character of the last word
    while (first >= 0 && s[first] != ' ')
        first--;

    // Return the length of the last word
    return last - first;
}

// LEETCODE: 344. Reverse string
void reverseString(vector<char> &s)
{
    int i = 0;
    int j = s.size() - 1;
    while (i <= j)
        swap(s[i++], s[j--]);
}

// LEETCODE: 1844. Replace all digits with characters
string replaceDigits(string s)
{
    for (int i = 1; i < s.length(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            char ch = s[i - 1];
            int num = s[i] - '0';
            s[i] = ch + num;
        }
    }

    return s;
}

// LEETCODE: 125. Valid palindrome
bool isPalindrome(string s)
{
    // Remove spaces & convert to lowercase
    string convert;
    for (int i = 0; i < s.length(); i++)
    {
        if (('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9'))
        {
            convert.push_back(s[i]);
        }
        else if ('A' <= s[i] && s[i] <= 'Z')
        {
            char temp = s[i] - 'A' + 'a';
            convert.push_back(temp);
        }
    }

    string orgConvert = convert;
    reverse(convert.begin(), convert.end());

    if (orgConvert == convert)
        return true;
    else
        return false;
}
