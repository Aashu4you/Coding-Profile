class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int length = 0 , l = 0;
        unordered_map<int,int> freq;
        for(int r=0;r<n;r++){
            freq[fruits[r]]++;
            while(freq.size()>2){
                freq[fruits[l]]--;
                if(freq[fruits[l]]==0){
                    freq.erase(fruits[l]);
                }
                l++;
            }
            length= max(length,r-l+1);
        }
        return length;
    }
};