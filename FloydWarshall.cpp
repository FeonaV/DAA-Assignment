#include <iostream>
#include <iomanip>
using namespace std;

const int MAXV = 100;
const int INF = 1000000000;

class Graph {
    int V = 0;
    int dist[MAXV][MAXV];
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
            for (int j = 0; j < V; j++) dist[i][j] = (i == j) ? 0 : INF;
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
            dist[u][v] = w;
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
            for (int j = 0; j < V; j++)
                if (i != j && dist[i][j] != INF)
                    cout << i << " " << j << " " << dist[i][j] << "\n";
    }
    void floydWarshall() {
        if (V == 0) {
            cout << "Create the graph first.\n";
            return;
        }
        int d[MAXV][MAXV];
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++) d[i][j] = dist[i][j];
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    if (d[i][k] != INF && d[k][j] != INF &&
                        d[i][k] + d[k][j] < d[i][j])
                        d[i][j] = d[i][k] + d[k][j];
        for (int i = 0; i < V; i++)
            if (d[i][i] < 0) {
                cout << "Negative weight cycle detected.\n";
                return;
            }
        cout << "All-pairs shortest distance matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (d[i][j] == INF) cout << setw(5) << "INF";
                else cout << setw(5) << d[i][j];
            }
            cout << "\n";
        }
    }
};

int main() {
    Graph g;
    int choice;
    while (true) {
        cout << "\nMenu:\n1. Create graph\n2. Display edges\n";
        cout << "3. Floyd-Warshall\n4. Quit\n";
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
            g.floydWarshall();
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
