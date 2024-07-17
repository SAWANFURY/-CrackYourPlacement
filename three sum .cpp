class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k = nums.size()-1;

            while(j<k){
                int third = nums[i]+nums[j]+nums[k];
                if(third>0){ k--; }
                else if(third<0){ j++; }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    
                while(nums[j]==nums[j-1]&&j<k) j++;
                while(nums[k]==nums[k+1] && j<k ) k--;
                }
            }
        }
return ans;
    }
};