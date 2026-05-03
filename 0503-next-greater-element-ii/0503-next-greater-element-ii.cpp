class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i = (n * 2) - 1;i>=0;i--){
            int idx = i % n;
             while(!st.empty() && nums[st.top()] <= nums[idx]){
                st.pop();
             }
             
             if(!st.empty())ans[idx] = nums[st.top()];
             if(idx < n){
                st.push(idx);
             }


        }

        return ans;
    }
};
