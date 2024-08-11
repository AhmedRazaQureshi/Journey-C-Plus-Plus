// Questions:-----
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Ques#01: Find all primes strictly less than 'n' by using Sieve of Eratosthenes
// Method-1: Sieve of Eratosthenes
vector<int> findPrimesSieve(int n)
{
    // Step-1: Create array [2 to n-1]
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

// Method-2: Optimised Sieve of Eratosthenes (primes strictly less than n)
vector<int> findPrimesSieveOpt(int n)
{
    vector<bool> sieve(n, true);
    vector<int> primes;
    for (int i = 2; i * i <= n; i++) // opt-2: i<=sqrt(n)  i.e.  i*i <= n
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j <sieve.size(); j += i) // opt-1: j=i*i   opt-2:
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

// Ques#02: Find all prime no.s in the range 'L' to 'R' (inclusive) by using Segmented Sieve
vector<int> findPrimesSegSieve(int L, int R)
{
    //REH RAHA HAI
    return {};
}

//Ques#03: Find HCF & LCM of a & b
//LEETCODE: 1979. Find Greatest Common Divisor of Array
int findHCF(int a, int b)
{
    //Edge case
    if(a == 0) return b;
    if(b == 0) return a;

    //Regular cases
    while(a>0 && b>0)
    {
        if(a>b) a = a-b;
        else    b = b-a;
    }

    int ans = a>0 ? a : b;

    return ans;
}

int findLCM(int a, int b)
{
    int hcf = findHCF(a,b);

    int ans = (a*b)/hcf;

    return ans;
}

//Ques#04: Fast exponentiation (find a^n in lgN time)
// GFG: Modular exponentiation for large numbers
//LEETCODE: 372. Super pow
long long findFastExpo(long long a, long long n)
{
    long long ans = 1;

    while(n > 0)
    {
        //Agar abhi wala 'n' value odd hai
        //to n/=2 karne pe yeh kho na jaye isliye 
        //ek baar pehle hi ans*a kr lo 
        if(n&1) 
            ans *= a;


        
        a = a*a; //Itself se multiply
        n >>= 1; //n = n/2;
    }

    return ans;
}

int main()
{
    // Ques#01: Find all prime no.s less than 'n' by using Sieve of Eratosthenes
    vector<int> v1 = findPrimesSieve(97);
    cout<<"By Sieve: ";
    for (auto i : v1)
        cout << i << ",";
    cout << endl;

    vector<int> v2 = findPrimesSieveOpt(97);
    cout<<"By Sieve-OPT: ";
    for (auto i : v2)
        cout << i << ",";
    cout << endl;

    // Ques#02: Find all prime no.s in the range 'L' to 'R' by using Segmented Sieve
    cout<<"By Seg-Sieve: ";
    vector<int> v3 = findPrimesSegSieve(110, 130);
    for (auto i : v3)
        cout << i << ",";
    cout << endl;

    //Ques#03: Find HCF & LCM of a & b
    int hcf = findHCF(72,24);
    int lcm = findLCM(72,24);
    cout<<"HCF & LCM of (72 & 24): "<<hcf<<","<<lcm<<endl;

    //Ques#04: Fast exponentiation (find a^n in lgN time)
    int a = 2;
    int n = 10;
    cout<<"a^n : "<<findFastExpo(a,n)<<endl;



    return 0;
}