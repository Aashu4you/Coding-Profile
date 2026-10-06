class Solution {
public:
    int minAddToMakeValid(string s) {
        int low = 0;
        int ans = 0;
        for(char c:s){
            if(c=='('){
                low++;
            }else{
                if(low>0){
                    low--;
                }else{
                    ans++;
                }
            }
            
        }
        return low+ans;
    }
};