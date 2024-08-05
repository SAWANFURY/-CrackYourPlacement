class Solution {
public:
   void backtrack(int start,vector<int>&arr,vector<vector<int>>&res,int n,int k){
    if(arr.size() == k){
        res.push_back(arr);
    }
    for(int i = start;i<=n;i++){
        arr.push_back(i);
        backtrack(i+1,arr,res,n,k);
        arr.pop_back();
    }
   }
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        vector<vector<int>> res;
        backtrack(1,arr,res,n,k);
        return res;
    }
};