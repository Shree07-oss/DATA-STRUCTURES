bool check(struct ListNode **left, struct ListNode *right)
{
    if (right == NULL)
        return true;

    if (check(left, right->next) == false)
        return false;

    if ((*left)->val != right->val)
        return false;

    *left = (*left)->next;

    return true;
}

bool isPalindrome(struct ListNode* head)
{
    return check(&head, head);
}
