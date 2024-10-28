#include <bits/stdc++.h>
using namespace std;

// Concept: Heap-Sort
class Heap
{
    public:
    vector<int> arr;
    int size;

    Heap()
    {
        size = 0;
    }

    void heapify_bottom_to_top(int i, int par_i)
    {
        // So that insertion-as-first node pe heapify krna hi na padey
        if(size < 2)
            return;

        while(arr[i] > arr[par_i])  
        {   
            if(i <= 0) //Top tak pohoch gaye
                break;
            
            swap(arr[i], arr[par_i]);

            i = par_i;
            par_i = (i-1)/2;
        }
    }

    void heapify_top_to_bottom(int i)
    {
        while (true)
        {
            int i_leftChild = 2 * i + 1;
            int i_rightChild = 2 * i + 2;
            int largest = i;

            if (i_leftChild < size && arr[i_leftChild] > arr[largest])
                largest = i_leftChild;

            if (i_rightChild < size && arr[i_rightChild] > arr[largest])
                largest = i_rightChild;

            if (largest == i) // No swap needed
                break;

            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

    void buildHeap(vector<int> input)
    {
        for(auto key: input)
        {
            arr.push_back(key);
            size++;

            int i = size-1;
            int par_i = (i-1)/2;
            heapify_bottom_to_top(i, par_i);
        }
    }

    void heapSort(vector<int>& inpt)
    {
        //1. Build Heap
        buildHeap(inpt);

        //2. Delete elements one by one 
        while(size > 0)
        {
            //A. Delete 
            swap(arr[0], arr[size-1]);
            size--;
            
            //B. Heapify
            heapify_top_to_bottom(0);
        }

        inpt = arr;
    }


};

int main()
{
    vector<int> inpt = {6,1,7,2,8,3,9,4,10,5};
    Heap h1;
    h1.heapSort(inpt);    

    for(auto i: inpt)
        cout<<i<<",";
    cout<<endl;

}