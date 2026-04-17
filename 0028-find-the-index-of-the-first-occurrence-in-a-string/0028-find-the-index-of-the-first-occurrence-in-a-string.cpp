class Solution {
public:
    vector<int> lps1(string s){
        vector<int>lps(s.size() , 0);
        int len = 0;
        int n = s.size();
        for(int i=1;i<n;i++){
            while(len > 0 && s[i] != s[len]){
                  len = lps[len - 1];
            }

            if(s[i] == s[len]){
                len++;
                lps[i] = len;
            }
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        
        // int size=needle.size();
        // if(haystack.size()<needle.size()){
        //     return -1;
        // }

        // for(int i=0;i<haystack.size()-(size-1);i++){
        //     string t=haystack.substr(i,size);
        //     if(t==needle){
        //         return i;
        //     }
        // }

        // return -1;
        int n = needle.size();
        vector<int>lps = lps1(needle); 
        int pre = 0 , suf = 0;
        int len = 0;
        while(pre < needle.size() && suf < haystack.size()){
            if(haystack[suf] == needle[pre]){
                pre++;
                suf++;
                if(pre == needle.size()){
                return suf - pre;
            }
            }else{
                if(pre == 0){
                  suf++; 
                }else{
                    pre = lps[pre - 1];
                }
            }

        }
    return -1;
    }
};