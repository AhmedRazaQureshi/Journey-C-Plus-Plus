#include <bits/stdc++.h>
using namespace std;
// LEETCODE: 204. Count Primes
// Method-1: Sieve of Eratosthenes
vector<int> findPrimesSieve(int n)
{
    // Step-1: Create array [of size n]
    vector<bool> sieve(n, true);
    vector<int> primes;
    for (int i = 2; i < n; i++)
    {
        if (sieve[i] == true)
        {
            primes.push_back(i);
            for (int j = i; j < sieve.size(); j += i)
                sieve[j] = false;
        }
    }
    return primes;
}

int countPrimes(int n)
{
    vector<int> ans = findPrimesSieve(n);
    return ans.size();
}

// Method-2: Optimised Sieve of Eratosthenes
vector<int> findPrimesSieveOpt(int n)
{
    vector<bool> sieve(n, true);
    vector<int> primes;
    for (int i = 2; i * i < n; i++) // opt-2: i<sqrt(n)  i.e.  i*i < n
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j < n; j += i) // opt-1: j=i*i   opt-2:
                sieve[j] = false;
        }
    }

    // Step-2: Collect all primes
    for (int i = 2; i < sieve.size(); i++)
    {
        if (sieve[i] == true)
            primes.push_back(i);
    }

    return primes;
}

int countPrimes(int n)
{
    vector<int> ans = findPrimesSieveOpt(n);
    return ans.size();
}

// Method-3: Using Segmented Sieve
//  REH RAHA HAI

// LEETCODE: 1979. Find Greatest Common Divisor of Array
int findHCF(int a, int b)
{
    // Edge case
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // Regular cases
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    int ans = a > 0 ? a : b;

    return ans;
}

int findGCD(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int first = nums[0];
    int last = nums[nums.size() - 1];

    int ans = findHCF(first, last);

    return ans;
}

// GFG: Modular exponentiation for large numbers
long long int PowMod(long long int x, long long int n, long long int M)
{
    long long int ans = 1;

    while (n > 0)
    {
        // Agar abhi wala 'n' value odd hai
        // to n/=2 karne pe yeh kho na jaye isliye
        // ek baar pehle hi ans*a kr lo
        if (n & 1)
            ans = (ans * x) % M;

        x = (x * x) % M; // Itself se multiply
        n >>= 1;         // n = n/2;
    }

    return ans % M;
}

// LEETCODE: 372. Super pow
int findFastExpo(long long a, int n)
{
    int ans = 1;

    while (n > 0)
    {
        if (n & 1)
            ans = (ans * a) % 1337;

        a = (a * a) % 1337;
        n >>= 1;
    }

    return ans % 1337;
}

int superPow(int a, vector<int> &b)
{
    int ans = 1;
    for (int i = 0; i < b.size(); i++)
    {
        ans = (findFastExpo(ans, 10) * findFastExpo(a, b[i])) % 1337;
    }

    return ans;
}
