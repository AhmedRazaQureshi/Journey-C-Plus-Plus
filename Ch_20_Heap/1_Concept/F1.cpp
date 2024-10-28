#include <bits/stdc++.h>
using namespace std;

/* Concept: MaxHeap
    0. Heap using arrays, 
    1. Bottom-Up-Heapify
    2. Insertion
    3. Top-Down-Heapify
    4. Deletion
    5. Build heap from input
*/
class Heap
{
    // 0. Heap using arrays
    public:
    vector<int> arr;
    int size;

    Heap()
    {
        size = 0;
    }
    
    // 1. Bottom-Up-Heapify
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

    // 2. Insertion
    void insertion(int val)
    {
        //A. Insert at end
        arr.push_back(val);
        size++;

        //B. Heapify
        int i = size-1;         //Index of newly inserted element
        int par_i = (i-1)/2;    //Index of parent of i
        heapify_bottom_to_top(i, par_i);
    }

    // 3. Top-Down-Heapify
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

    // 4. Deletion
    void deletion()
    {
        //A. Swap first & last element 
        swap(arr[0], arr[size-1]);

        //B. Delete the last element
        arr.pop_back();
        size--;

        //C. Heapify
        heapify_top_to_bottom(0);
    }

    // 5. Build heap from input
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

    // Display
    void display()
    {
        for(auto i: arr)
            cout<<i<<",";
        cout<<endl;
    }

};


int main()
{
    //1. Bottom-Up-Heapify & 2. Insertion
    Heap h1;

    h1.insertion(1);
    h1.insertion(2);
    h1.insertion(3);
    h1.insertion(4);
    h1.insertion(5);

    h1.display();

    //3. Top-Down-Heapify & 4. Deletion
    h1.deletion();

    h1.display();

    //5. Build heap from input
    vector<int> inp = {5,10,20,40,45,55,50,60,100};
    Heap h2;
    h2.buildHeap(inp);

    h2.display();


}