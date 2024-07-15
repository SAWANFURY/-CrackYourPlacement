class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price = prices[0];
        int maxi = 0;
        for(int i=0;i<prices.size();i++){
            int cost = prices[i]-price;
            maxi = max(maxi,cost);
            price = min(price,prices[i]);
        }
        return maxi;
    }
};