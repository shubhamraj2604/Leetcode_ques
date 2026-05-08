class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //find the next greatest smaller to thr left and right
        int n = heights.size();
        vector<int>right(n, n);
        vector<int>left(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
           while(!st.empty() && heights[st.top()] >= heights[i]){
               st.pop();
           }
            right[i] = st.empty() ? n : st.top();
          
          st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

         for(int i=0;i<n;i++){
           while(!st.empty() && heights[st.top()] > heights[i]){
               st.pop();
           }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans , (right[i] - left[i] - 1) * heights[i]);
        }

        return ans;
    }
};
