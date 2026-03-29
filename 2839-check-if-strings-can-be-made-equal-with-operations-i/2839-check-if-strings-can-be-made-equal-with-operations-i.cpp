class Solution {
public:
    bool canBeEqual(string s1, string s2) {
       if(s1 == s2)return true;
       string s3 = s2;
       string s4 = s2;
       swap(s3[2] , s3[0]);
       swap(s4[3] , s4[1]);
       string s5 = s2;
       swap(s5[2] , s5[0]);
       swap(s5[3] , s5[1]);
       if(s1 == s3 || s1 == s4 || s1 == s5)return true;

       return false;
          
    }
};