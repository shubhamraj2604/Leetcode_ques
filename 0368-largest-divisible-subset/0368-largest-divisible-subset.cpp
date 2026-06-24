class Solution {
public:
    vector<vector<vector<int>>> dp;

    vector<int> solve(vector<int>&nums , int prev , int idx){
        if (idx == nums.size()) {
            return {};
        }

        if (!dp[prev + 1][idx].empty()) {
            return dp[prev + 1][idx];
        }

        vector<int> notTake = solve(nums, prev, idx + 1);


        vector<int> take;
        if (prev == -1 || nums[idx] % nums[prev] == 0) {
            take = solve(nums, idx, idx + 1);
            take.insert(take.begin(), nums[idx]);
        }

        if (take.size() > notTake.size()) {
            return dp[prev + 1][idx] = take;
        }


         return dp[prev + 1][idx] = notTake; 
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        dp.resize(n + 1, vector<vector<int>>(n));

        return solve(nums, -1, 0);
    }
};