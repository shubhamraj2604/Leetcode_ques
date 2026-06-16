class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&prices , int index , int buy){
        if(index >= prices.size()){
            return 0;
        }

        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        int profit;
        if(buy){
             profit = max(solve(prices , index + 1 , 0) - prices[index], solve(prices , index + 1 , 1));
        }else {
            profit = max(prices[index] + solve(prices , index + 2 , 1) , solve(prices , index + 1 , 0));
        }

        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n , vector<int>(2 , -1));
        return solve(prices , 0 , 1);
    }
};