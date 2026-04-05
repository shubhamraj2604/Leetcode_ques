class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // brute force will be using 3 for loop for each index
        // we can do this in nlogn
        vector<vector<int>>ans;
        sort(nums.begin() , nums.end());
         int n = nums.size();
        for(int i=0;i<n;i++){
            if(i> 0 && nums[i] == nums[i-1])continue;
            int low = i+1;
            int high = n - 1;
            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];
                if(sum == 0){
                    ans.push_back({nums[i] , nums[low] , nums[high]});
                    int h = nums[low];
                    int x = nums[high];
                    while(low < high && nums[low] == h)low++;
                    while(low < high && nums[high] == x)high--;
                }else if(sum < 0){
                    low++;
                }else {
                    high--;
                }
            }
        }

        return ans;
    }
};
