// Question 34: Given a gold mine of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. 
// Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\) that is from a given cell, 
// the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Find out maximum amount of 
// gold he can collect. 

// Source: https://www.geeksforgeeks.org/gold-mine-problem/

// Approach 1: Recursion
T.C: O(3N*M)
S.C: O(N*M)

#include<bits/stdc++.h>
using namespace std;
 
int collectGold(vector<vector<int>> gold, int x, int y, int n, int m) {
 
    // Base condition.
    if ((x < 0) || (x == n) || (y == m)) { 
        return 0;
    }
   
 
    // Right upper diagonal
    int rightUpperDiagonal = collectGold(gold, x - 1, y + 1, n, m);
 
     // right
    int right = collectGold(gold, x, y + 1, n, m);
 
    // Lower right diagonal
    int rightLowerDiagonal = collectGold(gold, x + 1, y + 1, n, m); 
 
    // Return the maximum and store the value
    return  gold[x][y] + max(max(rightUpperDiagonal, rightLowerDiagonal), right); 
}
 
int getMaxGold(vector<vector<int>> gold, int n, int m)
{
    int maxGold = 0;
 
    for (int i = 0; i < n; i++) {
 
        // Recursive function call for  ith row.
        int goldCollected = collectGold(gold, i, 0, n, m); 
        maxGold = max(maxGold, goldCollected);
    }
 
    return maxGold;
}
 
// Driver Code
int main()
{
    vector<vector<int>> gold { {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };
    int m = 4, n = 4;
    cout << getMaxGold(gold, n, m);
    return 0;
}

// Approach 2: Memoization
Bottom-Up Approach: The second way is to take an extra space of size m*n and start computing values of states 
of right, right upper diagonal, and right bottom diagonal and store it in the 2d array.
T.C: O(m*n)
S.C: O(m*n)

#include<bits/stdc++.h>
using namespace std;
 
int collectGold(vector<vector<int>> gold, int x, int y, int n, int m, vector<vector<int>> &dp) {
 
    // Base condition.
    if ((x < 0) || (x == n) || (y == m)) { 
        return 0;
    }
   
    if(dp[x][y] != -1){
        return dp[x][y] ;
    }
 
    // Right upper diagonal
    int rightUpperDiagonal = collectGold(gold, x - 1, y + 1, n, m, dp);
 
     // right
    int right = collectGold(gold, x, y + 1, n, m, dp);
 
    // Lower right diagonal
    int rightLowerDiagonal = collectGold(gold, x + 1, y + 1, n, m, dp); 
 
    // Return the maximum and store the value
    return dp[x][y] = gold[x][y] + max(max(rightUpperDiagonal, rightLowerDiagonal), right); 
}
 
int getMaxGold(vector<vector<int>> gold, int n, int m)
{
    int maxGold = 0;
    // Initialize the dp vector
    vector<vector<int>> dp(n, vector<int>(m, -1)) ;
    for (int i = 0; i < n; i++) {
 
        // Recursive function call for  ith row.
        int goldCollected = collectGold(gold, i, 0, n, m, dp); 
        maxGold = max(maxGold, goldCollected);
    }
 
    return maxGold;
}
 
// Driver Code
int main()
{
    vector<vector<int>> gold { {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };
    int m = 4, n = 4;
    cout << getMaxGold(gold, n, m);
    return 0;
}

// Approach 3: Using Dp, Tabulation
Create a 2-D matrix goldTable[][]) of the same as given matrix mat[][].
T.C: O(m*n)
S.C: O(m*n)

#include<bits/stdc++.h>
using namespace std;
 
const int MAX = 100;
 
// Returns maximum amount of gold that can be collected
// when journey started from first column and moves
// allowed are right, right-up and right-down
int getMaxGold(int gold[][MAX], int m, int n)
{
    // Create a table for storing intermediate results
    // and initialize all cells to 0. The first row of
    // goldMineTable gives the maximum gold that the miner
    // can collect when starts that row
    int goldTable[m][n];
    memset(goldTable, 0, sizeof(goldTable));
 
    for (int col=n-1; col>=0; col--)
    {
        for (int row=0; row<m; row++)
        {
            // Gold collected on going to the cell on the right(->)
            int right = (col==n-1)? 0: goldTable[row][col+1];
 
            // Gold collected on going to the cell to right up (/)
            int right_up = (row==0 || col==n-1)? 0:
                            goldTable[row-1][col+1];
 
            // Gold collected on going to the cell to right down (\)
            int right_down = (row==m-1 || col==n-1)? 0:
                             goldTable[row+1][col+1];
 
            // Max gold collected from taking either of the
            // above 3 paths
            goldTable[row][col] = gold[row][col] +
                              max(right, max(right_up, right_down));
                                                     
        }
    }
 
    // The max amount of gold collected will be the max
    // value in first column of all rows
    int res = goldTable[0][0];
    for (int i=1; i<m; i++)
        res = max(res, goldTable[i][0]);
    return res;
}
 
// Driver Code
int main()
{
    int gold[MAX][MAX]= { {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };
    int m = 4, n = 4;
    cout << getMaxGold(gold, m, n);
    return 0;
}