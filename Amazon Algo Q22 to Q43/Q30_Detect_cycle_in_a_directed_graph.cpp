// Question 30: Given a directed graph, check whether the graph contains a cycle or not. 
// Your function should return true if the given graph contains at least one cycle, else return false.

// Soruce: https://www.geeksforgeeks.org/detect-cycle-in-a-graph/#:~:text=To%20detect%20cycle%2C%20check%20for,a%20cycle%20in%20the%20tree.

// Approach: Using DFS
Depth First Traversal can be used to detect a cycle in a Graph. DFS for a connected graph produces a tree. There is a cycle in a graph only 
if there is a back edge present in the graph. A back edge is an edge that is from a node to itself (self-loop) or one of its ancestors in 
the tree produced by DFS. In the following graph, there are 3 back edges, marked with a cross sign. We can observe that these 3 back edges 
indicate 3 cycles present in the graph.

For a disconnected graph, Get the DFS forest as output. To detect cycle, check for a cycle in individual trees by checking back edges.
To detect a back edge, keep track of vertices currently in the recursion stack of function for DFS traversal. If a vertex is reached that is 
already in the recursion stack, then there is a cycle in the tree. The edge that connects the current vertex to the vertex in the recursion 
stack is a back edge. Use recStack[] array to keep track of vertices in the recursion stack.
T.C: O(V+E), Time Complexity of this method is same as time complexity of DFS traversal which is O(V+E).
S.C: O(V), To store the visited and recursion stack O(V) space is needed.

#include<bits/stdc++.h>
  
using namespace std;
  
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic();    // returns true if there is a cycle in this graph
};
  
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
  
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
  
// This function is a variation of DFSUtil() in 
// https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
  
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
  
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}
  
// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in 
// https://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
  
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if ( !visited[i] && isCyclicUtil(i, visited, recStack))
            return true;
  
    return false;
}
  
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
  
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}