class Solution {
public:
    int characterReplacement(string s, int k) {
       vector<int>freq(26 , 0);
       int l = 0 , r = 0;
       int maxfreq = 0 , maxlength = 0;
       while(r<s.size()){
          freq[s[r] - 'A']++;
          maxfreq = max(maxfreq , freq[s[r] - 'A']);


          if((r - l + 1) - maxfreq > k){
            freq[s[l] - 'A']--;
            l++;
          } 

          maxlength = max(maxlength , r - l + 1);
          r++;
       }
       return maxlength;
    }
};
