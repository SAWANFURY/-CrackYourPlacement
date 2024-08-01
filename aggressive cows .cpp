//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
   bool possible(int k , vector<int>&stalls,int mid){
       int cows = 1;
       int pos = stalls[0];
       for(int i=1;i<stalls.size();i++){
           if(stalls[i]-pos>=mid){
               cows++;
               pos = stalls[i];
               if(cows>=k) return true;
           }
       }
       return false;
   }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
         n =stalls.size();
        int low =0;
        int high = stalls[n-1] - stalls[0];
        
        int res=0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possible(k,stalls,mid)){
                res = mid;
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends