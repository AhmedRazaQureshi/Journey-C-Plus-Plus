// LEETCODE: 206. Reverse Linked List
// M-1: Iterative :----------------------------------
ListNode *reverse_SLL_iterative(ListNode *&head)
{
    // Case: Empty LL
    if (head == NULL)
        return NULL;

    // Case: Onlyt 1 node in LL
    if (head->next == NULL)
        return head;

    // Case: Regular cases
    ListNode *prv = NULL;
    ListNode *crr = head;
    ListNode *nxt = head->next;

    while (nxt != NULL)
    {
        crr->next = prv;

        prv = crr;
        crr = nxt;
        nxt = nxt->next;
    }

    crr->next = prv;
    head = crr;

    return head;
}

// M-2: Recursive :------------------------------
ListNode *reverse_SLL_recursive(ListNode *&head, ListNode *prv, ListNode *crr, ListNode *nxt)
{
    // BC
    if (nxt == NULL)
    {
        crr->next = prv;
        head = crr;
        return head;
    }

    // Rec
    crr->next = prv;

    prv = crr;
    crr = nxt;
    nxt = nxt->next;

    return reverse_SLL_recursive(head, prv, crr, nxt);
}

ListNode *reverseList(ListNode *&head)
{
    // Case: Empty LL
    if (head == NULL)
        return NULL;

    // Case: Onlyt 1 node in LL
    if (head->next == NULL)
        return head;

    return reverse_SLL_recursive(head, NULL, head, head->next);
}

// LEETCODE: 876. Middle of the linked list
// M-1: By using length :----------------------------
int findLength(ListNode *ptr)
{
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

ListNode *findMiddleByLength(ListNode *head)
{
    int len = findLength(head);
    int mid = len / 2;

    while (mid--)
    {
        head = head->next;
    }
    return head;
}

ListNode *middleNode(ListNode *head)
{
    return findMiddleByLength(head);
}

// M-2: By using slow-fast
ListNode *findMiddleBySlowFast(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL)
    {
        fast = fast->next; // Moving 1 step forward
        if (fast != NULL)
        {
            fast = fast->next; // Moving 2 step forward
            slow = slow->next;
        }
    }
    return slow;
}

ListNode *middleNode(ListNode *head)
{
    return findMiddleBySlowFast(head);
}

// LEETCODE: 25. Reverse nodes in k-group
int findLength(ListNode *ptr)
{
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    // Edge case-1
    if (head == NULL || head->next == NULL || k <= 1)
        return head;

    // Edge case-2
    int length = findLength(head);
    if (k > length)
        return head;

    // Step-1: Reverse the first k nodes
    ListNode *prv = NULL;
    ListNode *crr = head;
    ListNode *nxt = head->next;

    int count = 0;

    while (count < k)
    {
        nxt = crr->next; //[BE CAREFUL] nxt ko yaha loop mein hi update karo, taki nullPtr dereference na ho

        crr->next = prv;

        prv = crr;
        crr = nxt;

        count++;
    }

    // head is now the last node of the reversed segment
    if (nxt != NULL)
    {
        head->next = reverseKGroup(nxt, k);
    }

    // prv is the new head of the reversed segment
    return prv;
}

// LEETCODE: 141. Linked list cycle
// M-1: Using slow-fast
bool hasCycle(ListNode *head)
{
    // Edge case-1: Empty LL
    if (head == NULL)
        return false;

    // Edge case-2: Only 1 node in LL
    if (head->next == head)
        return true;
    if (head->next == NULL)
        return false;

    // Regular cases: nodes >= 2
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;

            if (slow == fast)
                return true;
        }
    }
    return false;
}

// M-2: Using map of visited
bool hasCycle(ListNode *head)
{
    // Edge case-1: Empty LL
    if (head == NULL)
        return false;

    // Edge case-2: Only 1 node in LL
    if (head->next == head)
        return true;
    if (head->next == NULL)
        return false;

    // Regular cases: nodes >= 2
    ListNode *ptr = head;
    unordered_map<ListNode *, bool> visited;

    while (ptr != NULL)
    {
        if (visited.find(ptr) == visited.end()) // Yeh ptr not visited hai
        {
            visited[ptr] = true;
        }
        else // Yeh ptr visited hai
            return true;

        ptr = ptr->next;
    }

    // List khatam ho gyi
    return false;
}

