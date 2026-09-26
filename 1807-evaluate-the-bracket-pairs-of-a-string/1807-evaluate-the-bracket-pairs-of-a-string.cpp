class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string , string>m;
        for(auto c:knowledge){
            m[c[0]] = c[1];
        }
        string ans = "";
        string temp = "";
        int prev = 0;
        for(auto c:s){
           if(c == '('){
              prev = 1;
           }else if(prev == 1){
             if(c ==')'){
                if(m.count(temp)){
                    ans+=m[temp];
                }else{
                    ans+="?";
                }
                prev = 0;
                temp="";
             }else{
             temp+=c;
             }
           }else{
            ans+=c;
           }
        }
        return ans;
    }
};