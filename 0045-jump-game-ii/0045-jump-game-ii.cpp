class Solution {
public:
    int jump(vector<int>& nums) {
      int maxjump = 0;
      int nxtjump = 0;
      int cnt = 0;
      for(int i=0;i<nums.size() - 1;i++){
         maxjump = max(maxjump , nums[i] + i);
         if(i == nxtjump){
            cnt++;
            nxtjump = maxjump; 
         }
      }

      return cnt;
    }
};