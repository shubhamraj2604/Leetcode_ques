class Solution {
public:
    void nse(vector<int>&right_min , vector<int>&left_min , int n , vector<int>arr){
      stack<int>st;
      for(int i=n-1;i>=0;i--){
          while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
          }

          right_min[i] = st.empty() ? n : st.top();
          st.push(i);
      }  
      while(!st.empty()){
        st.pop();
      }
      for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }

        left_min[i] = st.empty() ? -1 : st.top();
        st.push(i);
      }
    }
    void nge(vector<int>&right_max , vector<int>&left_max , int n , vector<int>arr){
      stack<int>st;
      for(int i=n-1;i>=0;i--){
          while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
          }

          right_max[i] = st.empty() ? n : st.top();
          st.push(i);
      }  

      vector<int>left(n , -1);
      while(!st.empty()){
        st.pop();
      }
      for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            st.pop();
        }

        left_max[i] = st.empty() ? -1 : st.top();
        st.push(i);
      }
    }
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;
        //O(n^2) 
        // not optimal
        // for(int i=0;i<nums.size();i++){
        //     int smallest=nums[i];
        //     int largest=nums[i];

        //     for(int j=i+1;j<nums.size();j++){
        //         largest=max(largest,nums[j]);
        //         smallest=min(smallest,nums[j]);

        //         sum+=largest-smallest;
        //     }
        // }
        long long ans = 0;
        int n = nums.size();
        vector<int>left_max(n , -1) , right_max(n , n);
        nge(right_max , left_max , n , nums);
        vector<int>left_min(n , -1) , right_min(n , n);
        nse(right_min , left_min , n , nums);
        for(int i=0;i<n;i++){
           long long mincnt = 1LL * (i - left_min[i]) * (right_min[i] - i);
           long long maxcnt = 1LL * (i - left_max[i]) * (right_max[i] - i);
           ans+=1LL * nums[i] * (maxcnt - mincnt);
        }
        return ans;
    }
};