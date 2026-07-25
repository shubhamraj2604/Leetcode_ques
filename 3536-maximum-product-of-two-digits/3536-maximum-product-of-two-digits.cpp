class Solution {
public:
    int maxProduct(int n) {
       int f_max = -1;
       int s_max = -1;

       while(n!=0){
         int rev = n % 10;
         n/=10;
         if(rev > f_max){
            s_max = f_max;
            f_max = rev;
         }else if(rev > s_max){
            s_max = rev;
         }
       }

       return s_max * f_max; 
    }
};