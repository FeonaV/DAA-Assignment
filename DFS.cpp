#include <iostream>
using namespace std;

const int MAXV = 100;

class Graph {
    int V = 0;
    int adj[MAXV][MAXV];
    int deg[MAXV];
    void dfsRec(int u, bool visited[]) {
        visited[u] = true;
        cout << u << " ";
        for (int j = 0; j < deg[u]; j++)
            if (!visited[adj[u][j]]) dfsRec(adj[u][j], visited);
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
        cout << "Enter edges (u v):\n";
        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            if (u < 0 || v < 0 || u >= V || v >= V) {
                cout << "Invalid edge ignored.\n";
                continue;
            }
            if (deg[u] > MAXV - 2 || deg[v] > MAXV - 2) {
                cout << "Too many edges at a vertex; edge ignored.\n";
                continue;
            }
            adj[u][deg[u]++] = v;
            adj[v][deg[v]++] = u;
        }
        cout << "Graph created.\n";
    }
    void display() const {
        if (V == 0) {
            cout << "Create the graph first.\n";
            return;
        }
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int j = 0; j < deg[i]; j++) cout << adj[i][j] << " ";
            cout << "\n";
        }
    }
    void dfsRecursive(int start) {
        if (V == 0) {
            cout << "Create the graph first.\n";
            return;
        }
        if (start < 0 || start >= V) {
            cout << "Invalid start vertex.\n";
            return;
        }
        bool visited[MAXV] = {false};
        cout << "DFS (recursive): ";
        dfsRec(start, visited);
        cout << "\n";
    }
    void dfsIterative(int start) {
        if (V == 0) {
            cout << "Create the graph first.\n";
            return;
        }
        if (start < 0 || start >= V) {
            cout << "Invalid start vertex.\n";
            return;
        }
        bool visited[MAXV] = {false};
        static int st[MAXV * MAXV];
        int top = -1;
        st[++top] = start;
        cout << "DFS (iterative): ";
        while (top >= 0) {
            int u = st[top--];
            if (visited[u]) continue;
            visited[u] = true;
            cout << u << " ";
            for (int j = deg[u] - 1; j >= 0; j--)
                if (!visited[adj[u][j]]) st[++top] = adj[u][j];
        }
        cout << "\n";
    }
};

int main() {
    Graph g;
    int choice, start;
    while (true) {
        cout << "\nMenu:\n1. Create graph\n2. Display adjacency list\n";
        cout << "3. DFS (recursive)\n4. DFS (iterative)\n5. Quit\n";
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
            cout << "Enter starting vertex: ";
            cin >> start;
            g.dfsRecursive(start);
            break;
        case 4:
            cout << "Enter starting vertex: ";
            cin >> start;
            g.dfsIterative(start);
            break;
        case 5:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
