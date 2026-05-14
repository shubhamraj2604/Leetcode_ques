class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int,int>m;
        int maxi = nums[0];
        int n = nums.size();
        for(auto c:nums){
            maxi = max(maxi , c);
            m[c]++;
        }
        if(n != maxi + 1)return false;
        for(int i=1;i<=maxi;i++){
               if(i == maxi){
                 if(m[maxi] != 2)return false;
               }else{
                if(m[i] != 1)return false;
               }
               
        }
        return true;
    }
};