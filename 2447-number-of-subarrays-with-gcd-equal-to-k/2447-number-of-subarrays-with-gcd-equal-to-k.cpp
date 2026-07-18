class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            int curr_gcd = 0;
            for(int j=i;j<nums.size();j++){
                curr_gcd = gcd(curr_gcd , nums[j]);
                if(curr_gcd == k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};