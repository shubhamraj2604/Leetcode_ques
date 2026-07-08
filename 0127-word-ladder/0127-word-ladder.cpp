class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         // string , cnt
         // beginWord , 1
         //
         set<string>s(wordList.begin() , wordList.end());
        if(beginWord == endWord)return 0;
         queue<pair<string , int>>q;
         q.push({beginWord , 1});

         while(!q.empty()){
            string x = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if(x == endWord){
                return cnt;
            }

            for(int i=0;i<x.size();i++){
                char m = x[i];
                for(char c ='a' ; c<='z';c++){
                    x[i] = c;
                    if(s.count(x)){
                        q.push({x , cnt + 1});
                        s.erase(x);
                    }
                }
                x[i] = m;
            }
         }

         return 0;
    }
};