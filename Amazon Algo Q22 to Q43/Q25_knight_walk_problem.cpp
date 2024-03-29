// Question 25: Knight walk problem - Given a square chessboard of N x N size, the position of Knight and position of a target is given.
// We need to find out the minimum steps a Knight will take to reach the target position.

// Approach: Using BFS
This problem can be seen as shortest path in unweighted graph. Therefore we use BFS to solve this problem. 
We try all 8 possible positions where a Knight can reach from its position. 
If reachable position is not already visited and is inside the board, we push this state into queue with distance 1 more than its parent state. 
Finally we return distance of target position, when it gets pop out from queue.

T.C: O(N^2), At worst case, all the cells will be visited.
S.C: O(N^2), The nodes are stored in queue.

#include <bits/stdc++.h>
using namespace std;
 
// structure for storing a cell's data
struct cell {
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis)
        : x(x), y(y), dis(dis)
    {
    }
};
 
// Utility method returns true if (x, y) lies
// inside Board
bool isInside(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}
 
// Method returns minimum step
// to reach target position
int minStepToReachTarget(
    int knightPos[], int targetPos[],
    int N)
{
    // x and y direction, where a knight can move
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
 
    // queue for storing states of knight in board
    queue<cell> q;
 
    // push starting position of knight with 0 distance
    q.push(cell(knightPos[0], knightPos[1], 0));
 
    cell t;
    int x, y;
    bool visit[N + 1][N + 1];
 
    // make all cell unvisited
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            visit[i][j] = false;
 
    // visit starting state
    visit[knightPos[0]][knightPos[1]] = true;
 
    // loop until we have one element in queue
    while (!q.empty()) {
        t = q.front();
        q.pop();
 
        // if current cell is equal to target cell,
        // return its distance
        if (t.x == targetPos[0] && t.y == targetPos[1])
            return t.dis;
 
        // loop for all reachable states
        for (int i = 0; i < 8; i++) {
            x = t.x + dx[i];
            y = t.y + dy[i];
 
            // If reachable state is not yet visited and
            // inside board, push that state into queue
            if (isInside(x, y, N) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
            }
        }
    }
}
 
// Driver code to test above methods
int main()
{
    int N = 30;
    int knightPos[] = { 1, 1 };
    int targetPos[] = { 30, 30 };
    cout << minStepToReachTarget(knightPos, targetPos, N);
    return 0;
}