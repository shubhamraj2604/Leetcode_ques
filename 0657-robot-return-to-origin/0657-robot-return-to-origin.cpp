class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0;
        int v = 0;
        for(auto c:moves){
            if(c == 'U'){
                v++;
            }else if(c == 'D'){
                v--;
            }else if(c == 'L'){
                h++;
            }else{
                h--;
            }
        }
        return (v == 0) && (h==0);
    }
};