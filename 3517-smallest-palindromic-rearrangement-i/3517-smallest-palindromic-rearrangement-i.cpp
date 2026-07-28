class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        map<char,int>m;
        for(auto c:s){
            m[c]++;
        }
        string midd = "" , ans = "" , back = "";
        if(n % 2){
           char mid = s[n/2];
           m[mid]--;
           midd.push_back(mid);
           for(auto c:m){
               int cnt = c.second/2;
               ans.append(cnt , c.first);
               back.insert(back.begin() , cnt , c.first);
           }
        }else{
            for(auto c:m){
               int cnt = c.second/2;
               ans.append(cnt , c.first);
               back.insert(back.begin() , cnt , c.first);
           }
        }

        return ans + midd + back;
    }
};