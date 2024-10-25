/*  Concept: 
    1. Top-Down DP  (Recursion + Memoization)
    2. Bottom-Up DP (Loop + Memoization)
    3. Space-Opt DP (Loop + Less Memoization)
*/
#include <bits/stdc++.h>
using namespace std;

int fib_rec(int n)
{
    //1. BC
    if(n==0 || n==1)
        return n;
    
    //2. Recursion
    return fib_rec(n-1) + fib_rec(n-2);
}

int fib_top_down(int n, vector<int>& dp)
{
    //BC
    if(n==0 || n==1)
        return n;

    //Step-2: If answer already present in table
    if(dp[n] != -1)
        return dp[n];

    //Step-3: If answer not present in table
    dp[n] = fib_top_down(n-1, dp) + fib_top_down(n-2, dp);
    return dp[n];
}

int fib_bottom_up(int n)
{
    //Step-1: Create dp array
    vector<int> dp(n+1, -1);

    //Step-2: BC to DP cells filling
    if(dp.size()>=1)
        dp[0] = 0;
    if(dp.size()>=2)
        dp[1] = 1;

    //Step-3: Recursion to Loop conversion
    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2]; //RR for value 
    }

    return dp[n];
}

int fib_space_opt(int n)
{
    //Step-1: Optimize dp array
    int k_1;
    int k_2;
    int k;

    //Step-2: Fillings for BC 
    k_1 = 1;
    k_2 = 0;

    //Step-3: Loop
    for(int i=2; i<=n; i++)
    {
        k = k_1 + k_2;

        k_2 = k_1;
        k_1 = k;
    }

    return k;
}

int main()
{
    int n = 6;
    cout<<"Simple Recursion: "<<fib_rec(n)<<endl;
    
    //Step-1[Top-Down]: Create dp array
    vector<int> dp(n+1, -1);
    cout<<"Top-Down DP: "<<fib_top_down(n, dp)<<endl;

    cout<<"Bottom-Up DP: "<<fib_bottom_up(n)<<endl;

    cout<<"Space-Opt DP: "<<fib_space_opt(n)<<endl;


}