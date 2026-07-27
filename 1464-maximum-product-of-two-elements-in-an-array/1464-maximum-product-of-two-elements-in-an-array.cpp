class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int smaxi = INT_MIN;
        for(auto c:nums){
            if(c > maxi){
                smaxi = maxi;
                maxi = c;
            }else if(c > smaxi){
                smaxi = c;
            }
        }

        return (smaxi - 1) * (maxi - 1);
    }
};