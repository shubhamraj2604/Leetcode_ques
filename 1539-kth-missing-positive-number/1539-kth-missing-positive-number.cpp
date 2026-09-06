class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]<=k){
        //         k++;
        //     }
        //     else{
        //         break;
        //     }
        // }
        // return k;
        int l = 0 , r = arr.size() - 1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(arr[mid] - mid <= k){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

        return l + k;
    }
};