class Solution {
public:
    bool hasZero(int n){
        while(n>0){
            if(n%10==0){
                return true;
            }
            n/=10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        int x = n;
        int a = 1;
        while(true){
            int b = x-a;
            if(!hasZero(a) && !hasZero(b)){
                return {a,b};
            }
            a++;
        }

    }
};