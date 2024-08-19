class Solution {
private:

    bool isCycle(vector<vector<int>>& g, int vertex, vector<bool> &visited, vector<bool> &inRecursion) {
        
        if(inRecursion[vertex]) return true;

        if(visited[vertex]) return false;

        visited[vertex] = true;
        inRecursion[vertex] = true;

        for(int &child : g[vertex]) {
            
            if(isCycle(g, child, visited, inRecursion)) return true;
        }

        inRecursion[vertex] = false;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();  

        vector<bool> visited(n, false);    
        vector<bool> inRecursion(n, false); 

        
        for (int i = 0; i < n; i++) {
            if(!visited[i]){
                isCycle(graph, i, visited, inRecursion);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if(inRecursion[i] == false) ans.push_back(i);
        }
        
        return ans; 
    }
};