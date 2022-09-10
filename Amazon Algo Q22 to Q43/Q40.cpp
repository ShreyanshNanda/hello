// Question 40: Given a array of n positive elements we need to find the lowest possible sum of max and min elements in a subarray given that size of subarray should be greater than equal to 2.

// Source: https://www.geeksforgeeks.org/minimum-value-max-min-subarray/

// Approach: 
A simple solution is to generate all subarrays, compute sum of maximum and minimum and finally return lowest sum.
T.C: O(n) 
S.C: O(1) 

#include <bits/stdc++.h>
using namespace std;
 
int maxSum(int arr[], int n)
{
    if (n < 2)
        return -1;
    int ans = arr[0] + arr[1];
    for (int i = 1; i + 1 < n; i++)
        ans = min(ans, (arr[i] + arr[i + 1]));
    return ans;
}
 
// Driver code
int main()
{
    int arr[] = {1, 12, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n);
    return 0;
}