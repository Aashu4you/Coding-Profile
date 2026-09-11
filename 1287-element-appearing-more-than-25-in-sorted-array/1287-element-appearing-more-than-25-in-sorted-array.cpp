class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> map;
        for(int x:arr){
            map[x]++;
        }
        for(auto it:map){
            if(it.second>n/4){
                return it.first;
            }
        }
        return 0;
    }
};