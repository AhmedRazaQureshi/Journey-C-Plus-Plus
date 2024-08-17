#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//Questions on Recursion:

//Ques#01: Climbing stairs (Find total ways to climb a stair-case of 'n' stairs)
//         (as of now you're at 0th stair i.e. ground)
//         (you can either take 1 step or take 2 steps)
int findWaysToClimb(int n)
{
    //BC
    if(n==0 || n==1)
        return 1;

    //REC
    return findWaysToClimb(n-1) + findWaysToClimb(n-2);
}

//Ques#02: Print array recursively
void printArrayRecursive(vector<int>& v, int n)
{
    //BC
    if(n == 0)
        return;

    //REC
    printArrayRecursive(v, n-1);
    cout<<v[n-1]<<",";    
}

//Ques#03: Find maximum element recusrsively 
void findMaxRec(vector<int>& v, int n, int& maxi)
{
    //BC
    if(n == 0)
        return;

    //Computation
    maxi = max(maxi, v[n-1]);
    //REC
    findMaxRec(v, n-1, maxi);
}

//Ques#04: Find all indices of a character in string, recursively
void findCharacterRec(string& s, int i, char& t, vector<int>& indices)
{
    //BC
    if(i == -1)
        return;
    
    //REC
    findCharacterRec(s, i-1, t, indices);
    //Computation
    if(s[i] == t)
        indices.push_back(i);
}

//Ques#05: Check if an array is monotonically increasing, recursively
bool isMonoRec(vector<int>& v, int i)
{
    //BC
    if(i == 0)
        return true;

    //Computation
    if(v[i-1] > v[i])
        return false;
    //REC
    return isMonoRec(v, i-1);
}

// Ques#06: Binary search by recursion
int recBinSear(vector<int>& v, int s, int e, int& t)
{
    //BC
    if(s>e)
        return -1;

    //Computation
    int m = s+(e-s)/2;
    if(v[m] == t)
        return m;

    //REC
    else if(v[m] > t)
        return recBinSear(v, s, m-1, t);
    else 
        return recBinSear(v, m+1, e, t);
}

//Ques#07: Find all subsequence of a string
void findSubseq(string& str, string currSubseq, int i, vector<string>& ans)
{
    //BC
    if(i >= str.length())
        return;

    //Exclude 
    findSubseq(str, currSubseq, i+1, ans);
    //Include
    currSubseq.push_back(str[i]);
    ans.push_back(currSubseq);
    findSubseq(str, currSubseq, i+1, ans);
}

//Ques#08: Coin sum problem (1$, 2$, 3$ infinite coins available; find min. coins needed to get 5$)
int findMinCoin(vector<int>& coins, int target)
{
    //BC
    if(target == 0)  //Answer found
        return 0;
    if(target < 0)   //Answer not found
        return INT_MAX;

    //Recursion
    int currLevelAns = INT_MAX;
    for(int i=0; i<coins.size(); i++)
    {
        int currBranchAns = findMinCoin(coins, target-coins[i]);
        if(currBranchAns != INT_MAX)
            currLevelAns = min(currLevelAns, 1+currBranchAns);
    }

    return currLevelAns;
}

//Ques#09: Rod cutting problem ('n' rod length; 'x y z' segments lengths allowed to cut; Find max possible segments you can get if you cut the rod)
int findMaxSegments(int n, int x, int y, int z)
{
    //BC
    if(n == 0) return 0; //Answer found
    if(n < 0) return INT_MIN; //Answer not found

    //Recursion
    int _x = 1 + findMaxSegments(n-x, x, y, z);
    int _y = 1 + findMaxSegments(n-y, x, y, z);
    int _z = 1 + findMaxSegments(n-z, x, y, z);

    int ans = max(_x, max(_y, _z));
    return ans;
}

//Ques#10: Maximizing non-adjacent sum (In an array find max sum of subsequence in which no two elements are adjacent)
int findMaxSubseqSum(vector<int>& nums, int i, int currSum)
{
    //BC
    if(i >= nums.size()) 
        return currSum;

    //Recursion

    //Include
    int ans1 = findMaxSubseqSum(nums, i+2, currSum+nums[i]);
    //Exclude
    int ans2 = findMaxSubseqSum(nums, i+1, currSum);

    return max(ans1,ans2);
}


int main()
{
    //Ques#01: Climbing stairs
    int stairs = 35; //Output: 14930352
    cout<<"Ways to climb: "<<findWaysToClimb(stairs)<<endl;

    //Ques#02: Print array recursively
    vector<int> v1 = {100,2,3,4,500};
    cout<<"Printing array: ";
    printArrayRecursive(v1, 5);
    cout<<endl;

    //Ques#03: Find max in array recursively
    int maxi = INT_MIN;
    findMaxRec(v1, 5, maxi);
    cout<<"Max element: "<<maxi<<endl;

    //Ques#04: Find index of a character in string recursive
    string s1 = "IamQureshiQuresha";
    char target = 'Q';
    int lastIndex = s1.length()-1;
    vector<int> indices;
    findCharacterRec(s1, lastIndex, target, indices);
    cout<<"Q is at: ";
    for(auto i: indices)
        cout<<i<<",";
    cout<<endl;

    //Ques#05: Check if an array is monotonically increasing, recursively
    vector<int> v2 = {1, 1, 2, 4, 5, 6, 6, 8};
    cout<<"Is v2 mono inc.: "<<isMonoRec(v2, 7)<<endl;
    
    //Ques#06: Binary search by recursion
    vector<int> v3 = {1,23,43,56,78,90};
    int t = 78;
    cout<<"78 is found at: "<<recBinSear(v3, 0, 5, t)<<endl;

    //Ques#07: Find all subsequence of a string
    string s2 = "abc";
    string currOutput = ""; //Empty string ko include karane k liye
    vector<string> subs; //Final answer for all substrings
    subs.push_back(currOutput); //Empty string push karwai
    findSubseq(s2, currOutput, 0, subs);
    for(auto i: subs)
        cout<<i<<",";
    cout<<endl;

    //Ques#08: Coin sum problem (1$, 2$, 3$ infinite coins available; find min. coins needed to get 5$)
    vector<int> coins = {1,2,3};
    int sum = 5;
    int minCoins = findMinCoin(coins, sum);
    cout<<"Minimum coins to make sum 5: "<<minCoins<<endl;

    //Ques#09: Rod cutting problem ('n' rod length; 'x y z' segments lengths allowed to cut; Find max possible segments you can get if you cut the rod)
    int rodLength = 7;
    int seg1=5, seg2=2, seg3=2;
    int maxSegments = findMaxSegments(rodLength, seg1, seg2, seg3);
    cout<<"Maximum segments you got: "<<maxSegments<<endl;

    //Ques#10: Maximizing non-adjacent sum (In an array find max sum of subsequence in which no two elements are adjacent)
    vector<int> numbers = {2,1,4,9};
    int maxSubseqSum = findMaxSubseqSum(numbers, 0, 0);
    cout<<"Maximum non-adjacent sum: "<<maxSubseqSum<<endl;



    return 0;
}