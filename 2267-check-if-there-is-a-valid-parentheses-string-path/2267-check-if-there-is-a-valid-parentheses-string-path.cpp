class Solution {
public:
    vector<vector<vector<int>>>dp;
    bool solve(vector<vector<char>>&grid , int i , int j , int balance){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()){
            return false;        
        }
        if(grid[i][j] == '('){
            balance++;
        }else{
            balance--;
        }

        if(balance < 0){
            return false;
        }
        if(dp[i][j][balance] != -1){
            return dp[i][j][balance];
        }
        if(i == grid.size() - 1 && j == grid[0].size() - 1){
            return dp[i][j][balance] = balance == 0;
        }
        bool down = solve(grid , i+1 , j , balance);
        bool right = solve(grid , i , j+1 , balance);

        return dp[i][j][balance] = down || right;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] == ')'){
            return false;
        }
        dp.assign(m, vector<vector<int>>(
            n, vector<int>(m + n + 1, -1)
        ));
        return solve(grid , 0 , 0 , 0);
    }
};