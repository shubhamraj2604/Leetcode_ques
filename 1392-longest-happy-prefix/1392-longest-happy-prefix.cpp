class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0);
        int len = 0;

        // for (int i = 1; i < n; i++) {
        //     while (len > 0 && s[i] != s[len]) {
        //         len = lps[len - 1];
        //     }
        //     if (s[i] == s[len]) {
        //         len++;
        //         lps[i] = len;
        //     }
        // }
        int pre = 0 , suf = 1;

        while(suf < s.size()){

            if(s[suf] == s[pre]){
                lps[suf] = pre + 1;
                suf++;
                pre++;
            }else {
                if(pre <= 0){
                    lps[suf] = 0;
                    suf++;
                }else{
                    pre = lps[pre - 1];
                }
            }
        }
        return s.substr(0, lps[n - 1]);
    }
};