// LEETCODE: 142. Linked list cycle 2
// M-1: Using slow-fast
ListNode *detectCycle(ListNode *head)
{
    // Edge cases
    if (head == NULL || head->next == NULL)
        return NULL;
    if (head->next == head)
        return head;

    // Regular cases
    // Step-1: Slow & Fast ko meet karao
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;

            if (slow == fast)
                break;
        }
    }

    // Edge case: agar loop hai hi nahi, to fast null hogya hoga
    if (fast == NULL)
        return NULL;

    // Regular cases contd..
    // Step-2: Slow ko firse Head se shuru kara do
    slow = head;

    // Step-3: Move Slow & Fast 1-1 step until they meet
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; //(or) return fast
}

// Method-2: Using map of visited
ListNode *detectCycle(ListNode *head)
{
    // Edge cases
    if (head == NULL || head->next == NULL)
        return NULL;
    if (head->next == head)
        return head;

    // Regular cases
    unordered_map<ListNode *, bool> visited;

    ListNode *ptr = head;

    while (ptr != NULL)
    {
        if (visited.find(ptr) == visited.end())
        {
            visited[ptr] = true;
        }
        else
        {
            return ptr;
        }

        ptr = ptr->next;
    }
    return NULL;
}

// GFG: Remove loop in linked list
void removeLoop(Node *head)
{
    // Edge case
    if (head == NULL || head->next == NULL)
        return;

    // Step-1: Detect loop using slow and fast pointers
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet, a loop is detected
        if (slow == fast)
            break;
    }

    // Edge case: No loop detected
    if (fast == NULL || fast->next == NULL)
        return;

    // Step-2: Find the start of the loop
    slow = head;

    // Special case when loop starts at the head
    if (slow == fast)
    {
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
        return;
    }

    // Step-3: Move slow and fast at the same pace to find the loop start
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Step-4: Remove the loop
    fast->next = NULL;
}

// LEETCODE: 234. Palindrome linked list
// M-1: O(n) time & O(n) space
bool isPalindrome(ListNode *head)
{
    vector<int> rev;

    ListNode *ptr = head;
    while (ptr != NULL)
    {
        rev.push_back(ptr->val);
        ptr = ptr->next;
    }
    reverse(rev.begin(), rev.end());

    ptr = head;
    for (int i = 0; i < rev.size(); i++)
    {
        if (rev[i] != ptr->val)
            return false;

        ptr = ptr->next;
    }

    return true;
}

// M-2: O(n) time & O(1) space
ListNode *findMiddleBySlowFast(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL)
    {
        fast = fast->next; // Moving 1 step forward
        if (fast != NULL)
        {
            fast = fast->next; // Moving 2 step forward
            slow = slow->next;
        }
    }
    return slow;
}

ListNode *reverse_SLL_recursive(ListNode *&head, ListNode *prv, ListNode *crr, ListNode *nxt)
{
    // BC
    if (nxt == NULL)
    {
        crr->next = prv;
        head = crr;
        return head;
    }

    // Rec
    crr->next = prv;

    prv = crr;
    crr = nxt;
    nxt = nxt->next;

    return reverse_SLL_recursive(head, prv, crr, nxt);
}

bool isPalindrome(ListNode *head)
{
    ListNode *mid = findMiddleBySlowFast(head);
    reverse_SLL_recursive(mid, NULL, mid, mid->next);

    ListNode *ptr = head;
    while (mid != NULL && ptr != NULL)
    {
        if (mid->val != ptr->val)
            return false;

        mid = mid->next;
        ptr = ptr->next;
    }

    return true;
}

