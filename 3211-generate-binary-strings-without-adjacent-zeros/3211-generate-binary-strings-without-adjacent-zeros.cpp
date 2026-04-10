class Solution {
public:
    vector<string>ans;
    void bsting(int n , string s , int last_index){
        if(s.size() == n){
            ans.push_back(s);
            return;
        }
        
      
        if(last_index == 0){
              bsting(n , s + '1' , 1);
        }else {
              bsting(n , s + '1' , 1);
              bsting(n , s + '0' , 0);
        }

        return;
    }
    vector<string> validStrings(int n) {
        bsting(n , "" , -1);
        return ans;
    }
};