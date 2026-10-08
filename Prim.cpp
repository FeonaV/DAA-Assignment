#include <iostream>
#include <climits>
using namespace std;

const int MAXV = 100;

class Graph {
    int V = 0;
    int adj[MAXV][MAXV];
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
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++) adj[i][j] = 0;
        cout << "Enter number of edges: ";
        cin >> e;
        cout << "Enter edges (u v w):\n";
        for (int i = 0; i < e; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if (u < 0 || v < 0 || u >= V || v >= V || w <= 0) {
                cout << "Invalid edge ignored.\n";
                continue;
            }
            adj[u][v] = adj[v][u] = w;
        }
        cout << "Graph created.\n";
    }
    void display() const {
        if (V == 0) {
            cout << "Create the graph first.\n";
            return;
        }
        cout << "Edges (u v w):\n";
        for (int i = 0; i < V; i++)
            for (int j = i + 1; j < V; j++)
                if (adj[i][j]) cout << i << " " << j << " " << adj[i][j] << "\n";
    }
    void prim() {
        if (V == 0) {
            cout << "Create the graph first.\n";
            return;
        }
        int key[MAXV], parent[MAXV];
        bool inMST[MAXV];
        for (int i = 0; i < V; i++) {
            key[i] = INT_MAX;
            parent[i] = -1;
            inMST[i] = false;
        }
        key[0] = 0;
        int total = 0;
        for (int count = 0; count < V; count++) {
            int u = -1;
            for (int i = 0; i < V; i++)
                if (!inMST[i] && (u == -1 || key[i] < key[u])) u = i;
            if (key[u] == INT_MAX) {
                cout << "Graph is disconnected; MST not possible.\n";
                return;
            }
            inMST[u] = true;
            total += key[u];
            for (int v = 0; v < V; v++)
                if (adj[u][v] && !inMST[v] && adj[u][v] < key[v]) {
                    key[v] = adj[u][v];
                    parent[v] = u;
                }
        }
        cout << "Edges in the MST (Prim):\n";
        for (int v = 1; v < V; v++)
            cout << parent[v] << " - " << v << " : " << adj[parent[v]][v] << "\n";
        cout << "Total weight of MST: " << total << "\n";
    }
};

int main() {
    Graph g;
    int choice;
    while (true) {
        cout << "\nMenu:\n1. Create graph\n2. Display edges\n";
        cout << "3. Prim's MST\n4. Quit\n";
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
            g.prim();
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
