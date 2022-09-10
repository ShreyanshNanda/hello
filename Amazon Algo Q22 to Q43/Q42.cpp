// Question 42: Given a binary tree and a node, print all cousins of given node

// Source: https://www.geeksforgeeks.org/print-cousins-of-a-given-node-in-binary-tree/

// Approach 1: Single Traversal
The idea is to go for level order traversal of the tree, as the cousins and siblings of a node can be found in its level order traversal. 
Run the traversal till the level containing the node is not found, and if found, print the given level.
T.C: O(n), This is a single level order traversal.
S.C: O(n) 

#include <iostream>
#include <queue>
using namespace std;
 
// A Binary Tree Node
struct Node {
    int data;
    Node *left, *right;
};
 
// A utility function to create a new Binary
// Tree Node
Node* newNode(int item)
{
    Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// function to print cousins of the node
void printCousins(Node* root, Node* node_to_find)
{
    // if the given node is the root itself,
    // then no nodes would be printed
    if (root == node_to_find) {
        cout << "Cousin Nodes : None" << endl;
        return;
    }
 
    queue<Node*> q;
    bool found = false;
    int size_;
    Node* p;
    q.push(root);
 
    // the following loop runs until found is
    // not true, or q is not empty.
    // if found has become true => we have found
    // the level in which the node is present
    // and the present queue will contain all the
    // cousins of that node
    while (!q.empty() && !found) {
 
        size_ = q.size();
        while (size_) {
            p = q.front();
            q.pop();
 
            // if current node's left or right child
            // is the same as the node to find,
            // then make found = true, and don't push
            // any of them into the queue, as
            // we don't have to print the siblings
            if ((p->left == node_to_find ||
                p->right == node_to_find)) {
                found = true;
            }
            else {
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
 
            size_--;
        }
    }
 
    // if found == true then the queue will contain the
    // cousins of the given node
    if (found) {
        cout << "Cousin Nodes : ";
        size_ = q.size();
 
        // size_ will be 0 when the node was at the
        // level just below the root node.
        if (size_ == 0)
            cout << "None";
        for (int i = 0; i < size_; i++) {
            p = q.front();
            q.pop();
            cout << p->data << " ";
        }
    }
    else {
        cout << "Node not found";
    }
    cout << endl;
    return;
}
 
// Driver Program to test above function
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(15);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
 
    Node* x = newNode(43);
 
    printCousins(root, x);
    printCousins(root, root);
    printCousins(root, root->right);
    printCousins(root, root->left);
    printCousins(root, root->left->right);
 
    return 0;
}

// Approach 2: two traversals recursively.
The idea is to go for level order traversal of the tree, as the cousins and siblings of a node can be found in its level order traversal. 
Once we have found level, we can print all nodes at a given level. The only thing to take care of is, sibling should not be printed. 
To handle this, we change the printing function to first check for sibling and print node only if it is not sibling.
T.C: O(n)
S.C: O(n)

#include <bits/stdc++.h>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    int data;
    Node *left, *right;
};
 
// A utility function to create a new
// Binary Tree Node
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
/* It returns level of the node if it is
present in tree, otherwise returns 0.*/
int getLevel(Node *root, Node *node, int level)
{
     
    // base cases
    if (root == NULL)
        return 0;
    if (root == node)
        return level;
 
    // If node is present in left subtree
    int downlevel = getLevel(root->left,
                             node, level + 1);
    if (downlevel != 0)
        return downlevel;
 
    // If node is not present in left subtree
    return getLevel(root->right, node, level + 1);
}
 
/* Print nodes at a given level such that
sibling of node is not printed if it exists */
void printGivenLevel(Node* root, Node *node, int level)
{
    // Base cases
    if (root == NULL || level < 2)
        return;
 
    // If current node is parent of a node
    // with given level
    if (level == 2)
    {
        if (root->left == node || root->right == node)
            return;
        if (root->left)
            cout << root->left->data << " ";
        if (root->right)
            cout << root->right->data;
    }
 
    // Recur for left and right subtrees
    else if (level > 2)
    {
        printGivenLevel(root->left, node, level - 1);
        printGivenLevel(root->right, node, level - 1);
    }
}
 
// This function prints cousins of a given node
void printCousins(Node *root, Node *node)
{
    // Get level of given node
    int level = getLevel(root, node, 1);
 
    // Print nodes of given level.
    printGivenLevel(root, node, level);
}
 
// Driver Code
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(15);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
 
    printCousins(root, root->left->right);
 
    return 0;
}