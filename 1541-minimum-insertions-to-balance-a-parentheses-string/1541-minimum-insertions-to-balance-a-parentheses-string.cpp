class Solution {
public:
    int minInsertions(string s) {
       int open = 0 , close = 0;
       int n = s.size();
       for(int i=0;i<s.size();i++){
          if(s[i] == '('){
             open++;
          }else if(s[i] == ')'){
             if(i+1 < n && s[i+1] == ')'){
                i++;
             }else{
                close++;
             } 

             if(open > 0){
                open--;
             }else{
                close++;
             }
          }
       }
       return open * 2 + close; 
    }
};