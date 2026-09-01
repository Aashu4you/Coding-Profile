class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int count1=0;
        int count2=0;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        for(int i=0;i<n/2;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                count1++;
            }
        }
        for(int i=n/2;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                count2++;
            }
        }
        return count1==count2;
    }
};