#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    vector<Edge> edges;
};

// Function to create a graph
Graph createGraph(int V, int E) {
    Graph graph;
    graph.V = V;
    graph.E = E;
    return graph;
}

// Find function of disjoint sets
int find(vector<int>& parent, int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

// Union function of disjoint sets
void Union(vector<int>& parent, vector<int>& rank, int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

// Comparison function for sorting edges by weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void kruskalMST(Graph graph) {
    int V = graph.V;
    vector<Edge> result;

    // Sort all the edges in non-decreasing order of their weight
    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    // Create V subsets with single elements
    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int e = 0;  // Index variable used for result[]
    int i = 0;  // Index variable used for sorted edges

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph.E) {
        Edge nextEdge = graph.edges[i++];

        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dest);

        // If including this edge doesn't cause a cycle, add it to the result
        if (x != y) {
            result.push_back(nextEdge);
            Union(parent, rank, x, y);
            e++;
        }
    }

    // Print the edges of the minimum spanning tree
    cout << "Minimum Spanning Tree edges:\n";
    for (i = 0; i < result.size(); i++)
        cout << result[i].src << " -- " << result[i].dest << "  Weight: " << result[i].weight << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;
    cout << "Enter the number of edges in the graph: ";
    cin >> E;

    Graph graph = createGraph(V, E);

    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cout << "Enter edge " << i + 1 << " source, destination, and weight: ";
        cin >> src >> dest >> weight;

        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;

        graph.edges;
    }
}