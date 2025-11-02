#include <iostream>
#include <string>
using namespace std;

#define MAX 10   // Maximum number of web pages

class WebGraph {
    int adj[MAX][MAX];   // Adjacency matrix for hyperlinks
    string pages[MAX];   // Store page names (URLs)
    int visited[MAX];    // Track visited pages
    int n;               // Number of pages

public:
    WebGraph(int numPages) {
        n = numPages;
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
            for (int j = 0; j < n; j++)
                adj[i][j] = 0;
        }
    }

    void setPageName(int index, string name) {
        pages[index] = name;
    }

    void addLink(int src, int dest) {
        // Directed link from src → dest
        adj[src][dest] = 1;
    }

    void displayAdjacencyMatrix() {
        cout << "\nAdjacency Matrix:\n";
        cout << "    ";
        for (int i = 0; i < n; i++)
            cout << pages[i] << " ";
        cout << endl;

        for (int i = 0; i < n; i++) {
            cout << pages[i] << " : ";
            for (int j = 0; j < n; j++) {
                cout << adj[i][j] << "   ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void BFS(int start) {
        int queue[MAX];
        int front = 0, rear = -1;

        // Mark starting page as visited and enqueue it
        visited[start] = 1;
        queue[++rear] = start;

        cout << "Starting BFS Web Indexing from: " << pages[start] << "\n\n";
        cout << "Indexed Order of Pages:\n";

        while (front <= rear) {
            int current = queue[front++];   // Dequeue
            cout << pages[current] << endl; // "Index" this page

            // Explore all linked pages
            for (int i = 0; i < n; i++) {
                if (adj[current][i] == 1 && visited[i] == 0) {
                    visited[i] = 1;
                    queue[++rear] = i;  // Enqueue the linked page
                }
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter number of web pages (max " << MAX << "): ";
    cin >> n;

    WebGraph web(n);

    cout << "\nEnter page names:\n";
    for (int i = 0; i < n; i++) {
        string name;
        cout << "Page " << i << ": ";
        cin >> name;
        web.setPageName(i, name);
    }

    int links;
    cout << "\nEnter number of hyperlinks: ";
    cin >> links;

    cout << "Enter links as pairs (source destination) using page indices (0-" << n - 1 << "):\n";
    for (int i = 0; i < links; i++) {
        int src, dest;
        cin >> src >> dest;
        web.addLink(src, dest);
    }

    // Display adjacency matrix before BFS
    web.displayAdjacencyMatrix();

    int start;
    cout << "\nEnter starting page index for BFS: ";
    cin >> start;

    cout << "\n--- Web Indexing Simulation ---\n";
    web.BFS(start);

    return 0;
}
