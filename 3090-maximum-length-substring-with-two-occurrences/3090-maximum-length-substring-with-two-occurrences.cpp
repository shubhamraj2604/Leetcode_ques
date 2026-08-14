class Solution {
public:
    int maximumLengthSubstring(string s) {
       int l = 0 , r = 0;
       int n = s.size();
       int maxlength = 0;
       unordered_map<char,int>m;
       while(r<n){
          m[s[r]]++;
          while(m[s[r]] > 2){
            m[s[l]]--;
            if(m[s[l]] == 0){
                m.erase(s[l]);
            }
            l++;
          }
          maxlength = max(maxlength , r - l + 1);
          r++;
       }
       return maxlength;
    }
};