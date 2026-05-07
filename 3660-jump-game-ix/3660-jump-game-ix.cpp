class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n) , suffix(n);

        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = max(nums[i] , prefix[i-1]);
        }
        suffix[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
           suffix[i] = min(nums[i] , suffix[i+1]);
        }
        
        int start = 0;
        vector<int>ans(n);
        for(int i=0;i<n-1;i++){
            // means we cant jump
            // next value is greater
            if(prefix[i] <= suffix[i+1]){
               int mx = nums[start];

               for(int j=start;j<=i;j++){
                 mx = max(nums[j] , mx);
               }

               for(int j=start;j<=i;j++){
                   ans[j] = mx;
               }
            start = i + 1;
            }
        }
        
        int mx = nums[start];
        for(int i=start;i<=n-1;i++){
            mx = max(mx , nums[i]);
        }

        for(int i=start;i<=n-1;i++){
            ans[i] = mx;
        }

        return ans;
    }
};