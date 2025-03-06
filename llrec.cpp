#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

void print(Node* head);
/**
 * Given a linked list pointed to by head, creates two lists
 * where all values less than or equal to the pivot value are
 * placed in a linked list whose head will be pointed to by
 * smaller and all values greater than the pivot
 * value are placed in a linked list whose head will be pointed to
 * by larger.  The input list pointed to by head should be empty
 * upon return and head set to NULL (i.e. we are not making copies)
 * in the smaller and larger lists but simply moving Nodes out of
 * the input list and into the two other lists.
 * 
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @pre: smaller and larger may containing garbage (do NOT have
 *       to be NULL)
 *
 * @param[inout] head
 *   Reference to the head pointer to the input list.
 *   Should be set to NULL upon return
 * @param[out] smaller
 *   Reference to a head pointer for the list of nodes with values
 *   less than or equal to the pivot
 * @param[out] larger
 *   Reference to a head pointer for the list of nodes with values
 *   greater than the pivot
 * @param[in] pivot
 *   Pivot value
 *
 */

void print_list(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (head == nullptr) {
        // Base case: empty list
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    // Store the current node and move head to the next node before recursion
    Node* curr = head;
    head = head->next;

    // Recursive call first (head recursion)
    llpivot(head, smaller, larger, pivot);

    // Process the current node after recursion
    if (curr->val <= pivot) {
        curr->next = smaller;
        smaller = curr;
    } else {
        curr->next = larger;
        larger = curr;
    }
}

