#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    smaller = nullptr;
    larger = nullptr;
    
    llpivotHelper(head, smaller, larger, pivot);
    head = nullptr;
}

void llpivotHelper(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    if (head == nullptr)
    {
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    if (head->val <= pivot)
    {
        smaller = head;
        llpivotHelper(head->next, smaller->next, larger, pivot);
    }
    else
    {
        larger = head;
        llpivotHelper(head->next, smaller, larger->next, pivot);
    }
    
}
