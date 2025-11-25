/*
Depth First Search (DFS) algorithm traverses a graph in a depth-ward motion and uses a stack to remember to get the next vertex to
start a search when a deadend occurs in any iteration.
DFS uses LIFO (Last In First Out) principle while using Stack to find the shortest path.
DFS is also called Edge Based Traversal because it explores the nodes along the edge or path.
DFS is faster and requires less memory. DFS is best suited for decision trees.
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next, graph, visited);
        }
    }
}

int main() {

    int nodes, edges;
    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> graph(nodes);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    vector<bool> visited(nodes, false);

    cout << "DFS Traversal: ";
    dfs(start, graph, visited);

    return 0;
}
