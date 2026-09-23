class Solution {
public:
    //  bool minsizesubarray(vector<int>& prefixsum, int k, int target) {
    //     for (int i = k; i < prefixsum.size(); i++) {
    //         if (prefixsum[i] - prefixsum[i - k] >= target) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    int minSubArrayLen(int target, vector<int>& nums) {
    //    int n= nums.size();
    //    vector<int>prefixsum(n+1 , 0);
    //    for (int i = 0; i < n; ++i){
    //         prefixsum[i + 1] = prefixsum[i] + nums[i];
    //     }
    //    int low = 1;
    //    int high = n;
    //    int ans = 0;
    //    while(low<=high){
    //     int mid = low + (high - low)/2;
    //     bool s = minsizesubarray(prefixsum,mid,target);
    //     if(s){
    //         ans = mid;
    //         high = mid - 1;
    //     } 
    //     else{
    //         low = mid + 1;
    //     }
    //    } 
       int l = 0 , r = 0;
       int sum = 0;
       int minlen = INT_MAX;
       while(r<nums.size()){
          sum+=nums[r];
          while(sum>=target){
            if(r-l+1 < minlen){
                minlen = r - l + 1;
            }
            sum-=nums[l];
            l++;
          }
          r++;
       }
       return minlen == INT_MAX ? 0 : minlen;
    }
};