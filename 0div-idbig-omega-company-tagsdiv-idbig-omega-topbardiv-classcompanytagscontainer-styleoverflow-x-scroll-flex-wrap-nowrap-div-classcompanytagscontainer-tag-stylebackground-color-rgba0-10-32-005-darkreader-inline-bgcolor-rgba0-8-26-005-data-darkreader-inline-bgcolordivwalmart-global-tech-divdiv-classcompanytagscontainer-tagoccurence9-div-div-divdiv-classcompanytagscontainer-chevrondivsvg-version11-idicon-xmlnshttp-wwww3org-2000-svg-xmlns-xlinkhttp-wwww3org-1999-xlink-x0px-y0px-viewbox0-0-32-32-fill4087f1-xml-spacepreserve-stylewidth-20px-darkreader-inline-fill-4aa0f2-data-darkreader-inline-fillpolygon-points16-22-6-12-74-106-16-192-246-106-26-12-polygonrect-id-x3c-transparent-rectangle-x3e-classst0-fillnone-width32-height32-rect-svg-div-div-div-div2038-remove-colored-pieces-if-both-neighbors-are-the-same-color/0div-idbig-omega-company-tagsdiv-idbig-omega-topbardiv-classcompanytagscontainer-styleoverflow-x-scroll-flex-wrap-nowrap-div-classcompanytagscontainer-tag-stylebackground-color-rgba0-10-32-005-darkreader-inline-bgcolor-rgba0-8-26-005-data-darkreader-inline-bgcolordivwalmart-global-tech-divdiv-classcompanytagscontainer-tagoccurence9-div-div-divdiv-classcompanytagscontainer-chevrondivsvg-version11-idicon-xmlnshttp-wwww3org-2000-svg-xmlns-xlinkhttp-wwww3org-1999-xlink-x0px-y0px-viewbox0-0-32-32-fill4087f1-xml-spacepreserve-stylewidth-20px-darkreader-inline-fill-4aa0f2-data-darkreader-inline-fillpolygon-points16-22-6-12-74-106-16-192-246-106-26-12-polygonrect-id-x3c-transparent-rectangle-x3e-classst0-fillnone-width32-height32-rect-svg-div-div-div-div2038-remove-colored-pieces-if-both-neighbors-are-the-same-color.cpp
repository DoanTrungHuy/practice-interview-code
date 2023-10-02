class Solution {
public:
    bool winnerOfGame(string colors) {
        char c = 'C';
        int cur[2] = {0, 0};
        int cnt[2] = {0, 0};
        
        for (char c : colors) {
            if (c == 'A') {
                cur[0] += 1;
                cur[1] = 0;
                cnt[0] += cur[0] >= 3;
            }
            else {
                cur[1] += 1;
                cur[0] = 0;
                cnt[1] += cur[1] >= 3;
            }
        }
        
        return cnt[0] > cnt[1];
    }
};