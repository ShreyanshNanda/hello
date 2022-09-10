// Question 28: Handshake problem- There are N persons in a room. Find the maximum number of Handshakes possible. 
// Given the fact that any two persons shake hand exactly once.

Source: https://www.geeksforgeeks.org/find-maximum-number-handshakes/#:~:text=To%20maximize%20the%20number%20of,2%20handshakes%20and%20so%20on.

// Approach1: Recursive 
T.C: O(N)
S.C: O(1)

#include <bits/stdc++.h>
using namespace std;
 
// Function to find all possible handshakes
int handshake(int n)
{
 
    // When n becomes 0 that means all the persons have done
    // handshake with other
    if (n == 0)
        return 0;
    else
        return (n - 1) + handshake(n - 1);
}

// Driver code
int main()
{
    int n = 9;
    cout << " " << handshake(n);
    return 0;
}

// Aprroach 2: Iterative
T.C: O(1)
S.C: O(1)

#include <bits/stdc++.h>
using namespace std;
 
// function to find all possible handshakes
int handshake(int n) { return n * (n - 1) / 2; }
 
int main()
{
    int n = 9;
    cout << handshake(n) << endl;
    return 0;
}