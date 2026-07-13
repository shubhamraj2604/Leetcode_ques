class Solution {
public:
    bool checkrow(vector<vector<int>>& grid , int &limit , int a , int b){
        for(int i=0;i<grid.size();i++){
            if(abs(grid[i][b] - grid[i][a]) > limit){
                return false;
            }
        } 
        return true;
    }
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& grid , int limit , int prev , int index){
        if(index >= grid[0].size()){
            return 0;
        }
        //satisfied
        if(dp[index][prev + 1] !=-1){
            return dp[index][prev + 1];
        }
        if(prev == -1){
            // no element taken before it
            // choose to take it or not;
            int take = 1 + solve(grid , limit , index , index + 1);
            int notake = solve(grid , limit , prev , index + 1);
            return dp[index][prev + 1] = max(take, notake);
        }
        if(prev != -1 && checkrow(grid , limit , prev , index)){
            return dp[index][prev + 1] = max(1 + solve(grid , limit , index , index + 1),solve(grid , limit , prev , index + 1));
        }
        return dp[index][prev + 1] = solve(grid , limit , prev , index + 1);
    }
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(m , vector<int>(m+1 , -1));
        return solve(grid , limit , -1 , 0);
    }
};