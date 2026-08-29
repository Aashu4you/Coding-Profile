class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0 , ans =0;
        for(int i=0;i<gain.size();i++){
            alt+=gain[i];
            ans = max(ans,alt);
        }
        return ans;
    }
};