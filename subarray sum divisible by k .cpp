class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix(nums.size());
        int count = 0;
        unordered_map<int,int> mp;
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i] = nums[i] + prefix[i-1];
        }
        for(int i=0;i<prefix.size();i++){
            if(prefix[i]==k) count++;
            if(mp.find(prefix[i]-k)!=mp.end()){
                count += mp[prefix[i]-k];
            }
            mp[prefix[i]]++;
        }
           return count;
    }
};