class Solution {
public:
    // vector<vector<vector<int>>>dp;
    // bool solve(string &s , string &t , int index1 , int cnt , int index2){
    //     if(index1 >= s.size()){
    //         return true;
    //     }

    //     if(index2 >= t.size()){
    //         return false;
    //     }

    //     if(dp[index1][index2][cnt] != -1){
    //         return dp[index1][index2][cnt];
    //     }

    //     // we have three options
       
    //     if(s[index1] != t[index2]){
    //         // we either replace this or we move the index2 to see if it exit forwaard;
    //         bool ans = solve(s , t , index1 , cnt , index2 + 1);
    //         if(cnt == 1){
    //              ans = ans || (solve(s , t , index1 + 1 , 0 , index2 + 1));
    //         }

    //         return dp[index1][index2][cnt] = ans;
    //     }
    //  return dp[index1][index2][cnt] = solve(s , t , index1 + 1 , cnt , index2 + 1) ||
    //      solve(s , t , index1 , cnt , index2 + 1);
    // }
    bool canMakeSubsequence(string s, string t) {
        // dp.resize(s.size() , vector<vector<int>>(t.size() , vector<int>(2, -1)));
        // int noreplace = 0;
        // int replace = 0;
        // for(auto c:t){
        //     int oldn = noreplace;
        //     int oldr = replace;

        //     if(oldr < s.size() && s[oldr] == c){
        //         replace = max(replace , oldr + 1);
        //     }


        //     if(oldn < s.size()){
        //         replace = max(replace , oldn + 1);
        //     }

        //     if(oldn < s.size() && s[oldn] == c){
        //         noreplace = oldn + 1;
        //     }
        // }

        // return max(noreplace , replace) == s.size();
        int n = s.size();
        int m = t.size();
        vector<int>prefix(n+1 , 1e9);
        int i=0,j=0;
        prefix[0] = -1;
        while(i<n && j<m){
           if(s[i] == t[j]){
               prefix[i+1] = j;
               i++;
           }
           j++;
        }
        
        vector<int>suffix(n+1, -1e9);
        i = n-1;
        j = m-1;
        suffix[n] = m; 
        while(i >= 0 && j>=0){
            if(s[i] == t[j]){
                suffix[i] = j;
                i--;
            }
            j--;
        }
        
        for(int k=0;k<n;k++){
            int left = prefix[k];
            int right = suffix[k+1];

            if(left != 1e9 && right!=-1e9 && right - left > 1){
               return true;
            }
        }
        return false;
    }
};