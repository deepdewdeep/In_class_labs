#include <iostream>
#include <climits>
#include <vector>
#include <iomanip>
using namespace std;

#define V 6  // Number of vertices in the graph

// Function to find the vertex with the minimum distance value
int minDistance(const vector<int>& dist, const vector<bool>& sptSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the shortest path from the source to the destination vertex
void printPath(const vector<int>& parent, int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    cout << "-> " << j;
}

// Function to print the final solution, including the shortest distances and paths from the source to all other vertices
void printSolution(const vector<int>& dist, const vector<int>& parent, int source) {
    int sum = 0;
    cout << "City\t\t\tTime\t\tPath\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t\t\t" << dist[i] << "\t\t\t" << source;
        printPath(parent, i);
        cout << endl;

        if (i != source) {
            sum += dist[i];
        }
    }

    // Calculate and display the average time from the source city to other cities
    double average = static_cast<double>(sum) / (V - 1);
    cout << fixed << setprecision(2);
    cout << "Average Time from Source city to Other Cities: " << average << "\n" << endl;
}

// Dijkstra's algorithm to find the shortest paths from a given source vertex to all other vertices
void dijkstra(const vector<vector<int>>& graph, int source) {
    vector<int> dist(V, INT_MAX);   // Array to store the shortest distances from the source vertex
    vector<bool> sptSet(V, false);  // Array to track the vertices included in the shortest path tree
    vector<int> parent(V, -1);      // Array to store the parent nodes of the shortest path

    dist[source] = 0;  // Distance from the source to itself is always 0

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);  // Find the vertex with the minimum distance value
        sptSet[u] = true;                   // Mark the selected vertex as processed

        // Update dist[v] if there is a shorter path from the source to v through u
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];  // Update the distance
                parent[v] = u;                    // Update the parent for the shortest path
            }
        }
    }

    printSolution(dist, parent, source);  // Print the final solution
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };
    
    // Iterate over each vertex as the source and find the shortest paths
    for (int source = 0; source < V; source++) {
        cout << "Source City is " << source << "" << endl;
        dijkstra(graph, source);
    }

    return 0;
}
