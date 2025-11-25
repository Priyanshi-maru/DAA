/*
Breadth First Search (BFS) algorithm traverses a graph in a breadth-ward motion and uses a queue to remember to get the
next vertex to start a search when a dead end occurs in any iteration.
BFS is basically a nodebased algorithm which is used to find the shortest path in the graph between two nodes.
BFS moves through all of its nodes which are connected to the individual nodes.
BFS uses the FIFO (First In First Out) principle while using the Queue to find the shortest path.
 However, BFS is slower and requires a large memory space.
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {

    int nodes, edges;
    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter number of edges: ";
    cin >> edges;

    // Graph using adjacency list
    vector<vector<int>> graph(nodes);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);   // directed graph
        graph[v].push_back(u);   // remove this for directed only
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    vector<bool> visited(nodes, false);
    queue<int> q;

    // Start BFS
    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        // Visit all neighbors
        for (int next : graph[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return 0;
}
