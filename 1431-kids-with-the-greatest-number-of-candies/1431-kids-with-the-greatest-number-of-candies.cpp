class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxcandies = candies[0];
        for(int i=1;i<candies.size();i++){
            maxcandies = max(maxcandies,candies[i]);
        }
        int n = candies.size();
        vector<bool> ans(n,false);
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=maxcandies){
                ans[i]=true;
            }else{
                ans[i]=false;
            }
        }
        return ans;
    }
};