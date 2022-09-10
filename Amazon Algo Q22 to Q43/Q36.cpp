// Question 36: Given a Linked List and a number N, write a function that returns the value at the Nth node from the end of the Linked List.

// Source: https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/

// Approach 1: Naive Approach
1. Calculate the length of the Linked List. Let the length be len. 
2. Print the (len – n + 1)th node from the beginning of the Linked List. 
T.C: O(M) where M is the size of the linked list
S.C: O(1)

#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node {
    int data;
    struct Node* next;
};
 
/* Function to get the Nth node from
   the last of a linked list*/
void printNthFromLast(struct Node* head, int N)
{
    int len = 0, i;
    struct Node* temp = head;
 
    // Count the number of nodes in Linked List
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
 
    // Check if value of N is not
    // more than length of the linked list
    if (len < N)
        return;
 
    temp = head;
 
    // Get the (len-N+1)th node from the beginning
    for (i = 1; i < len - N + 1; i++)
        temp = temp->next;
 
    cout << temp->data;
 
    return;
}
 
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
// Driver's Code
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    // create linked 35->15->4->20
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);
     
      // Function call
    printNthFromLast(head, 4);
    return 0;
}

// Approach 2: Recursive
T.C: O(M) where M is the length of the linked list. 
S.C: O(M) for call stack

void printNthFromLast(struct Node* head, int N)
{
    static int i = 0;
    if (head == NULL)
        return;
    printNthFromLast(head->next, N);
    if (++i == N)
        cout<<head->data;
}

// Approach 3: Using two pointers(Best Approach)
T.C: O(M) where M is the length of the linked list.
S.C: O(1)

#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int data;
    node* next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
 
struct llist {
 
    node* head;
    llist() { head = NULL; }
 
    // insert operation at the beginning of the list.
    void insertAtBegin(int val)
    {
        node* newNode = new node(val);
        newNode->next = head;
        head = newNode;
    }
 
    // finding n-th node from the end.
    void nthFromEnd(int n)
    {
        // create two pointers main_ptr and ref_ptr
        // initially pointing to head.
        node* main_ptr = head;
        node* ref_ptr = head;
 
        // if list is empty, return
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
 
        // move ref_ptr to the n-th node from beginning.
        for (int i = 1; i < n; i++) {
            ref_ptr = ref_ptr->next;
            if (ref_ptr == NULL) {
                cout << n
                     << " is greater than no. of nodes in "
                        "the list"
                     << endl;
                return;
            }
        }
 
        // move ref_ptr and main_ptr by one node until
        // ref_ptr reaches end of the list.
        while (ref_ptr != NULL && ref_ptr->next != NULL) {
            ref_ptr = ref_ptr->next;
            main_ptr = main_ptr->next;
        }
        cout << "Node no. " << n
             << " from end is: " << main_ptr->data << endl;
    }
 
    void displaylist()
    {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
 
// Driver's code
int main()
{
    llist ll;
 
    ll.insertAtBegin(20);
    ll.insertAtBegin(4);
    ll.insertAtBegin(15);
    ll.insertAtBegin(35);
 
    ll.displaylist();
 
    // Function call
    ll.nthFromEnd(4);
 
    return 0;
}

