class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
         if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        unordered_map<int,int>m;
        for(auto c:nums){
                m[c]++;
        }
        int ans = -1;
        if(k == 1){
            // print the largest no which is not repeated;
            for(auto c:m){
               if(c.second == 1){
                ans = max(ans , c.first);
               }
            }
        }else{
           if(m[nums[0]] == 1){
              ans = max(ans , nums[0]);
           }

           if(m[nums[n-1]] == 1){
              ans = max(ans , nums[n-1]);
           }
        }
        return ans;
    }
};