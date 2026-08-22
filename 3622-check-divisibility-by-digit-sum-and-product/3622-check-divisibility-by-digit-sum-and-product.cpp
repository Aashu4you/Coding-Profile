class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int digitsum = 0;
        int digitprod = 1;
        while(n>0){
            int digit = n % 10;
            digitsum += digit;
            digitprod *= digit;
            n /=10;
        }
        int total = digitsum + digitprod;
        return original % total ==0;
    }
};