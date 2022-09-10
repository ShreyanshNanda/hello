// Question 29: Given a binary search tree, task is to find Kth largest element in the binary search tree.

// Source 1: https://www.geeksforgeeks.org/kth-largest-element-bst-using-constant-extra-space/#:~:text=To%20find%20Kth%20largest%20element%20in%20a%20Binary%20search%20tree,traversal%20and%20print%20the%20data.
// Source 2: https://afteracademy.com/blog/kth-largest-element-in-a-bst

// Approach 1: Brute Force → Performing inorder traversal and storing the elements in an array.
A very simple solution is to perform inorder traversal and store the elements of BST in an array which will give us all elements in sorted order. 
By traversing the array in reverse order and maintaining a count, we can return the Kth largest element.
T.C: Traversing the tree for storing elements in an array + Traversing the array in reverse order = O(n) + O(n) = O(n)
S.C: O(n) (We are using an extra array of n size, where n is the number of nodes.)

// Approach 2: By using reverse inorder traversal → Reverse inorder will help to get the elements sorted in descending order.
The idea is to do reverse inorder traversal of BST which helps to explore all the nodes in decreasing order. While doing the traversal,
we keep track of count of nodes visited so far. When the count becomes equal to K, we stop the traversal and return the value stored in the node.
T.C: Traversing tree in reverse in-order = O(n)
S.C: O(h) for recursion call stack, where h is the height of the tree.

// Approach 3: By using reverse morris traversal → Morris traversal is used to traverse BST without using recursion.
Morris Traversal is just traversing the tree in inorder fashion without using recursion and stack. Since it does not use recursion or stack, 
it saves us a lot of space.We will here use reverse morris traversal to get elements in descending order and then use a count variable to get the Kth element.
T.C: O(n) (Every edge is traversed 3 times and there are n-1 edges)
S.C: O(1)


// Approach 4: By using augmented BST--> We can augment our BST in order to keep count of the right elements.
To find Kth largest element in a Binary search tree, the simplest logic is to do reverse inorder traversal and while doing reverse 
inorder traversal simply keep a count of number of Nodes visited. When the count becomes equal to k, 
we stop the traversal and print the data. It uses the fact that reverse inorder traversal will give us a list sorted in descending order. 
T.C: O(n) 
S.C: O(1) 

#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    struct Node *left, *right;
};
 
// helper function to create a new Node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
}
 
Node* KthLargestUsingMorrisTraversal(Node* root, int k)
{
    Node* curr = root;
    Node* Klargest = NULL;
 
    // count variable to keep count of visited Nodes
    int count = 0;
 
    while (curr != NULL) {
        // if right child is NULL
        if (curr->right == NULL) {
 
            // first increment count and check if count = k
            if (++count == k)
                Klargest = curr;
 
            // otherwise move to the left child
            curr = curr->left;
        }
 
        else {
 
            // find inorder successor of current Node
            Node* succ = curr->right;
 
            while (succ->left != NULL && succ->left != curr)
                succ = succ->left;
 
            if (succ->left == NULL) {
 
                // set left child of successor to the
                // current Node
                succ->left = curr;
 
                // move current to its right
                curr = curr->right;
            }
 
            // restoring the tree back to original binary
            //  search tree removing threaded links
            else {
 
                succ->left = NULL;
 
                if (++count == k)
                    Klargest = curr;
 
                // move current to its left child
                curr = curr->left;
            }
        }
    }
 
    return Klargest;
}
 
int main()
{
    // Your C++ Code
    /* Constructed binary tree is
          4
        /   \
       2     7
     /  \   /  \
    1    3  6    10 */
 
    Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(10);
 
    cout << "Finding K-th largest Node in BST : "
         << KthLargestUsingMorrisTraversal(root, 2)->data;
 
    return 0;
}