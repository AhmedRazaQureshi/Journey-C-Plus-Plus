// LEETCODE: 509. Fibonacci number
// Sol-1: Simple recursion
int fib_rec(int n)
{
    // 1. BC
    if (n == 0 || n == 1)
        return n;

    // 2. Recursion
    return fib_rec(n - 1) + fib_rec(n - 2);
}
// Sol-2: Top-Down-DP
int fib_top_down(int n, vector<int> &dp)
{
    // BC
    if (n == 0 || n == 1)
        return n;

    // Step-2: If answer already present in table
    if (dp[n] != -1)
        return dp[n];

    // Step-3: If answer not present in table
    dp[n] = fib_top_down(n - 1, dp) + fib_top_down(n - 2, dp);
    return dp[n];
}
// Sol-3: Bottom-Up-DP
int fib_bottom_up(int n)
{
    // Step-1: Create dp array
    vector<int> dp(n + 1, -1);

    // Step-2: BC to DP cells filling
    if (dp.size() >= 1)
        dp[0] = 0;
    if (dp.size() >= 2)
        dp[1] = 1;

    // Step-3: Recursion to Loop conversion
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2]; // RR for value
    }

    return dp[n];
}
// Sol-4: Space-Opt-DP
int fib_space_opt(int n)
{
    // Step-1: Optimize dp array
    int k_1;
    int k_2;
    int k;

    // Step-2: Fillings for BC
    k_1 = 1;
    k_2 = 0;

    // Step-3: Loop
    for (int i = 2; i <= n; i++)
    {
        k = k_1 + k_2;

        k_2 = k_1;
        k_1 = k;
    }

    return k;
}

// LEETCODE: 322. Coin change
// #1: Recursion
int solveRec(vector<int> &coins, int amount)
{
    // BC
    if (amount == 0)
        return 0;
    if (amount < 0)
        return INT_MAX;

    int finalAnswer = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int currAns = solveRec(coins, amount - coins[i]);
        if (currAns != INT_MAX)
            finalAnswer = min(finalAnswer, 1 + currAns);
    }

    return finalAnswer;
}

// #2: Recursion + Memoization
int solveMem(vector<int> &coins, int amount, vector<int> &dp)
{
    // BC
    if (amount == 0)
        return 0;
    if (amount < 0)
        return INT_MAX;
    // S3
    if (dp[amount] != -1)
        return dp[amount];

    // S2
    int finalAnswer = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int currAns = solveMem(coins, amount - coins[i], dp);
        if (currAns != INT_MAX)
            finalAnswer = min(finalAnswer, 1 + currAns);
    }

    dp[amount] = finalAnswer;
    return dp[amount];
}

int coinChange(vector<int> &coins, int amount)
{
    // S1
    vector<int> dp(amount + 1, -1);
    int ans = solveMem(coins, amount, dp);

    if (ans != INT_MAX)
        return ans;
    else
        return -1;
}

// #3: Bottom-Up
int solve(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int target = 1; target <= amount; target++)
    {
        int mini = INT_MAX;

        for (int i = 0; i < coins.size(); i++)
        {
            if (target - coins[i] >= 0)
            {
                int currAns = dp[target - coins[i]];

                if (currAns != INT_MAX)
                    mini = min(mini, 1 + currAns);
            }
        }

        dp[target] = mini;
    }

    return dp[amount];
}

int coinChange(vector<int> &coins, int amount)
{
    int ans = solve(coins, amount);
    if (ans != INT_MAX)
        return ans;
    return -1;
}

// LEETCODE: 198. House robber

// n->house no. to rob;
// As of now we're at last house & moving R to L
int solveRec(vector<int> &nums, int n)
{
    // BC
    if (n < 0)
        return 0; // No profit on house that doesn't exist
    if (n == 0)
        return nums[0]; // Only single house to rob->just rob it

    // Include
    int include = solveRec(nums, n - 2) + nums[n];
    // Exclude
    int exclude = solveRec(nums, n - 1);

    return max(include, exclude);
}

int solveMem(vector<int> &nums, int n, vector<int> &dp)
{
    // BC
    if (n < 0)
        return 0; // No profit on house that doesn't exist
    if (n == 0)
        return nums[0]; // Only single house to rob->just rob it
    // Step-3
    if (dp[n] != -1)
        return dp[n];

    // Include
    int include = solveMem(nums, n - 2, dp) + nums[n];
    // Exclude
    int exclude = solveMem(nums, n - 1, dp);

    // Step-2
    dp[n] = max(include, exclude);

    return dp[n];
}

int solveTab(vector<int> &nums, int n)
{
    // Step-1
    // dp[i] -> robbed amout after robbing i'th house
    //  as of now we're at i'th position & moving L to R
    vector<int> dp(n, 0);
    // Step-2
    dp[0] = nums[0];

    // neeche for loop mein [i-2] karne pe out of bound na ho isliye
    // loop i=2 se shuru karunga aur i=1 ki value khud hi bhar lunga
    if (nums.size() >= 2) // nums[1] out of bound na ho isliye if cond.n
        dp[1] = max(dp[0], nums[1]);

    // Step-3
    for (int i = 2; i < n; i++) // as of now I am at i'th house
    {
        // Include
        int include = dp[i - 2] + nums[i];

        // Exclude
        int exclude = dp[i - 1];

        // Step-2
        dp[i] = max(include, exclude);
    }
    return dp[n - 1]; // size n hai, last index n-1 hai
}

int solveSpaceOpt(vector<int> &nums, int n)
{
    int prev2 = 0;
    int prev1 = 0;
    int curr = 0;

    // Edge cases
    if (nums.size() == 1)
        return nums[0];

    if (nums.size() == 2)
        return max(nums[0], nums[1]);

    // Normal cases
    prev2 = nums[0];
    prev1 = max(prev2, nums[1]);

    for (int i = 2; i < n; i++) // as of now I am at i'th house
    {
        // Include
        int include = nums[i] + prev2;

        // Exclude
        int exclude = prev1;

        // Max
        curr = max(include, exclude);

        // Aage badho
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int rob(vector<int> &nums)
{
    int n = nums.size();

    return solveSpaceOpt(nums, n);
}

