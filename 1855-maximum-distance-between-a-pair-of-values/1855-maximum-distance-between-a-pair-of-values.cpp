class Solution {
public:
 
    // int binarysearch(vector<int>&nums2 , int key){
    //     int low = 0;
    //     int high = nums2.size() - 1;
    //     int ans = -1;
    //     while(low<=high){
    //         int mid = low + (high - low) /2;
    //            if(nums2[mid]>=key){
    //             ans = mid;
    //             low= mid + 1;
    //         }
    //         else{
    //             high = mid - 1;
    //         }
    //     }
    //     cout<<low<<" "<<endl;
    //     return ans;
    // } 
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
         int diff = 0;
         int j = 0;
        for(int i=0;i<n;i++){
            while(j<nums2.size() && nums1[i]<=nums2[j]){
                j++;
            }

            diff = max(diff , j - i - 1);
        }

        return diff;
    }
};