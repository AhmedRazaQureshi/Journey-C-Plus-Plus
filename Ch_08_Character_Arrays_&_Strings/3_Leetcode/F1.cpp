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

// LEETCODE: 1957. Delete characters to make fancy string
string makeFancyString(string s)
{
    string temp = s;
    int n = s.length();

    int i = n - 1;
    int j = n - 2;
    int k = n - 3;

    while (k >= 0)
    {

        if (temp[i] == temp[j] && temp[j] == temp[k])
            temp.erase(j, 1);

        k--;
        j--;
        i--;
    }

    return temp;
}

// LEETCODE: 1047. Remove all adjacent duplicates in string
string removeDuplicates(string &s)
{
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        // Matching pada mila ans mein => pop karo
        if (!ans.empty() && ans.back() == s[i])
            ans.pop_back();
        else
            ans.push_back(s[i]);
    }

    return ans;
}

// LEETCODE: 1910. Remove all occurences of a substring
void removeSubstringOccurences(string &source, string &subStr)
{
    bool flag = true;
    while (flag)
    {
        if (source.find(subStr) == string::npos)
            flag = false;
        else
        {
            int index = source.find(subStr);
            source.erase(index, subStr.length());
        }
    }
}

string removeOccurrences(string s, string part)
{
    removeSubstringOccurences(s, part);
    return s;
}

// LEETCODE: 680. Valid palindrome 2
bool helperForIsPallindrome(string &s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;

        i++;
        j--;
    }
    return true;
}

bool validPalindrome(string &s)
{
    int i = 0;
    int j = s.length() - 1;

    while (i <= j)
    {
        if (s[i] != s[j])
            return helperForIsPallindrome(s, i, j - 1) || helperForIsPallindrome(s, i + 1, j);
        else
        {
            i++;
            j--;
        }
    }

    return true;
}

// LEETCODE: 539. Minimum time difference
int findMinDifference(vector<string> &times)
{
    // Step-1: Convert HH:MM (string) to MM (int)
    vector<int> intMinutes;
    for (int i = 0; i < times.size(); i++)
    {
        string currTime = times[i];

        int currHours = stoi(currTime.substr(0, 2));
        int currMinutes = stoi(currTime.substr(3, 2));

        currMinutes += (currHours * 60);
        intMinutes.push_back(currMinutes);
    }

    // Step-2: Sort intMinutes (taaki sirf adjacents hi compare karane padein)
    sort(intMinutes.begin(), intMinutes.end());

    // Step-3: Compare adjacents (last mein extremes also you compare)
    int minimumTimeDifference = INT_MAX;
    for (int i = 1; i < intMinutes.size(); i++)
    {
        int currTimeDifference = abs(intMinutes[i - 1] - intMinutes[i]);
        minimumTimeDifference = min(minimumTimeDifference, currTimeDifference);
    }
    // Ab extremes ko compare karao
    int diff_clockWise = abs(intMinutes[0] - intMinutes[intMinutes.size() - 1]);
    int diff_antiClockWise = abs(1440 + intMinutes[0] - intMinutes[intMinutes.size() - 1]);

    // Step-3: Final answer
    minimumTimeDifference = min(minimumTimeDifference, min(diff_clockWise, diff_antiClockWise));

    return minimumTimeDifference;
}

// LEETCODE: 647. Palindromic substrings
int helperForCountPallindrome(string &s, int i, int j)
{
    int count = 0;
    while (i >= 0 && j < s.length() && (s[i] == s[j]))
    {
        count++;
        i--;
        j++;
    }
    return count;
}
int countSubstrings(string &s)
{
    int count = 0;
    // Har ek character k around expand krna hai(2 tareeke se)
    for (int i = 0; i < s.length(); i++)
    {
        // Counting Odd length pallindromes
        count += helperForCountPallindrome(s, i, i);
        // Counting Evem length pallindromes
        count += helperForCountPallindrome(s, i, i + 1);
    }
    return count;
}

// LEETCODE: 179. Largest number
static bool cmp(int a, int b)
{
    string num1 = to_string(a); // 3
    string num2 = to_string(b); // 30

    if (num1 + num2 > num2 + num1) // 3,30 > 30,3
        return true;
    else
        return false;
}

string largestNumber(vector<int> &nums)
{
    // nums -> 3,30,34,5,9
    sort(nums.begin(), nums.end(), cmp);
    // nums -> 9,5,34,3,30

    string ans = "";
    for (int i = 0; i < nums.size(); i++)
        ans += to_string(nums[i]);

    // Edge case
    if (ans[0] == '0')
        return "0";

    return ans;
}

// LEETCODE: 242. Valid anagram
// Method-1: Sort
bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return (s == t);
}
//Method-2: Count freq.
bool isAnagram(string& s1, string s2)
{
    //Count frequencies
    int freq[256]={0};

    for(int i=0; i<s1.length(); i++)
        freq[s1[i]]++;
    
    for(int i=0; i<s2.length(); i++)
        freq[s2[i]]--;

    for(int i=0; i<256; i++)
        if(freq[i] != 0)
            return false;
    
    return true;
}

//LEETCODE: 917. Reverse only letters
string reverseOnlyLetters(string& s)
{
    //Two ptr 
    int i=0;
    int j=s.length()-1;

    while(i <= j)
    {
        if(isalpha(s[i]) && isalpha(s[j]))
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
        else if(!isalpha(s[i]))
            i++;
        else    
            j--;
    }
    return s;
}

