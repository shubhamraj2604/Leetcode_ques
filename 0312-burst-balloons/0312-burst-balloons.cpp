class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&nums , int i , int j){
        if(i>j){
            return 0;
        }
        
        if(dp[i][j] !=-1){
            return dp[i][j];
        }
        int mn = INT_MIN;
        for(int k = i; k<=j;k++){
            int temp = solve(nums , i , k - 1) + solve(nums , k+1 , j) + nums[i-1] * nums[k] * nums[j+1];
            mn = max(mn , temp);
        }

        return dp[i][j] = mn;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin() , 1);
        nums.push_back(1);
        dp.resize(303 , vector<int>(303 , -1));
        return solve(nums , 1 , n);
    }
};