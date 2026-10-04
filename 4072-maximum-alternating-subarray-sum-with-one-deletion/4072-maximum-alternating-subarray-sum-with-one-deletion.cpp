class Solution {
public:
    vector<vector<vector<long long>>>dp;
    long long solve(vector<int>&nums , int del , int op , int index){
        if(index>=nums.size()){
           return LLONG_MIN/ 2;
        }
        if(dp[index][op][del] != LLONG_MIN){
            return dp[index][op][del];
        }
        long long take;
        if(op == 0){
            take = (long long)nums[index] + max(0LL , solve(nums , del , !op , index + 1));
        }else if(op == 1){
             take = max(solve(nums , del , !op , index + 1) , 0LL) - (long long)nums[index];
        }

        long long ans = take;
        if(del == 0){
            ans = max(ans , solve(nums , 1 , op , index + 1));
        }

        return dp[index][op][del] = ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        dp.resize(nums.size() , vector<vector<long long>>(2 , vector<long long>(2 , LLONG_MIN)));
        
        long long max_sum = LLONG_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            max_sum = max(max_sum, solve(nums, 0, 0, i));
          }
        return max_sum;
    }
};