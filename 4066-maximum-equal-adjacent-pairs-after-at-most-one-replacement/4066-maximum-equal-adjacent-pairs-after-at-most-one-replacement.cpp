class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        // pair is global read the question properly
        // int maxlength = INT_MIN;
        // int l = 0 , r=0;
        // unordered_map<int,int>m;
        // while(r<nums.size()){
        //    m[nums[r]]++;
        //    if(m.size() > 2){
        //        m[nums[l]]--;
        //        if(m[nums[l]] == 0){
        //           m.erase(nums[l]);
        //        }
        //        l++;
        //    }

        //    maxlength = max(maxlength , r - l + 1);
        //    r++;
        // }
        // return maxlength - 1;

        int ans = 0 , equal = 0;
        map<pair<int,int>,int>m;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                equal++;
            }else{
                int a = nums[i];
                int b = nums[i-1];
                if(a>b){
                    swap(a , b);
                }

                m[{a,b}]++;
                ans = max(ans , m[{a,b}]);
            }
        }

        return ans + equal;
    }
};