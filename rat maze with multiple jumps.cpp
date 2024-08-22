//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool safe(int x,int y,int n,vector<vector<int>>&m){
        return ( x>=0 && x<n && y>=0 && y<n && m[x][y]!=0); 
    }
    bool fn(vector<vector<int>>&m,vector<vector<int>>&vis, int x,int y,int n){
        if(x==n-1 && y==n-1){
            vis[x][y]=1;
            return true;
        }
        if(safe(x,y,n,m) && !vis[x][y]){
            vis[x][y]=1;
            for(int i=1;i<=m[x][y] && i<n;i++){
                if(fn(m,vis,x,y+i,n)) return true;
                if(fn(m,vis,x+i,y,n)) return true;
            }
            vis[x][y]=0;
            return false;
        } 
        return false;
    }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   int n=matrix.size();
        vector<vector<int>>vis(n,vector<int>(n,false));
        if(fn(matrix,vis,0,0,n)==false) return {{-1}};
        return vis;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends