#include <iostream>
#include <string>
using namespace std;

#define MAX 10

class WebGraph {
    int adj[MAX][MAX];
    string pages[MAX];
    int visited[MAX];
    int n;

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
    
    string getPageName(int index) {
        if (index >= 0 && index < n) {
            return pages[index];
        }
        return "ERROR: Invalid Index";
    }

    void addLink(int src, int dest) {
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

    void DFS(int start) {
        visited[start] = 1;
        cout << pages[start] << endl; 

        for (int i = 0; i < n; i++) {
            if (adj[start][i] == 1 && visited[i] == 0) {
                DFS(i);
            }
        }
    }

    void resetVisited() {
        for (int i = 0; i < n; i++)
            visited[i] = 0;
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

    web.displayAdjacencyMatrix();

    int start;
    cout << "\nEnter starting page index for DFS: ";
    cin >> start;

    cout << "\n--- Web Indexing Simulation (DFS) ---\n";
    cout << "Starting DFS Web Indexing from: " << web.getPageName(start) << "\n\n";
 
    cout << "Indexed Order of Pages:\n";
    web.resetVisited();
    web.DFS(start);

    return 0;
}
