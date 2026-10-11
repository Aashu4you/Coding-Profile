class Solution {
public:
    void dfs(int city , vector<vector<int>>& isConnected , vector<bool>&vis){
        vis[city]=true;
        for(int neigh = 0; neigh<isConnected.size();neigh++){
            if(isConnected[city][neigh]==1 && !vis[neigh]){
                dfs(neigh,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n,false);
        int provinces = 0;

        for(int city = 0; city<isConnected.size();city++){
            if(!vis[city]){
                provinces++;
                dfs(city,isConnected,vis);
            }
        }
        return provinces;
    }
};