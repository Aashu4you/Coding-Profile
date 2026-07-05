class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int prefix = 0 , count =0;
        for(int x : arr){
            prefix += x;
            int rem = prefix % k;
            if(rem<0) rem += k;
            if(mp.find(rem)!=mp.end()){
                count += mp[rem];
            }
            mp[rem]++;
        }
        return count;
    }
};