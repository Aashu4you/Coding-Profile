class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp = score;
        sort(temp.rbegin(),temp.rend());
        unordered_map<int,int> rank;
        for(int i=0;i<temp.size();i++){
            rank[temp[i]]=i+1;
        }
        vector<string> ans;
        for(int value:score){
            int position = rank[value];
            if(position==1){
                ans.push_back("Gold Medal");
            }else if(position==2){
                ans.push_back("Silver Medal");
            }else if(position==3){
                ans.push_back("Bronze Medal");
            }else{
                ans.push_back(to_string(position));
            }
        }
        return ans;
    }
};