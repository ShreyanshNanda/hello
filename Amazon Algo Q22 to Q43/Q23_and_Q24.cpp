// Question 23: Given an integer array find the number of merge operation required to make it a palindrome.
// Input : arr[] = {15, 4, 15}
// Output : 0
// Array is already a palindrome. So we do not need any merge operation.

// Question 24: Input : arr[] = {1, 4, 5, 1}
// Output : 1
// We can make given array palindrome with minimum one merging (merging 4 and 5 to make 9)

// Source: https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/#:~:text=To%20make%20any%20array%20a,to%20single%2Dcharacter%20string).

Approach 1:
T.C: O(n)
S.C: O(1)
#include <bits/stdc++.h>
using namespace std;
 
// Returns minimum number of count operations
// required to make arr[] palindrome
int findMinOps(int arr[], int n)
{
    int ans = 0; // Initialize result
 
    // Start from two corners
    for (int i=0,j=n-1; i<=j;)
    {
        // If corner elements are same,
        // problem reduces arr[i+1..j-1]
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
 
        // If left element is greater, then
        // we merge right two elements
        else if (arr[i] > arr[j])
        {
            // need to merge from tail.
            j--;
            arr[j] += arr[j+1] ;
            ans++;
        }
 
        // Else we merge left two elements
        else
        {
            i++;
            arr[i] += arr[i-1];
            ans++;
        }
    }
 
    return ans;
}
 
// Driver program to test above
int main()
{
    int arr[] = {1, 4, 5, 9, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Count of minimum operations is "
         <<  findMinOps(arr, n) << endl;
    return 0;
}