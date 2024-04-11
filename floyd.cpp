#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX

// Function to find all pairs shortest paths using Floyd's algorithm
void floyd(vector<vector<int>>& graph, int n) {
    // Initialize the distance matrix with the given graph
    vector<vector<int>> dist = graph;

    // Initialize the predecessor matrix with -1
    vector<vector<int>> pred(n, vector<int>(n, -1));

    // Floyd's algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = k;
                }
            }
        }
    }

    // Output the results
    for (int problem = 0; problem < n; problem++) {
        cout << "Problem " << problem + 1 << ": n = " << n << endl;
        cout << "P matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (pred[i][j] != -1 ? pred[i][j] + 1 : 0) << " ";
            }
            cout << endl;
        }
        cout << "V1-Vj: shortest path and length" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    cout << "V" << i + 1 << " V" << j + 1 << ": ";
                    if (dist[i][j] == INF)
                        cout << "No path exists" << endl;
                    else {
                        cout << "V" << i + 1 << " ";
                        int temp = pred[i][j];
                        while (temp != -1) {
                            cout << "V" << temp + 1 << " ";
                            temp = pred[temp][j];
                        }
                        cout << "V" << j + 1 << ": " << dist[i][j] << endl;
                    }
                }
            }
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <graph-file>" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    if (!file) {
        cerr << "Error: Unable to open file " << argv[1] << endl;
        return 1;
    }

    int n;
    while (file >> n) {
        vector<vector<int>> graph(n, vector<int>(n));
        // Read the adjacency matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                file >> graph[i][j];
            }
        }
        // Find all pairs shortest paths using Floyd's algorithm
        floyd(graph, n);
    }

    return 0;
}
