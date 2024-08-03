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

// LEETCODE: 2129. Capitalize the title
string capitalizeTitle(string title)
{
    // Convert entire string to lower-case
    transform(title.begin(), title.end(), title.begin(), ::tolower);

    // Change each character of starting word to upper-case
    int i = 0;
    int first = 0;
    int last;
    while (i < title.length())
    {
        while (i < title.length() && title[i] != ' ')
            i++;

        last = i - 1;

        if ((last - first + 1) > 2)
            title[first] = title[first] - 'a' + 'A';

        i++;
        first = i;
    }

    return title;
}

// LEETCODE: 709. To lower case
string toLowerCase(string s)
{
    for (int i = 0; i < s.length(); i++)
        if ('A' <= s[i] && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';

    return s;
}

// LEETCODE: 2937. Make three strings equal
int findMinimumOperations(string s1, string s2, string s3)
{
    if (!((s1[0] == s2[0]) && (s2[0] == s3[0])))
        return -1;

    /*
    Explanation:
    s1 = aaaaaaca
    s2 = aaaaaabcc
    s3 = aaaaaaccba

    Step-1: Find minimum no. of operations
    aaaaaaca
    aaaaaabc|c
    aaaaaacc|ba      =>3 operations to lagenge ji lagenge

    Step-2: Find additional operations
         i
    aaaaaaca
    aaaaaabc
    aaaaaacc
           j         =>3*(j-i+1) additional operations
    */
    int n1 = s1.length();
    int n2 = s2.length();
    int n3 = s3.length();

    int minLength = min(n1, min(n2, n3));
    int minOperations = (n1 - minLength) + (n2 - minLength) + (n3 - minLength);

    int i = minLength - 1;
    int j = minLength - 1;
    int additionalOperations = 0;

    while (i != 0)
    {
        if (!((s1[i] == s2[i]) && (s2[i] == s3[i])))
            additionalOperations = 3 * (j - i + 1);

        i--;
    }

    return minOperations + additionalOperations;
}

// LEETCODE: 833. Find and replace in string
string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets)
{
    // Step-1: Store 'indices' & 'sources' & 'targets' in a vector of tuple
    vector<tuple<int, string, string>> data;
    for (int i = 0; i < indices.size(); i++)
        data.push_back({indices[i], sources[i], targets[i]});

    // Step-2: Sort data in DESC. based on indices (taaki R to L replacement kar saku)
    // R to L replacement isliye karna hai taki indices modify na karne padein
    sort(data.rbegin(), data.rend()); //

    // Step-3: Replace by traversing 'data'
    for (auto i : data)
    {
        int index;
        string source;
        string mod;

        tie(index, source, mod) = i;

        if (s.substr(index, source.length()) == source)
            s.replace(index, source.length(), mod);
    }
    return s;
}

//