class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        health-=grid[0][0];
        if (health <= 0) return false;
        queue<pair<int,pair<int,int>>>q;
        q.push({health , {0 , 0}});
        
        vector<vector<int>>best(n , vector<int>(m , INT_MIN));
         int dx[] = {-1,1,0,0};
         int dy[] = {0 , 0 , -1 ,1};
         best[0][0] = health ;
        while(!q.empty()){
            int h = q.front().first;
            int i = q.front().second.first;
            int j = q.front().second.second;
            q.pop();
              
            if(h < 0 || h < best[i][j])continue;

            if(i == n - 1 && j == m-1)return true;

            for(int k=0;k<4;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(nx >= 0 && nx < n && ny>=0 && ny<m){
                    if(grid[nx][ny] == 1){
                        int newhealth = h - 1;
                        if(newhealth > 0 && newhealth > best[nx][ny]){
                            best[nx][ny] = newhealth;
                            q.push({newhealth , {nx , ny}});
                        }
                    }else{
                        if(h > best[nx][ny]){
                            best[nx][ny] = h;
                            q.push({h , {nx , ny}});
                        }
                    }
                }
            }
        }
        return false;         
    }
};