class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> mp;
        for(int num : nums){
             mp[num]++;
        }
        nums.clear();
        for(auto a : mp){
            if(a.second==2){
                nums.push_back(a.first);
            }
        }
        return nums;
    }
};