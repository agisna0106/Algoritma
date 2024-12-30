#include <iostream>
#include <cstdlib>  // For malloc and free

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Find set of an element i (uses path compression technique)
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// A function that does union of two sets of x and y (uses union by rank)
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights
void sortEdges(Edge edges[], int E) {
    for (int i = 0; i < E - 1; ++i) {
        for (int j = 0; j < E - i - 1; ++j) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Kruskal's algorithm to find MST
void KruskalMST(Edge edges[], int V, int E) {
    Edge *result = (Edge *)malloc((V - 1) * sizeof(Edge)); // Store the resultant MST
    int e = 0; // Initial count of edges in MST
    int i = 0; // Initial count of sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    sortEdges(edges, E);

    // Allocate memory for creating V subsets
    Subset *subsets = (Subset *)malloc(V * sizeof(Subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < E) {
        // Step 2: Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far.
        Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.u);
        int y = find(subsets, next_edge.v);

        // If including this edge does not cause a cycle, include it in the result
        // and increment the index of the result for the next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the contents of the resultant MST
    cout << "Node 1 dengan berat 5\n";
    cout << "Node 2 dengan berat 7\n";
    cout << "Node 3 dengan berat 9\n";
    cout << "Langkah\tSisi\tBobot\tIlustrasi\n";
    int step = 1;
    for (int j = 0; j < e; ++j) {
        cout << step << "\t(" << result[j].u << " - " << result[j].v << ")\t" << result[j].weight << "\t";
        // Illustration
        for (int k = 0; k < step; ++k) {
            cout << "|";
        }
        cout << "(" << result[j].weight << ")\n";
        step++;
    }

    // Free allocated memory
    free(result);
    free(subsets);
}

int main() {
    int V = 5; // Number of vertices in the graph
    int E = 4; // Number of edges in the graph
    Edge edges[] = {
        {0, 1, 2},
        {1, 2, 3},
        {0, 3, 6},
        {1, 4, 5}
    };

    KruskalMST(edges, V, E);

    return 0;
}

