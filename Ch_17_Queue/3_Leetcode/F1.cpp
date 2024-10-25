// GFG: Queue Reversal
void solve(queue<int> &q1)
{
    // BC
    if (q1.empty())
        return;

    int temp = q1.front();
    q1.pop();
    solve(q1);
    q1.push(temp);
}

queue<int> rev(queue<int> q)
{
    solve(q);
    return q;
}

// GFG: Reverse First K elements of Queue
void solve(queue<int> &q1, int k)
{
    // BC
    if (q1.empty() || k <= 0)
        return;

    int temp = q1.front();
    q1.pop();
    solve(q1, k - 1);
    q1.push(temp);
}

queue<int> modifyQueue(queue<int> q, int k)
{
    solve(q, k);

    int x = q.size() - k;
    while (x--)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
    return q;
}

// GFG: Interleave the First Half of the Queue with Second Half
vector<int> rearrangeQueue(queue<int> &q)
{
    int n = q.size();
    queue<int> firstHalf;

    for (int i = 0; i < n / 2; i++)
    {
        firstHalf.push(q.front());
        q.pop();
    }

    vector<int> ans;

    while (!firstHalf.empty() && !q.empty())
    {
        ans.push_back(firstHalf.front());
        ans.push_back(q.front());

        firstHalf.pop();
        q.pop();
    }

    if (n & 1)
        ans.push_back(q.front());

    return ans;
}

// GFG: First negative in every window of size k
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int k)
{
    vector<long long> ans;

    // 1. Process first window of size 'K'
    queue<long long int> q1;

    for (long long int i = 0; i < k; i++)
    {
        if (A[i] < 0)
            q1.push(i);
    }

    // 2. Process reamining windows
    for (long long int i = k; i < N; i++)
    {
        // Previous window ka answer nikal lo
        if (!q1.empty())
            ans.push_back(A[q1.front()]);
        else
            ans.push_back(0);

        // Remove out of window elements (if any)
        if (!q1.empty() && !(i - k + 1 <= q1.front() && q1.front() <= i))
            q1.pop();

        // Naye element ka index dalo (if voh -ve hai to)
        if (A[i] < 0)
            q1.push(i);
    }

    // Last wali window ka answer nikal do
    if (!q1.empty())
        ans.push_back(A[q1.front()]);
    else
        ans.push_back(0);

    return ans;
}

// LEETCODE: 387. First Unique Character in a String
int firstUniqChar(string s)
{
    int freq[26] = {0};
    queue<int> q;

    for (int i = 0; i < s.length(); i++)
    {
        // 1. Frequency ++
        freq[s[i] - 'a']++;
        // 2. Push in queue
        q.push(i);
        // 3. Check if q.front() is a repeating character
        while (!q.empty())
        {
            if (freq[s[q.front()] - 'a'] > 1)
                q.pop();
            else
                break;
        }
    }

    if (q.empty())
        return -1;

    return q.front();
}

//LEETCODE: 
