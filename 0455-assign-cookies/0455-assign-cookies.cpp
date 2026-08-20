class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = s.size();
        int cc = 0;
        int child =0 , cookie = 0 ;
        while(child<g.size() && cookie<s.size()){
            if(s[cookie]>=g[child]){
                cc++;
                child++;
                cookie++;
            }else{
                cookie++;
            }
        }
        return cc;
    }
};