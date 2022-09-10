// Question 43: Write a function to print ZigZag order traversal of a binary tree. 

// Source: https://www.geeksforgeeks.org/zigzag-tree-traversal/

// Approach 1: using two stacks
T.C: O(n)
S.C: O(n)+O(n)=O(n)

#include <iostream>
#include <stack>
using namespace std;
 
// Binary Tree node
struct Node {
    int data;
    struct Node *left, *right;
};
 
// function to print the zigzag traversal
void zizagtraversal(struct Node* root)
{
    // if null then return
    if (!root)
        return;
 
    // declare two stacks
    stack<struct Node*> currentlevel;
    stack<struct Node*> nextlevel;
 
    // push the root
    currentlevel.push(root);
 
    // check if stack is empty  
    bool lefttoright = true;
    while (!currentlevel.empty()) {
 
        // pop out of stack
        struct Node* temp = currentlevel.top();
        currentlevel.pop();
 
        // if not null
        if (temp) {
 
            // print the data in it
            cout << temp->data << " ";
 
            // store data according to current
            // order.
            if (lefttoright) {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
            else {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }
 
        if (currentlevel.empty()) {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }
}
 
// A utility function to create a new node
struct Node* newNode(int data)
{
    struct Node* node = new struct Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
// driver program to test the above function
int main()
{
    // create tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout << "ZigZag Order traversal of binary tree is \n";
 
    zizagtraversal(root);
 
    return 0;
}

// Approach 2: Recursive Approach
The approach used here is the observable similarity to the level order traversal.
Here we need to include an extra parameter to keep a track of printing each level in left-right or right-left way.
T.C: O(n)
S.C: O(n)

#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    Node *left;
    Node *right;
 
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
 
// Function to Build Tree
Node* buildTree(string str)
{  
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
     
    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;
     
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
         
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
         
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
         
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
             
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
             
        // Get the current node's value from the string
        string currVal = ip[i];
             
        // If the left child is not null
        if(currVal != "N") {
                 
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                 
            // Push it to the queue
            queue.push(currNode->left);
        }
             
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
             
        // If the right child is not null
        if(currVal != "N") {
                 
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                 
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
     
    return root;
}
 
// Function to calculate height of tree
int treeHeight(Node *root){
    if(!root) return 0;
    int lHeight = treeHeight(root->left);
    int rHeight = treeHeight(root->right);
    return max(lHeight, rHeight) + 1;
}
 
// Helper Function to store the zig zag order traversal
// of tree in a list recursively
void zigZagTraversalRecursion(Node* root, int height, bool lor, vector<int> &ans){
    // Height = 1 means the tree now has only one node
    if(height <= 1){
        if(root) ans.push_back(root->data);
    }
    // When Height > 1
    else{
        if(lor){
            if(root->left) zigZagTraversalRecursion(root->left, height - 1, lor, ans);
            if(root->right) zigZagTraversalRecursion(root->right, height - 1, lor, ans);
        }
        else{
            if(root->right) zigZagTraversalRecursion(root->right, height - 1, lor, ans);
            if(root->left) zigZagTraversalRecursion(root->left, height - 1, lor, ans);
        }
    }
}
 
// Function to traverse tree in zig zag order
vector <int> zigZagTraversal(Node* root)
{
    vector<int> ans;
    bool leftOrRight = true;
    int height = treeHeight(root);
    for(int i = 1; i <= height; i++){
        zigZagTraversalRecursion(root, i, leftOrRight, ans);
        leftOrRight = !leftOrRight;
    }
    return ans;
}
 
 
int main()
{   
      // Tree:
    //          1
    //        /   \
    //       /     \
    //      /       \
    //     2          3
    //   /   \       /  \
    //  4     5     6     7
    // / \   /  \  / \   /  \
    //8  9  10 11 12 13 14  15
   
    string s = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15";
    Node* root = buildTree(s);
    vector <int> res = zigZagTraversal(root);
      cout<<"ZigZag traversal of binary tree is:"<<endl;
    for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
    cout<<endl;
  return 0;
}

// Approach 3: use a deque 
Push and pop in different ways depending on if the level is odd or level is even.
T.C: O(N)
S.C: O(N) for deque data structure

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
// Binary Tree node
class Node {
public:
    int data;
    Node *left, *right;
};
 
// Function to print the zigzag traversal
vector<int> zigZagTraversal(Node* root)
{
    deque<Node*> q;
    vector<int> v;
    q.push_back(root);
    v.push_back(root->data);
    Node* temp;
   
    // set initial level as 1, because root is
    // already been taken care of.
    int l = 1;
                
    while (!q.empty()) {
        int n = q.size();
 
        for (int i = 0; i < n; i++) {
 
            // popping mechanism
            if (l % 2 == 0) {
                temp = q.back();
                q.pop_back();
            }
            else {
                temp = q.front();
                q.pop_front();
            }
 
            // pushing mechanism
            if (l % 2 != 0) {
 
                if (temp->right) {
                    q.push_back(temp->right);
                    v.push_back(temp->right->data);
                }
                if (temp->left) {
                    q.push_back(temp->left);
                    v.push_back(temp->left->data);
                }
            }
            else if (l % 2 == 0) {
 
                if (temp->left) {
                    q.push_front(temp->left);
                    v.push_back(temp->left->data);
                }
                if (temp->right) {
                    q.push_front(temp->right);
                    v.push_back(temp->right->data);
                }
            }
        }
        l++; // level plus one
    }
    return v;
}
 
// A utility function to create a new node
struct Node* newNode(int data)
{
    struct Node* node = new struct Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
// Driver program to test
// the above function
int main()
{
   
    // vector to store the traversal order.
    vector<int> v;
   
    // create tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout << "ZigZag Order traversal of binary tree is \n";
 
    v = zigZagTraversal(root);
 
    for (int i = 0; i < v.size();
         i++) { // to print the order
        cout << v[i] << " ";
    }
 
    return 0;
}

// Approach 4: use a queue 
just like we used in Level Order Traversal. But in this case, we can also maintain a flag variable which keeps track of alternate level 
to reverse the order of the corresponding level traversal.flag==true implies we have to insert from left to right and flag==false means 
we have to insert element from right to left our answer arraylist.
T.C: O(N)
S.C: O(N) for Queue data structure

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
// Binary Tree node
class Node {
public:
    int data;
    Node *left, *right;
};
 
// Function to print the zigzag traversal
vector<int> zigZagTraversal(Node* root) {
    if(root == NULL){return {  } ; }
 
    vector<int > ans ;
    queue<Node*> q ;
    q.push(root) ;
    bool flag = false ;
 
    while(!q.empty()){
        int size = q.size() ;
        vector<int> level ;
        for(int i=0 ; i < size ; i++){
            Node* node = q.front() ;
            q.pop() ;
            level.push_back(node->data) ;
 
            if(node->left != NULL) {q.push(node->left) ;}
            if(node->right != NULL) {q.push(node->right) ;}   
 
        }
        flag = !flag ;  
        if(flag == false){
            reverse(level.begin() , level.end()) ;           
        }
        for(int i = 0 ; i < level.size() ; i++){
          ans.push_back(level[i]) ;
        }
         
    }
    return ans ;
}
 
// A utility function to create a new node
struct Node* newNode(int data)
{
    struct Node* node = new struct Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
// Driver program to test
// the above function
int main()
{
   
    // vector to store the traversal order.
    vector<int> v;
   
    // create tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout << "ZigZag Order traversal of binary tree is \n";
 
    v = zigZagTraversal(root);
 
    for (int i = 0; i < v.size();
         i++) { // to print the order
        cout << v[i] << " ";
    }
 
    return 0;
}