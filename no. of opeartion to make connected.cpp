class Solution {
private:
    vector<int> parent; 
    vector<int> rankk;  
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        x = find(x); 
        y = find(y); 

        if (rankk[x] < rankk[y]) {
            parent[x] = y; 
        } else if (rankk[x] > rankk[y]) {
            parent[y] = x;
        } else {
            parent[y] = x; 
            rankk[x]++;
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int components = n; 
        parent.resize(n);    
        rankk.resize(n, 0);
        if (connections.size() < n - 1) return -1;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& vec : connections) {
            if (find(vec[0]) != find(vec[1])) {
                unionSet(vec[0], vec[1]);
                components--; 
            }
        }

        return components - 1;
    }
};