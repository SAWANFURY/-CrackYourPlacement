class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int product = nums[nums.size()-1] * nums[nums.size()-2] * nums[nums.size()-3];
        int product1 = nums[0]*nums[1]*nums[nums.size()-1];
        return max(product,product1);
            }
            
};