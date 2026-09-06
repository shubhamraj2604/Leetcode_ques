class Solution {
public:

    bool binarysearch(vector<int>&ans , int &target){
        int n = ans.size();
        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = low + (high - low)/2;
            if(ans[mid] == target){
                return true;
            }
            else if(ans[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // for(int i =0;i<matrix.size();i++){
        //     vector<int>ans = matrix[i];
        //     int low = 0;
        //     int high = ans.size() - 1;
            
        //     if(ans[low] == target || ans[high] == target){
        //         return true;
        //     }
        //     if(ans[low]<target && target <ans[high]){
        //         return binarysearch(ans,target);
        //     }

        // }        
        // return false;
                // int row = 0 , col = matrix[0].size() - 1;

    //     while(col >= 0  && row < matrix.size()){
    //         if(matrix[row][col] == target){
    //             return true;
    //         }else if(target < matrix[row][col]){
    //             col--;
    //         }else if(target > matrix[row][col]){
    //             row++;
    //         }
    //     }
    //     return false;
            int n = matrix.size();
            int m = matrix[0].size();

            int low = 0;
            int high = n * m - 1;
            while(low <= high){
                int mid = low + (high - low)/2;
                int row = mid / m;
                int col = mid % m;

                if(matrix[row][col] == target){
                    return true;
                }else if(matrix[row][col] < target){
                    low = mid + 1;
                }else {
                    high = mid - 1;
                }
            }
            return false;
    }
};