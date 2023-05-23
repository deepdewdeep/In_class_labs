#include <cstring>
#include <iostream>
using namespace std;

#define INF 9999999

// number of vertices in graph
#define V 6

// create a 2d array of size 5x5
// for adjacency matrix to represent graph
int G[V][V] = {
    {0, 3, 0, 0, 0, 1},
    {3, 0, 2, 1, 10, 0},
    {0, 2, 0, 3, 0, 5},
    {0, 1, 3, 0, 5, 0},
    {0, 10, 0, 5, 0, 4},
    {1, 0, 5, 0, 4, 0}
};

int main() {
    int no_edge; // number of edges

    // create an array to track selected vertices
    // selected will become true otherwise false
    int selected[V];

    // set selected to false initially
    memset(selected, false, sizeof(selected));

    // set the number of edges to 0
    no_edge = 0;

    // the number of edges in the minimum spanning tree will always be
    // less than (V-1), where V is the number of vertices in the graph

    // choose the 0th vertex and make it true
    selected[0] = true;

    int x; // row number
    int y; // col number

    // print the edges and weights
    cout << "Edge" << "    Weight" << endl;
    while (no_edge < V - 1) {
        int min = INF;
        x = 0;
        y = 0;

        // for every vertex in the selected set, find all adjacent vertices
        // calculate the distance from the vertex selected at step 1
        // if the vertex is already in the selected set, discard it
        // otherwise, choose another vertex nearest to the selected vertex at step 1

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) { // not in selected and there is an edge
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y << "    " << G[x][y] << endl;
        selected[y] = true;
        no_edge++;
    }

    return 0;
}
