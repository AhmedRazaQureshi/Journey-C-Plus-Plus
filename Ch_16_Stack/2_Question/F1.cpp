#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// Ques#01: String reversal using stack
void stringRev(string& s)
{
    stack<char> st1;
    for(int i=0; i<s.length(); i++)
        st1.push(s[i]);

    int i=0;
    while(!st1.empty())
    {
        s[i] = st1.top();
        st1.pop();
        i++;
    }
}

// Ques#02: Find middle element in a stack
int findMiddle(stack<int>& st1, int initialSize)
{
    //Corner case: No element in stack
    if(st1.size() == 0) 
        return -1;

    //BC
    if(st1.size() == (initialSize/2)+(initialSize%2))
        return st1.top();

    //Rec
    int temp = st1.top();
    st1.pop();
    int ans = findMiddle(st1, initialSize);
    st1.push(temp);
    return ans;
}

// Ques#03: Insert at bottom of stack (top ko utha k bottom mein daal do)
void insertAtBottom(stack<int>& st1, int target)
{
    if(st1.empty())
    {
        st1.push(target);
        return;
    }

    int temp = st1.top();
    st1.pop();
    insertAtBottom(st1, target);
    st1.push(temp);
}

// Ques#04: Reverse a stack
void revStack(stack<int>& st1)
{
    if(st1.empty())
        return;

    int currTop = st1.top();
    st1.pop();
    revStack(st1);
    insertAtBottom(st1, currTop);
}

// Ques#05: Sort a stack
void insertInSortedStack(stack<int>& st, int val)
{
    //BC
    if(st.empty())
    {
        st.push(val);
        return;
    }

    if(st.top() >= val)
        st.push(val);
    else
    {
        int temp = st.top();
        st.pop();
        insertInSortedStack(st,val);
        st.push(temp);
    }
}

void sortStack(stack<int>& st)
{
    //BC
    if(st.empty())
        return;

    int temp = st.top();
    st.pop();
    sortStack(st);

    insertInSortedStack(st,temp);
}

// Ques#06: Remove redundant brackets
void removeRedunBrac(string& s)
{
    stack<pair<int,char>> st;

    for(int i=0; i<s.length(); i++)
    {
        //Case: '(' or Operator encountered
        if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*')
            st.push({i,s[i]});

        //Case: ')' encountered
        else if(s[i]==')')
        {
            if(!st.empty())
            {
                //Subcase-1: st.top() is an operator => Useful => Do nothing
                if(st.top().second=='+' || st.top().second=='-' || st.top().second=='/' || st.top().second=='*')
                {
                    //Pop these useful brackets & operators
                    while(st.top().second != '(') st.pop();
                    //Now pop this '(' as well
                    st.pop();
                }
                //Subcase-2: st.top() is not an operator => Useless => Modify string
                else
                {
                    s[i] = ' ';
                    s[st.top().first]=' ';

                    st.pop();
                }

            }
        }
    }

    //Remove blank spaces
    s.erase(remove(s.begin(),s.end(),' '), s.end());
}

// Ques#07: Next smaller element
vector<int> nextSmaller(vector<int>& v)
{
    vector<int> ans(v.size());

    stack<int> st;
    st.push(-1);

    for(int i=v.size()-1; i>=0; i--)
    {
        int curr = v[i];
        while( !(st.top()<curr) )
            st.pop();
        
        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}

// Ques#08: Previous smaller element
vector<int> prevSmaller(vector<int>& v)
{
    vector<int> ans(v.size());

    stack<int> st;
    st.push(-1);

    for(int i=0; i<v.size(); i++)
    {
        int curr = v[i];

        while( !(st.top() < curr) )
            st.pop();

        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}

int main()
{
    // Ques#01: String reversal using stack
    string s1 = "AhmedRazaQureshi";
    stringRev(s1);
    cout<<"After reversal: "<<s1<<endl;

    // Ques#02: FInd middle element in a stack
    stack<int> st1({1,2,3,4,5}); //top->5
    cout<<"Middle element of stack: "<<findMiddle(st1, st1.size())<<endl;

    // Ques#03: Insert at bottom of stack (top ko utha k bottom mein daal do)
    cout<<"After insertAtBottom: top->";
    //Corner case: Empty stack
    if(st1.empty())
        cout<<""<<endl;
    else
    {
        int target = st1.top();
        st1.pop();
        insertAtBottom(st1, target);
        while(!st1.empty()) {cout<<st1.top()<<","; st1.pop(); }
    }
    cout<<endl;
    
    // Ques#04: Reverse a stack
    stack<int> st2({10,20,30,40,50}); //top->50
    cout<<"After reverse: top->";
    revStack(st2);
    while(!st2.empty()) {cout<<st2.top()<<","; st2.pop(); }
    cout<<endl;
    
    // Ques#05: Sort a stack
    stack<int> st3({7,11,3,5,9}); //Top->9
    cout<<"After sorting: ";
    sortStack(st3);
    while(!st3.empty()) {cout<<st3.top()<<","; st3.pop(); }
    cout<<endl;

    // Ques#06: Remove redundant brackets
    string s2 = "(()(a+b))"; //Output: (a+b)
    cout<<"After redundant bracket removal: ";
    removeRedunBrac(s2);
    cout<<s2<<endl;

    // Ques#07: Next smaller element
    vector<int> v1 = {2,1,4,3};
    vector<int> ans1 = nextSmaller(v1);
    cout<<"Next smaller array: ";
    for(auto i: ans1) cout<<i<<",";
    cout<<endl;

    // Ques#08: Previous smaller element
    vector<int> v2 = {2,1,4,3};
    vector<int> ans2 = prevSmaller(v2);
    cout<<"Previous smaller array: ";
    for(auto i: ans2) cout<<i<<",";
    cout<<endl;




    return 0;
}
