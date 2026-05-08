class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int l=0,r=0;
        while(r<nums.size()){
            while(!dq.empty() && dq.back() < nums[r]){
                dq.pop_back();
            }

            dq.push_back(nums[r]);

            if(r - l + 1 == k){
                ans.push_back(dq.front());
                if(nums[l] == dq.front()){
                    dq.pop_front();
                }
                l++;
            }
            r++;
        }
    return ans;
    }
};
