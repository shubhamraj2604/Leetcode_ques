class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (!st.empty()) {
                    result += s[i];
                }
                st.push(s[i]);
            } 
            else if (s[i] == ')') {
                st.pop();
                if (!st.empty()) {
                    result += s[i];
                }
            }
        }
        return result;
    }
};
