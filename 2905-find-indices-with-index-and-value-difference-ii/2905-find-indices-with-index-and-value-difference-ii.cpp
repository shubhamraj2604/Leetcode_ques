class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        // vector<int>smin(n);
        // vector<int>smax(n);
        // smin[n-1] = nums[n-1];
        // smax[n - 1] = nums[n - 1];

        // for(int i= n -2 ;i>=0;i--){
        //     smin[i] = min(smin[i+1] , nums[i]);
        //     smax[i] = max(smax[i+1] , nums[i]);
        // }

        // vector<int>ans(2 , -1);
        // for(int i=0;i<n;i++){
        //     int j = i + indexDifference;
        //     if(j<n && (abs(nums[i] - smin[j]) >= valueDifference || abs(nums[i] - smin[j]) >= valueDifference)){
        //         ans[0] = i;
        //         for(int k=j;k<n;k++){
        //             if(abs(nums[i] - nums[k])>= valueDifference){
        //                 ans[1] = k;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // return ans;

        vector<pair<int,int>>smin(n);
        vector<pair<int,int>>smax(n);
        smin[n-1] = {nums[n-1] , n -1};
        smax[n - 1] = {nums[n - 1] , n-1};

        for(int i= n -2 ;i>=0;i--){
            smin[i] = min(smin[i+1] , {nums[i] , i});
            smax[i] = max(smax[i+1] ,{nums[i] , i});
        }
        

        for(int i=0;i<n;i++){
            int j = i + indexDifference;
            if(j>=n)break;

            if(abs(nums[i] - smin[j].first) >= valueDifference){
                return {i , smin[j].second};
            }

            if(abs(nums[i] - smax[j].first) >= valueDifference){
                return {i , smax[j].second};
            }
        }
        return {-1 , -1};
    }
};