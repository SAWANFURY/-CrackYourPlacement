//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    // Function to check if the current color assignment is safe for vertex v
bool isSafe(int v, vector<int>& color, vector<vector<int>>& graph, int c) {
    for (int i = 0; i < graph[v].size(); i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return false; // Adjacent vertex has the same color
        }
    }
    return true;
}

// A recursive function to solve the M-coloring problem
bool graphColoringUtil(vector<vector<int>>& graph, int M, vector<int>& color, int v, int N) {
    if (v == N) {
        return true; // All vertices are colored
    }

    // Try different colors for vertex v
    for (int c = 1; c <= M; c++) {
        if (isSafe(v, color, graph, c)) {
            color[v] = c;

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, M, color, v + 1, N)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution, remove it
            color[v] = 0;
        }
    }

    return false;
}
    bool graphColoring(bool graph[101][101], int n, int m) {
    vector<int> color(n, 0); 
    return graphColoringUtil(graph, m, color, 0, n);

}


    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends