class Solution {
public:
    string processStr(string s) {
        string ans ="";
        for(auto c:s){
            if(c == '%'){
                reverse(ans.begin() , ans.end());
            }else if(c == '#'){
                ans+=ans;
            }else if(c == '*'){
                if(!ans.empty()){
                    ans.pop_back();
                }
            }else{
                ans+=c;
            }
        }

        return ans;
    }
};