class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         unordered_set<string>s(wordList.begin() , wordList.end());

         queue<pair<string,int>>q;
         q.push({beginWord , 0});
         s.erase(beginWord);


         while(!q.empty()){
            string w = q.front().first;
            int steps = q.front().second;

            q.pop();

            if(w == endWord){
                return steps + 1;
            }

            for(int i=0;i<w.size();i++){
                char o = w[i];
                for(char x = 'a' ; x<='z';x++){
                    w[i] = x;
                    if(s.count(w)){
                        q.push({w , steps + 1});
                        s.erase(w);
                    }   
                }
                w[i] = o;
            }
         }
         return 0;
    }
};