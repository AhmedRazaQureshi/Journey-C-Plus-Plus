//Question: On WAF (Write A Function)

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//Ques#01: Factorial
long long findFactorial(int n)
{
    //Edge case
    if(n<0)
        return -1;

    //Base case
    if(n==1)
        return 1;
    
    //Recursion
    return n*findFactorial(n-1);
}

//Ques#02: To check if 'n' is prime
bool isPrime(int n)
{
    //Edge case
    if(n<2)
        return false;

    //Iteration
    int rootN = (int)sqrt(n);

    for(int i=2; i<=rootN; i++)
        if(n%i == 0)
            return false;

    return true;
}

//Ques#03: All primes from 1 to n
vector<int> allPrimes(int n)
{
    vector<int> primes;

    for(int i=2; i<=n; i++)
        if(isPrime(i))
            primes.push_back(i);

    return primes;

}

//Ques#04: Reverse 'n'
int reverseNumber(int n)
{
    int num = n;

    bool isNegative = false;
    if(n<0)
    {
        isNegative = true;
        num = num*(-1);
    }
        
    int digit;
    int revNum=0;
    while(num)
    {
        digit = num%10;
        num/=10;

        revNum = (revNum*10) + digit;
    }

    if(isNegative)
        revNum *= (-1);

    
    return revNum;
}

//Ques#05: Get digits of 'n'
vector<int> getDigits(int n)
{
    vector<int> digits;

    //Edge case
    if(n == 0)
        return {0};

    //Regular code
    if(n<0)
        n = n*(-1);

    while(n)
    {
        digits.push_back(n%10);
        n/=10;
    }

    return digits;
}

//Ques#06: Count set bits in binary of 'n'
//LEETCODE: 191. Number of 1 Bits
int countSetBits(int n)
{
    int count = 0;

    while(n)
    {
        if(n&1)
            count++;
        
        n = n>>1;
    }

    return count;
}

//Ques#07: Decimal to Binary
long long decimalToBinary(int n)
{
    long long bin=0;

    while(n)
    {
        bool lastBit = n&1;
        bin = (bin*10)+lastBit;
        n = n>>1;
    }  

    return bin;
}

//Ques#08: Binary to Decimal
//LEETCODE: 1290. Convert Binary Number in a Linked List to Integer
long long binaryToDecimal(long long n)
{
    long long dec=0;
    int bitIndex=0; //to traverse 'n' from R to L

    //Logic jis bhi bitIndex par 1 pada hai bass uski pow(2, bitIndex) kr k add krna hai
    while(n)
    {
        bool lastBit = n%10;

        if(lastBit == 1)
        {
            dec += pow(2, bitIndex);
        }
            

        n /= 10;;
        bitIndex++;
    }

    return dec;
}


int main()
{
    int n1 = 5;
    cout<<findFactorial(n1)<<endl;

    int n2 = 139;
    cout<<isPrime(n2)<<endl;

    int n3 = 100;
    vector<int> primes = allPrimes(n3);
    for(int i=0; i<primes.size(); i++)
        cout<<primes[i]<<", ";
    cout<<endl;

    int n4 = -1234;
    cout<<reverseNumber(n4)<<endl;

    int n5 = 1234;
    vector<int> digits = getDigits(n5);
    cout<<"Digits of number: ";
    for(int i=0; i<digits.size(); i++)
        cout<<digits[i]<<", ";
    cout<<endl;

    int n6 = 1025;
    cout<<countSetBits(n6)<<endl;

    int n7 = 5;
    cout<<decimalToBinary(n7)<<endl;

    long long n8 = 10000000001;
    cout<<binaryToDecimal(n8)<<endl;


    return 0;
}