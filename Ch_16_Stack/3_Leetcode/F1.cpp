// LEETCODE: 20. Valid parentheses
bool isValid(string &s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char currChar = s[i];

        // Opening bracket encounter
        if (currChar == '(' || currChar == '{' || currChar == '[')
            st.push(currChar);

        // Closing baracket encounter
        if (currChar == ')' || currChar == '}' || currChar == ']')
        {
            if (!st.empty())
            {
                if (st.top() == '(' && currChar == ')' ||
                    st.top() == '{' && currChar == '}' ||
                    st.top() == '[' && currChar == ']')
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }
    }

    if (st.empty())
        return true;
    else
        return false;
}

// LEETCODE: 155. Min stack
class MinStack
{
public:
    vector<pair<int, int>> st;

    MinStack()
    {
    }

    void push(int val)
    {
        // Insertion as first element
        if (st.empty())
        {
            st.push_back({val, val});
        }
        // Regular insertion
        else
        {
            int temp = st.back().second;
            st.push_back({val, min(val, temp)});
        }
    }

    void pop()
    {
        st.pop_back();
    }

    int top()
    {
        return st.back().first;
    }

    int getMin()
    {
        return st.back().second;
    }
};

// LEETCODE: 32. Longest valid parentheses
int longestValidParentheses(string &s)
{
    stack<int> st;
    st.push(-1);
    int maxLen = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(i);

        else
        {
            st.pop();

            if (!st.empty())
                maxLen = max(maxLen, i - st.top());
            else
                st.push(i);
        }
    }
    return maxLen;
}

// LEETCODE: 84. Largest Rectangle in Histogram
vector<int> prevSmaller(vector<int> &v)
{
    vector<int> ans(v.size());

    stack<int> st;
    st.push(-1);

    for (int i = 0; i < v.size(); i++)
    {
        int curr = v[i];

        while (!(st.top() == -1) && !(v[st.top()] < curr))
            st.pop();

        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> nextSmaller(vector<int> &v)
{
    vector<int> ans(v.size());

    stack<int> st;
    st.push(-1);

    for (int i = v.size() - 1; i >= 0; i--)
    {
        int curr = v[i];

        while (!(st.top() == -1) && !(v[st.top()] < curr))
            st.pop();

        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int getMaxArea(vector<int> &heights)
{
    vector<int> prv = prevSmaller(heights);
    vector<int> nxt = nextSmaller(heights);

    for (int i = 0; i < nxt.size(); i++)
        if (nxt[i] == -1)
            nxt[i] = nxt.size();

    int maxArea = INT_MIN;

    for (int i = 0; i < heights.size(); i++)
    {
        int base = nxt[i] - prv[i] - 1;
        int height = heights[i];
        int area = base * height;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int largestRectangleArea(vector<int> &heights)
{
    int ans = getMaxArea(heights);
    return ans;
}