// LEETCODE: 83. Remove duplicates from sorted list
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *q = head;
    ListNode *p = head->next;

    while (p != NULL)
    {
        if (q->val == p->val)
        {
            ListNode *temp = p;

            p = p->next;
            q->next = p;

            delete temp;
            temp = NULL;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    return head;
}

// GFG: Remove duplicates from an unsorted linked list
// M-1: Double loop (TLE aagya)
Node *removeDuplicates(Node *head)
{
    Node *i = head;
    while (i != NULL)
    {
        Node *j = i->next;
        Node *q = i; // Tailing ptr

        while (j != NULL)
        {
            if (i->data == j->data)
            {
                Node *temp = j;
                j = j->next;
                q->next = j;
                temp->next = NULL;
                delete temp;
            }
            else
            {
                q = j;
                j = j->next;
            }
        }
        i = i->next;
    }

    return head;
}

// M-2: Map
Node *removeDuplicates(Node *head)
{
    unordered_map<int, Node *> visited;

    Node *ptr = head;
    Node *q = NULL;
    while (ptr != NULL)
    {
        if (visited.find(ptr->data) != visited.end())
        {
            Node *temp = ptr;
            ptr = ptr->next;
            q->next = ptr;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            visited[ptr->data] = ptr;
            q = ptr;
            ptr = ptr->next;
        }
    }

    return head;
}

// M-3: Sorting & Remove duplicate from sorted LL
// BAAD MEIN KAR LENE

// CodeingNinjas: Sort linked list of 0s 1s 2s
Node *sortList(Node *head)
{
    Node *zero = new Node(-1);
    Node *i = zero;

    Node *one = new Node(-1);
    Node *j = one;

    Node *two = new Node(-1);
    Node *k = two;

    Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == 0)
        {
            Node *temp = ptr;
            ptr = ptr->next;
            temp->next = NULL;

            i->next = temp;
            i = i->next;
        }
        else if (ptr->data == 1)
        {
            Node *temp = ptr;
            ptr = ptr->next;
            temp->next = NULL;

            j->next = temp;
            j = j->next;
        }
        else
        {
            Node *temp = ptr;
            ptr = ptr->next;
            temp->next = NULL;

            k->next = temp;
            k = k->next;
        }
    }

    i->next = one->next;
    j->next = two->next;

    return zero->next;
}

// LEETCODE: 445. Add two numbers 2
ListNode *reverseLL(ListNode *head, ListNode *prv, ListNode *crr, ListNode *nxt)
{
    // BC
    if (nxt == NULL)
    {
        crr->next = prv;
        head = crr;
        return head;
    }

    // Rec
    crr->next = prv;

    return reverseLL(head, crr, nxt, nxt->next);
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // Step-1: Reverse both list
    l1 = reverseLL(l1, NULL, l1, l1->next);
    l2 = reverseLL(l2, NULL, l2, l2->next);

    // Final answer ki list banane k liye
    ListNode *start = NULL;
    ListNode *end = NULL;

    // Step-2:
    int carry = 0;

    while (l1 && l2)
    {
        int currVal = l1->val + l2->val + carry;
        int digit = currVal % 10;

        carry = 0;
        carry += currVal / 10;

        l1 = l1->next;
        l2 = l2->next;

        ListNode *newNode = new ListNode(digit);

        // Insertion at tail
        if (end == NULL)
        {
            start = newNode;
            end = newNode;
        }
        else
        {
            end->next = newNode;
            end = newNode;
        }
    }

    while (l1)
    {
        int currVal = carry + l1->val;
        int digit = currVal % 10;
        carry = 0;
        carry += currVal / 10;
        ;
        ListNode *newNode = new ListNode(digit);
        l1 = l1->next;

        // Insertion at tail
        if (end == NULL)
        {
            start = newNode;
            end = newNode;
        }
        else
        {
            end->next = newNode;
            end = newNode;
        }
    }

    while (l2)
    {
        int currVal = carry + l2->val;
        int digit = currVal % 10;
        carry = 0;
        carry += currVal / 10;
        ;
        ListNode *newNode = new ListNode(digit);
        l2 = l2->next;

        // Insertion at tail
        if (end == NULL)
        {
            start = end = newNode;
        }
        else
        {
            end->next = newNode;
            end = newNode;
        }
    }

    while (carry)
    {
        int digit = carry % 10;
        carry /= 10;

        ListNode *newNode = new ListNode(digit);

        // Insertion at tail
        if (end == NULL)
        {
            start = newNode;
            end = newNode;
        }
        else
        {
            end->next = newNode;
            end = newNode;
        }
    }

    start = reverseLL(start, NULL, start, start->next);

    return start;
}
