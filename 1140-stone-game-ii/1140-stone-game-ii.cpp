class Solution {
public:
    // 0 = alice , 1 = bob
    vector<vector<vector<int>>>dp;
    int solve(vector<int>& piles, int index, int M, int turn, vector<int>& suffix) {
      int n = piles.size();
       if (index >= n) return 0;
        if(dp[index][M][turn]!=-1){
            return dp[index][M][turn];
        }
        int limit = min(2 * M, n - index);

       if (turn == 0) { // Alice (maximize)
         int ans = 0;
         for (int i = 1; i <= limit; i++) {
            int currsum = suffix[index] - suffix[index + i];
            ans = max(ans, currsum + solve(piles, index + i, max(M, i), 1, suffix));
         }
         return dp[index][M][turn]= ans;
      } 
       else { // Bob (minimize Alice's score)
        int ans = INT_MAX;
        for (int i = 1; i <= limit; i++) {
            int currsum = suffix[index] - suffix[index + i];
            ans = min(ans, solve(piles, index + i, max(M, i), 0, suffix));
        }
        return dp[index][M][turn]= ans;
    }
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int>suffix(n+1 , 0);
        for(int i=n-1;i>=0;i--){
            suffix[i] = suffix[i+1] + piles[i];
        }
        dp.resize(n , vector<vector<int>>(n+1 , vector<int>(2 , -1)));
        return solve(piles , 0 ,1 , 0 , suffix);
    }
};