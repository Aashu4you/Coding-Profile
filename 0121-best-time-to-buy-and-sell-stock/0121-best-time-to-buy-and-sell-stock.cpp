class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = INT_MAX;
        int maxi = 0;
        for(int price:prices){
            minp = min(minp,price);
            maxi = max(maxi,price-minp);
        }
        return maxi;
    }
};