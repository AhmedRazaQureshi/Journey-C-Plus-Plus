#include <bits/stdc++.h>
using namespace std;

// Ques#01: Find median from a data stream
int signum(int m1, int m2)
{
    if(m1 == m2)  return 0;
    if(m1 > m2)   return 1;
    if(m1 < m2)   return -1;
}

void callMedian(double& median, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap, int currElement)
{
    //1. There can be 3 states of MaxHeap--Median--MinHeap
    int m1 = maxHeap.size();
    int m2 = minHeap.size();
    int currCase = signum(m1, m2);
    
    //2. Based on case, you need to do i) Accomodate currElement into one of the Heaps, ii) Update median
    switch(currCase)
    {
        case 0: //MaxHeap == MinHeap  => median was avg(MaxHeap.top(),MinHeap.top()); [left+right se nikla tha]
                if(currElement > median) // => Push in right (minHeap)
                {
                    minHeap.push(currElement);
                    median = minHeap.top();
                }
                else // => Push in left (maxHeap)
                {
                    maxHeap.push(currElement);
                    median = maxHeap.top();
                }
                break;

        case 1: //MaxHeap > MinHeap  => median was MaxHeap.top() [left mein pda tha]
                if(currElement > median) // => Push in right (minHeap)
                {
                    minHeap.push(currElement);
                    median = (maxHeap.top()+minHeap.top()) / 2.0;
                }
                else // => Push in left (maxHeap)
                {
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(currElement);

                    minHeap.push(temp);

                    median = (maxHeap.top()+minHeap.top()) / 2.0;
                }
                break;

        case -1: //MaxHeap < MinHeap => median was MinHeap.top() [right mein pda tha]
                if(currElement > median) // => push in right (minHeap)
                {
                    int temp = minHeap.top();
                    minHeap.pop();
                    minHeap.push(currElement);

                    maxHeap.push(temp);

                    median = (maxHeap.top()+minHeap.top()) / 2.0;
                }
                else // => push in left (maxHeap)
                {
                    maxHeap.push(currElement);
                    median = (maxHeap.top()+minHeap.top()) / 2.0;
                }
                break;
    }
}

int main()
{
    vector<int> v = {5,15,1,3,2,8,7,9,10,6,11,4};
    int n = 12;

    double median = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0; i<n; i++)
    {
        callMedian(median, maxHeap, minHeap, v[i]);
        cout<<"Median-"<<i<<" : "<<median<<endl;
    }


    return 0;
}