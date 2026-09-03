class Solution {
public:
    int solve(int n , int m , vector<vector<int>>& obstacleGrid , 
       vector<vector<int>> &t){
        if(n==0 && m == 0){
           return obstacleGrid[0][0] == 1 ? 0 : 1;
        }

        if(n<0 || m<0)return 0;

        if(t[n][m] !=-1){
            return t[n][m];
        }
        int x = 0, y = 0;
        if(obstacleGrid[n][m] != 1){
            x+=solve(n,m-1,obstacleGrid, t);
            y+=solve(n-1,m,obstacleGrid , t);
        }

        return t[n][m] = x + y; 

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int n = obstacleGrid.size();
       int m = obstacleGrid[0].size();

    //    vector<vector<int>>t(n,vector<int>(m,-1));
       
    //    return solve(n - 1,m-1 , obstacleGrid , t);
         vector<vector<int>>t(n+1,vector<int>(m+1,0));
         t[1][1] = obstacleGrid[0][0] == 1 ? 0 : 1;
         for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i == 1 && j == 1)continue;
                if(obstacleGrid[i-1][j-1] != 1){
                  t[i][j] = t[i-1][j] + t[i][j-1];
                }
            }
         }
         return t[n][m];
    }
};