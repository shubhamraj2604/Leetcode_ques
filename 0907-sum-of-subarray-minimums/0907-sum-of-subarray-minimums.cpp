class Solution {
public:
    const int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
      int n = arr.size();
      vector<int>right(n ,n);
      stack<int>st;
      for(int i=n-1;i>=0;i--){
          while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
          }

          right[i] = st.empty() ? n : st.top();
          st.push(i);
      }  

      vector<int>left(n , -1);
      while(!st.empty()){
        st.pop();
      }
      for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }

        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
      }


      long long ans = 0;
      for(int i=0;i<n;i++){
        long long l = i - left[i];
         long long r = right[i] - i;
         ans=(ans + (((l * r) % mod)*arr[i]) % mod)% mod;
      }

      return ans;  
    }
};