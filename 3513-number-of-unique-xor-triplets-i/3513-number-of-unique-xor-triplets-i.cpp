class Solution {
public:
    bool power(int n){
        return n>0 && (n & (n-1)) == 0;
    }
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 1;
        if(n == 2)return 2;
        int ans = 0;
        if(power(n)){
            ans =  n * 2;
            return ans;
        }

          int nextPow2 = 1;
          while (nextPow2 <= n)nextPow2 <<= 1;

        return nextPow2;
    }
};