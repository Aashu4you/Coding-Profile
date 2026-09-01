class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<pair<int,int>> litter;
        int sr, sc;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if(classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }
        int k = litter.size();
        if(k == 0)
            return 0;
        vector<vector<int>> id(m, vector<int>(n, -1));
        for(int i = 0; i < k; i++) {
            id[litter[i].first][litter[i].second] = i;
        }
        int fullMask = (1 << k) - 1;
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << k, false)
                )
            )
        );
        queue<array<int,5>> q;
        visited[sr][sc][energy][0] = true;
        q.push({sr, sc, energy, 0, 0});
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!q.empty()) {
            auto [r, c, e, mask, dist] = q.front();
            q.pop();
            if(mask == fullMask)
                return dist;
            for(int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;
                if(classroom[nr][nc] == 'X')
                    continue;
                if(e == 0)
                    continue;
                int ne = e - 1;
                int nmask = mask;
                if(classroom[nr][nc] == 'L') {
                    int bit = id[nr][nc];
                    nmask |= (1 << bit);
                }
                if(classroom[nr][nc] == 'R') {
                    ne = energy;
                }
                if(!visited[nr][nc][ne][nmask]) {
                    visited[nr][nc][ne][nmask] = true;
                    q.push({
                        nr,
                        nc,
                        ne,
                        nmask,
                        dist + 1
                    });
                }
            }
        }
        return -1;
    }
};