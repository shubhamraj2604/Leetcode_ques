class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>lower(26 , 0);
        vector<int>upper(26 , 0);
        int cnt = 0;
        for(auto c:word){
            if(c>='A' && c<='Z'){
                upper[c - 'A'] = 1;
            }else{
                lower[c - 'a'] = 1;
            }
        }


        for(int i=0;i<26;i++){
            if(upper[i] && lower[i]){
                cnt++;
            }
        }
        return cnt;
    }
};