class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto c:nums){
            m[c]++;
        }
        int sum = nums[0];
        for(int i=1;i<nums.size();i++){
          if(nums[i] == nums[i-1] + 1){
              sum+=nums[i];
          }else{
            break;
          }
        }

         while (m.count(sum)) sum++;
        return sum;
    }
};