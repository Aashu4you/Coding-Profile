class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                freq[nums[i]]++;
            }
        }
        int ans = -1;
        int mfreq = 0;
        for(auto it:freq){
            int num=it.first;
            int fre = it.second;
            if(fre>mfreq || (fre==mfreq && num<ans)){
                mfreq=fre;
                ans=num;
            }
        }
        return ans;
    }
};