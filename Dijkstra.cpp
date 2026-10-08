#include <iostream>
#include <climits>
using namespace std;

const int MAXV = 100;

struct Edge {
    int v, w;
};

class Graph {
    int V = 0;
    Edge adj[MAXV][MAXV];
    int deg[MAXV];
    void printPath(const int parent[], int v) {
        if (parent[v] == -1) {
            cout << v;
            return;
        }
        printPath(parent, parent[v]);
        cout << " -> " << v;
    }
public:
    void create() {
        int e;
        cout << "Enter number of vertices: ";
        cin >> V;
        if (V <= 0 || V > MAXV) {
            V = 0;
            cout << "Invalid number of vertices.\n";
            return;
        }
        for (int i = 0; i < V; i++) deg[i] = 0;
        cout << "Enter number of edges: ";
        cin >> e;
        cout << "Enter directed edges (u v w):\n";
        for (int i = 0; i < e; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if (u < 0 || v < 0 || u >= V || v >= V) {
                cout << "Invalid edge ignored.\n";
                continue;
            }
            if (w < 0) {
                cout << "Negative weight ignored (use Bellman-Ford).\n";
                continue;
            }
            if (deg[u] == MAXV) {
                cout << "Too many edges at a vertex; edge ignored.\n";
                continue;
            }
            adj[u][deg[u]].v = v;
            adj[u][deg[u]].w = w;
            deg[u]++;
        }
        cout << "Graph created.\n";
    }
    void display() const {
        if (V == 0) {
            cout << "Create the graph first.\n";
            return;
        }
        cout << "Edges (u v w):\n";
        for (int u = 0; u < V; u++)
            for (int j = 0; j < deg[u]; j++)
                cout << u << " " << adj[u][j].v << " " << adj[u][j].w << "\n";
    }
    void dijkstra(int src) {
        if (V == 0) {
            cout << "Create the graph first.\n";
            return;
        }
        if (src < 0 || src >= V) {
            cout << "Invalid source vertex.\n";
            return;
        }
        int dist[MAXV], parent[MAXV];
        bool done[MAXV];
        for (int i = 0; i < V; i++) {
            dist[i] = INT_MAX;
            parent[i] = -1;
            done[i] = false;
        }
        dist[src] = 0;
        for (int count = 0; count < V; count++) {
            int u = -1;
            for (int i = 0; i < V; i++)
                if (!done[i] && dist[i] != INT_MAX && (u == -1 || dist[i] < dist[u]))
                    u = i;
            if (u == -1) break;
            done[u] = true;
            for (int j = 0; j < deg[u]; j++) {
                int v = adj[u][j].v, w = adj[u][j].w;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                }
            }
        }
        cout << "Shortest distances from vertex " << src << ":\n";
        for (int v = 0; v < V; v++) {
            cout << v << " : ";
            if (dist[v] == INT_MAX) {
                cout << "INF (unreachable)\n";
                continue;
            }
            cout << dist[v] << " path: ";
            printPath(parent, v);
            cout << "\n";
        }
    }
};

int main() {
    Graph g;
    int choice, src;
    while (true) {
        cout << "\nMenu:\n1. Create graph\n2. Display edges\n";
        cout << "3. Dijkstra's shortest path\n4. Quit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) break;
        switch (choice) {
        case 1:
            g.create();
            break;
        case 2:
            g.display();
            break;
        case 3:
            cout << "Enter source vertex: ";
            cin >> src;
            g.dijkstra(src);
            break;
        case 4:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
