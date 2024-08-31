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

ListNode *reverse_SLL_recursive(ListNode *&head)
{
    // BC
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;

    // Rec
}

ListNode *reverseList(ListNode *&head)
{
    return reverse_SLL_iterative(head);
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

//