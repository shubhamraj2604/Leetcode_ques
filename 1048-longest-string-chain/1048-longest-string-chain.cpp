class Solution {
public:
    // this was taking O(N^2)
    // int lcs(string a , string b){
    //     int n = a.size();
    //     int m = b.size();

    //     vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0));

    //     for(int i=1;i<n+1;i++){
    //         for(int j=1;j<m+1;j++){
    //            if(a[i-1] == b[j-1]){
    //               dp[i][j] = 1 + dp[i-1][j-1];
    //            }else{
    //             dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
    //            }
    //         }
    //     }
    //     return dp[n][m];
    // }
    int lcs(const string& a, const string& b) {
        int i = 0;
        int j = 0;
        
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
            }
            j++;
        }
        return i; 
    }
    vector<vector<int>>t;
    int solve(vector<string>&words , int prev , int index){
       if(index>=words.size()){
         return 0;
       }

       if(t[index][prev + 1] != -1){
        return t[index][prev + 1];
       }

       int nottake = solve(words , prev , index + 1);
       int take = 0;
       string &b = words[index];
       if(prev == -1){
        take = 1 + solve(words , index , index + 1);
       }
       else if(words[prev].size() + 1 == b.size()){
          string &a = words[prev];
          // we were calling for N(words.size()) * O(sizeof(a*b));
          // we are visistimg evry index only once
          if(lcs(a , b) == a.size()){
            take = 1 + solve(words , index , index + 1);
          }
       }

       return t[index][prev + 1] = max(take , nottake);
    }
    int longestStrChain(vector<string>& words) {
          sort(words.begin(), words.end(), [](const string &a,  const string &b){
                return a.size() < b.size();
          });
          int n = words.size();
          t.resize(n , vector<int>(n+1 , -1));
          return solve(words , -1 , 0);
    }
};