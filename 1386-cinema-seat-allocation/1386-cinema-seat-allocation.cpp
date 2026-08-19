class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> m;
        for (auto &c : reservedSeats) {
            m[c[0]].insert(c[1]);
        }
        int ans = 2 * n;
        for (auto &[row, seats] : m) {
            ans -= 2;
            bool left = true;   
            bool mid = true;    
            bool right = true;  
            for (int seat : seats) {
                if (seat >= 2 && seat <= 5)
                    left = false;

                if (seat >= 4 && seat <= 7)
                    mid = false;

                if (seat >= 6 && seat <= 9)
                    right = false;
            }

            if (left && right) {
                ans += 2;
            }
            else if (left || mid || right) {
                ans += 1;
            }
        }

        return ans;
    }
};