class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        unordered_map<char,int>m;
        int l = 0 , r=0;

        while(r<s.size()){
            m[s[r]]++;
            while(m['a'] > 0 && m['b'] > 0 && m['c'] > 0){
                // if abc is staisfied so will be abca , abcabc , etc
                // abc when r = 2 , s.size() = 6
                // this says the remaining 3 elements will also be satisfied bcoz they will   also have one occurence of abc
                // cnt = 4 bcoz they are 3 elements that left and including the abc gives 4
                // if you found one occurence of abc then every otherb after this will be satisfied.
                cnt+=s.size() - r;
                m[s[l]]--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};