class Solution {
public:
    int strStr(string haystack, string needle) {
        int search = haystack.find(needle);
        if(search == haystack.npos){
            return -1;
        }
        return search;
    }
};