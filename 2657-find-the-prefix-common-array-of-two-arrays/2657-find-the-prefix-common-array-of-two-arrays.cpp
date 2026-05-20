class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>freq(n+1 , 0);
        vector<int>ans;
        for(int i = 0;i<A.size();i++){
                freq[A[i]]++;
                int cnt = 0;
           for(int j=0;j<=i;j++){
              cnt+=freq[B[j]];
           }
           ans.push_back(cnt);
        }

        return ans;
    }
};