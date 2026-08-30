class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int ans = 0 , count =0;
        int l = 0;
        for(int r=0;r<n;r++){
            if(s[r]=='a'||s[r]=='e'||s[r]=='i'||s[r]=='o'||s[r]=='u'){
                count++;
            }
            while(r-l+1>k){
                if(s[l]=='a'||s[l]=='e'||s[l]=='i'||s[l]=='o'||s[l]=='u'){
                    count--;
                }
                l++;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};