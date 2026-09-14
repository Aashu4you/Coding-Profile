class Solution {
public:
    string thousandSeparator(int n) {
        string num = to_string(n);
        string ans;
        int count=0;
        for(int i=num.size()-1;i>=0;i--){
            if(count==3){
                ans+=".";
                count=0;
            }
            ans+=num[i];
            count++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};