//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> rotten;
        int freshCount = 0;
        int minutes = 0;

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        
        while (!rotten.empty() && freshCount > 0) {
            int size = rotten.size();
            while (size--) {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();

                
                for (auto& dir : directions) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    
                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2; 
                        freshCount--; 
                        rotten.push({newX, newY}); 
                    }
                }
            }
            minutes++;
        }
        return freshCount == 0 ? minutes : -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends