class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        const long long mod = 1e9 + 7;
        for(auto c:queries){
            long long l = c[0];
            long long r = c[1];
            long long k = c[2];
            long long v = c[3];
            while(l<=r){
                nums[l] = ((long long)nums[l] * v) % mod;
                l+=k;
            }
        }

        int x = 0;
        for(auto c:nums){
            x^=c;
        }

        return x;
    }
};