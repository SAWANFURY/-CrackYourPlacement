#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    int WordWrap(int remain, int i, vector<int>& nums, int k, unordered_map<string, int>& memo) {
        if (i == nums.size()) {
            return 0;
        }
        
        string key = to_string(i) + ":" + to_string(remain);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        int ans;
        if (nums[i] > remain) {
            ans = pow(remain + 1, 2) + WordWrap(k - nums[i] - 1, i + 1, nums, k, memo);
        } else {
            int choice1 = pow(remain + 1, 2) + WordWrap(k - nums[i] - 1, i + 1, nums, k, memo);
            int choice2 = WordWrap(remain - nums[i] - 1, i + 1, nums, k, memo);
            ans = min(choice1, choice2);
        }
        
        memo[key] = ans;
        return ans;
    }

    int solveWordWrap(vector<int>& nums, int k) {
        unordered_map<string, int> memo;
        return WordWrap(k, 0, nums, k, memo);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 2, 5};  // Example word lengths
    int k = 6;  // Maximum width of each line
    int result = sol.solveWordWrap(nums, k);
    cout << "Minimum cost of word wrapping: " << result << endl;
    return 0;
}
