class Solution {
public:
    // turn = 0 (alice)
    // turn = 1 (bob)
    // turn = 0 -> Alice
    // turn = 1 -> Bob
    vector<vector<int>> dp;
    int solve(vector<int>& stoneValue, int index, int turn) {
        if (index >= stoneValue.size())
            return 0;

        if (dp[index][turn] !=-1)
            return dp[index][turn];

        int sum = 0;

        if (turn == 0) {
            int ans = INT_MIN;
            for (int k = 0; k < 3 && index + k < stoneValue.size(); k++) {
                sum += stoneValue[index + k];
                ans = max(ans, sum + solve(stoneValue, index + k + 1, 1));
            }
            return dp[index][turn] = ans;
        } else {
            int ans = INT_MAX;
            for (int k = 0; k < 3 && index + k < stoneValue.size(); k++) {
                sum += stoneValue[index + k];
                ans = min(ans, -sum + solve(stoneValue, index + k + 1, 0));
            }
            return dp[index][turn] = ans;
        }
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.resize(n, vector<int>(2 , -1));

        int d = solve(stoneValue, 0 , 0);

        if (d > 0)
            return "Alice";
        else if (d < 0)
            return "Bob";
        return "Tie";
    }
};