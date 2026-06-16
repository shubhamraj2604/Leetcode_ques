class Solution {
public:

        vector<vector<vector<int>>>dp;
    int solve(vector<int>&prices , int index , int buy , int cap){
        if(index >= prices.size() || cap == 2){
            return 0;
        }

        if(dp[index][buy][cap] != -1){
            return dp[index][buy][cap];
        }
        int profit;
        if(buy){
            // buy or not buy
            profit = max(solve(prices , index + 1 , 0 , cap) - prices[index], solve(prices , index + 1 , 1 , cap));
        }else{
            profit = max(prices[index] + solve(prices , index + 1 , 1 , cap + 1) , solve(prices , index + 1 , 0 , cap));
        }

        return dp[index][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n , vector<vector<int>>(2, vector<int>(3 , -1)));

        return solve(prices , 0 , 1 , 0);
    }
};