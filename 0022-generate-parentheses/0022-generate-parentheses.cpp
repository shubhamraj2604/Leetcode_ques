class Solution {
public:
    vector<string>ans;
    // last = 1 -> open;
    // last = 2 -> closed;
    void solve(string &s , int open , int close , int size){
        if(s.size() == 2*size){
           ans.push_back(s);
           return;
        }


        if(open < size){
            s.push_back('(');
            solve(s, open + 1 , close , size);
            s.pop_back();
        }

        if(close < open){
            s.push_back(')');
            solve(s, open , close + 1 , size);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
       string s = "";
       solve(s , 0 , 0 , n);
       return ans;
    }
};