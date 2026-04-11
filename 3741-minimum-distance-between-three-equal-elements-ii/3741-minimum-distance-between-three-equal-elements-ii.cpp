class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,int>m;
        unordered_map<int,int>last , second_last;
         int minans = INT_MAX;
        for(int i=0;i<nums.size();i++){
               if(!last.count(nums[i]) || last[nums[i]] == -1){
                  last[nums[i]] = i;
               }else if(!second_last.count(nums[i])){
                   second_last[nums[i]] = i;
               }else{
                    int last_index = last[nums[i]];
                    int second = second_last[nums[i]];
                    int ans = abs(i - last_index) + abs(second - i) + abs(last_index - second); 
                    minans = min(minans , ans);
                    last[nums[i]] = second;
                    second_last[nums[i]] = i;
               }
        }

        if(minans == INT_MAX)return -1;
        return minans;
    }
};