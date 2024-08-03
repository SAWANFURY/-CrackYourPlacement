class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        map<int,int> mp;
        stack<int> st;
        for(int i=0;i<nums2.size();i++){
            while(!st.empty()&&st.top()<nums2[i]){
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            if(mp[nums1[i]]){
               arr.push_back(mp[nums1[i]]);
            }
            else arr.push_back(-1);
        }
        return arr;
    }
};