#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
    int vert;
    unordered_map<int, list<int>> aL; // Adjacency list to store the graph

    Graph() : vert(0) {} // Constructor to initialize the number of vertices

    void addEdge(int a, int b, int dir = 0) {
        vert++; // Increment the number of vertices
        aL[a].push_back(b); // Add b to the adjacency list of a

        if (dir == 0) {
            aL[b].push_back(a); // If the direction is bidirectional, add a to the adjacency list of b as well
        }
    }

    void print() {
        for (auto i : aL) {
            cout << i.first << "->"; // Print the current vertex
            for (auto j : i.second) {
                cout << j << ","; // Print the vertices connected to the current vertex
            }
            cout << endl;
        }
    }

    vector<int> BFS() {
        unordered_map<int, bool> visited; // Map to keep track of visited vertices
        queue<int> q; // Queue to store the vertices to be visited
        vector<int> ans; // Vector to store the order of visited vertices

        for (auto& i : aL) {
            int node = i.first; // Get the current vertex
            if (!visited[node]) { // If the current vertex is not visited
                q.push(node); // Add it to the queue
                visited[node] = true; // Mark it as visited
                while (!q.empty()) {
                    int frontnode = q.front(); // Get the front vertex from the queue
                    q.pop(); // Remove it from the queue
                    ans.push_back(frontnode); // Add it to the answer vector
                    for (auto neighbor : aL[frontnode]) {
                        if (!visited[neighbor]) { // If the neighbor is not visited
                            q.push(neighbor); // Add it to the queue
                            visited[neighbor] = true; // Mark it as visited
                        }
                    }
                }
            }
        }

        return ans; // Return the vector containing the BFS order
    }
};

int main() {
    Graph g1; // Create a Graph object
    g1.addEdge(1, 2); // Add edges to the graph
    g1.addEdge(2, 3);
    g1.addEdge(1, 4);
    g1.addEdge(4, 5);
    g1.addEdge(1, 5);
    g1.addEdge(2, 4);
    g1.print(); // Print the graph

    vector<int> bfsOrder = g1.BFS(); // Perform BFS and store the result in a vector
    for (int i : bfsOrder) {
        cout << i << " "; // Print each vertex in the BFS order
    }
    cout << endl;

    return 0;
}
