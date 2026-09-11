class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> freq(10,0);
        int ans = 0 , maxi = INT_MAX;
        while(n>0){
            int num = n%10;
            freq[num]++;
            n/=10;
        }
        for(int i=0;i<10;i++){
            if(freq[i]>0 && freq[i]<maxi){
                maxi=freq[i];
                ans=i;
            }
        }
        return ans;
    }
};