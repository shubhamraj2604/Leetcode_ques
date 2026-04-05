class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int>row;
            for(int j = 0 ; j<=i ; j++){
                if(j == 0 || j == i){
                    row.push_back(1);
                }else{
                    int sum = ans[i-1][j] + ans[i-1][j-1];
                    row.push_back(sum);
                }
            }
            ans.push_back(row);
        }

        return ans;

    }
};