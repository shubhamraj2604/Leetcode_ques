class Solution {
public:
    int reversedigit(int nums) {
        int l = nums;
        int ans = 0;
        while (l != 0) {
            int rev = l % 10;
            l /= 10;
            ans = ans * 10 + rev;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = INT_MAX;
        for (int j = nums.size()-1; j >= 0; j--) {
            int reverse = reversedigit(nums[j]);
            if (m.count(reverse)) {
                int index = m[reverse];
                if (j < index) {
                    ans = min(ans, abs(j - m[reverse]));
                }
            }
            m[nums[j]] = j;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};