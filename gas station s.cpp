class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int total = 0;
        int diff =0;
        for(int i=0;i<gas.size();i++){
            total += gas[i]-cost[i];
            diff += gas[i]-cost[i];
        
        if(total<0){
            total = 0;
            start = i+1;
        }}
        if(diff<0){
            return -1;
        }
        return start;
    }
};