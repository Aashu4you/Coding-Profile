class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int mod = purchaseAmount %10;
        if(mod!=0){
            if(mod>=5){
                purchaseAmount+=10-mod;
            }else{
                purchaseAmount-=mod;
            }
        }
        return 100-purchaseAmount;
    }
};