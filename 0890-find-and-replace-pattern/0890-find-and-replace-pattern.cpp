class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(auto c:words){
            unordered_map<char,char>a;
            unordered_map<char,char>b;
            bool f = true;
            for(int i=0;i<c.size();i++){
                if(a.count(c[i]) && a[c[i]] != pattern[i]){
                    f = false;
                    break;
                }

                if(b.count(pattern[i])  && b[pattern[i]] != c[i]){
                    f = false;
                    break;
                }

                a[c[i]] = pattern[i];
                b[pattern[i]] = c[i];
            }
            if(f)ans.push_back(c);
        }

        return ans;
    }
};