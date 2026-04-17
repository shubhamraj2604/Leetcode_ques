class Solution {
public:

    int getlps(string temp){
        int n = temp.size();
        int len = 0;
        vector<int>lps(n, 0);
        for(int i=1;i<n;i++){
            while(len > 0 && temp[i] != temp[len]){
                len = lps[len - 1];
            }

            if(temp[i] == temp[len]){
                len++;
                lps[i] = len;
            }
        }
        return lps[n-1];
    }
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin() , t.end());

        string temp = s + '#' + t;
        int lps = getlps(temp);
        cout<<lps<<endl;
        int l = s.size() - lps;
        string ans = t.substr(0, l) + s;

        return ans;
    }
};