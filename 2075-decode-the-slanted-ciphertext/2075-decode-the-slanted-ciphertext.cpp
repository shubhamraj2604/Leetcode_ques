class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int col = n / rows;
        vector<vector<char>>s(rows , vector<char>(col , ' '));
        int idx = 0;
        for(int i=0;i<rows;i++){
            for(int j = 0 ;j<col;j++){
                s[i][j] = encodedText[idx];
                idx++;
            }
        }
        string ans = "";
        for(int j=0;j<col;j++){
            int i=0 , k = j;
            while(i<rows && k<col){
                 ans+=s[i][k];
                 i++;
                 k++;
            }
        }

        while(!ans.empty() && ans.back() == ' '){
            ans.pop_back();
        }
     
        return ans;
    }
};