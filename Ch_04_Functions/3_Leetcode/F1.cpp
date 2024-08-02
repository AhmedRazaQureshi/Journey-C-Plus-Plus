#include <bits/stdc++.h>

// LEETCODE: 191. Number of 1 Bits
int countSetBits(int n)
{
    int count = 0;

    while (n)
    {
        if (n & 1)
            count++;

        n = n >> 1;
    }

    return count;
}


//LEETCODE: 1290. Convert Binary Number in a Linked List to Integer
int binaryToDecimal(string n)
{
    int dec = 0;
    int bitIndex = 0; // to traverse 'n' from R to L

    // Logic jis bhi bitIndex par 1 pada hai bass uski pow(2, bitIndex) kr k
    // add krna hai
    for (int i = n.length() - 1; i >= 0; i--)
    {
        char lastBit = n[i];

        if (lastBit == '1')
        {
            dec += pow(2, bitIndex);
        }

        n.pop_back();

        bitIndex++;
    }

    return dec;
}

int getDecimalValue(ListNode *head)
{
    // Traverse the LL & store the number
    ListNode *p = head;
    string num = "";

    while (p != NULL)
    {
        int currNum = p->val;
        if (currNum == 1)
            num.push_back('1');
        else if (currNum == 0)
            num.push_back('0');

        p = p->next;
    }

    int ans = binaryToDecimal(num);

    return ans;
}