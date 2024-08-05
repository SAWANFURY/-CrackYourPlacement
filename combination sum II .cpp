class Solution {
public:
    void backtrack(vector<int>&candidates,int target,int start,vector<int>&comb,vector<vector<int>>&res){
        if(target<0) return;
        if(target == 0){
            res.push_back(comb);
        }
        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target) break;
            comb.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],i+1,comb,res);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> ans;
        backtrack(candidates,target,0,ans,res);
        return res;
    }
};