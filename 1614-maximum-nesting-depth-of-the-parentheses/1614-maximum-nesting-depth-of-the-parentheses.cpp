class Solution {
public:
    int maxDepth(string s) {
        int maxlength = 0;
        int cnt = 0;
        for(auto c:s){
            if(c == '('){
                cnt++;
            }else if(c == ')'){
                cnt--;
            }

            maxlength = max(maxlength , cnt);
        }
        return maxlength;
    }
};