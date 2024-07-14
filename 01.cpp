class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(int a:nums){
         mp[a]++;
        }
        for(auto pair :mp){
        if(pair.second>1){
            return pair.first;
        }}
        return 0;
    }
};