class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l = 0 , r = 0;
        int sum = 0;
        for(auto c:nums)sum+=c;
        int target = sum - x;
        if (target < 0) return -1;
        if (target == 0) return nums.size();
        int ans = -1;
        sum = 0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum > target){
                sum-=nums[l];
                l++;
            }

            if(sum == target){
                ans = max(ans , r - l + 1);
            }
            r++;
        }
        if(ans == -1)return -1;
        return nums.size() - ans;
    }
};