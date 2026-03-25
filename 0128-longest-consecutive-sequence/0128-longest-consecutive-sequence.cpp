class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        // sort(nums.begin(),nums.end());

        // int count=1;
        // int maxlength=1;
        // for(int i=1;i<nums.size();i++){
        //     if (nums[i] == nums[i - 1]){
        //     continue;
        //     } 
                
            
            
        //     if(nums[i] == nums[i-1]+1){
        //         count++;
        //     }
        //     else{
        //         count=1;
        //     }

        //     maxlength=max(maxlength,count);

        // }
        int maxlength = INT_MIN;
        unordered_map<int,int>m;
        for(auto c:nums){
            if(m.count(c))continue;
            int left = m.count(c - 1) ? m[c - 1] : 0;
            int right = m.count(c + 1) ? m[c + 1] : 0;

            int length = left + right + 1;
            m[c] = length;
            m[c - left] = m[c];
            m[c + right] = m[c];

            maxlength = max(maxlength , m[c]);

        } 

        return maxlength;
    }
};