class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       
        int n = nums.size();
        int l = 0 , r = 0;
        sort(nums.begin() , nums.end());           
        long long sum = 0;
        int maxlength = INT_MIN;
        while(r< n){
            sum+=nums[r];
            while((long long)nums[r] * (r - l + 1) - sum > k){
                sum-=nums[l];
                l++;
            }

            maxlength = max(maxlength , r - l + 1);
            r++;
        }
        return maxlength;
    }
};