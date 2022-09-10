// Question 41: Given a singly linked list, write a function to swap elements pairwise. 

// Source: https://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list/

// Approach 1: Iterative 
Start from the head node and traverse the list. While traversing swap data of each node with its next node’s data. 
T.C: O(n), As we traverse the linked list only once.
S.C: O(1), As constant extra space is used.

#include <bits/stdc++.h>
using namespace std;
  
/* A linked list node */
class Node {
public:
    int data;
    Node* next;
};
  
/* Function to pairwise swap elements
of a linked list */
void pairWiseSwap(Node* head)
{
    Node* temp = head;
  
    /* Traverse further only if 
    there are at-least two nodes left */
    while (temp != NULL && temp->next != NULL) {
        /* Swap data of node with 
           its next node's data */
        swap(temp->data,
             temp->next->data);
  
        /* Move temp by 2 for the next pair */
        temp = temp->next->next;
    }
}
  
/* Function to add a node at the 
   beginning of Linked List */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
  
    /* put in the data */
    new_node->data = new_data;
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);
  
    /* move the head to point 
       to the new node */
    (*head_ref) = new_node;
}
  
/* Function to print nodes
   in a given linked list */
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
  
// Driver Code
int main()
{
    Node* start = NULL;
  
    /* The constructed linked list is: 
    1->2->3->4->5 */
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
  
    cout << "Linked list "
         << "before calling pairWiseSwap()\n";
    printList(start);
  
    pairWiseSwap(start);
  
    cout << "\nLinked list "
         << "after calling pairWiseSwap()\n";
    printList(start);
  
    return 0;
}

// Approach 2: Recursive 
If there are 2 or more than 2 nodes in Linked List then swap the first two nodes and recursively call for the rest of the list.
T.C: O(n), As we traverse the linked list only once.
S.C: O(1), As it is a tail recursive function, function call stack would not be build and thus no extra space will be used.

void pairWiseSwap(node* head)
{
    /* There must be at-least two nodes in the list */
    if (head != NULL && head->next != NULL) {
  
        /* Swap the node's data with data of next node */
        swap(head->data, head->next->data);
  
        /* Call pairWiseSwap() for rest of the list */
        pairWiseSwap(head->next->next);
    }
}