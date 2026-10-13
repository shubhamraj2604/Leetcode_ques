class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
       for(int i=0;i<nums.size();i++){
         nums[i] = abs(nums[i]);
       }
       sort(nums.begin() , nums.end());
       int half = nums.size() / 2;
       long long sum = 0;
       for(int i=0;i<half;i++){
          sum-=nums[i] * nums[i];
       }

       for(int i=half;i<nums.size();i++){
        sum+=nums[i] * nums[i];
       }

       return sum;   
    }
};