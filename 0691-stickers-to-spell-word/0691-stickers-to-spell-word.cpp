class Solution {
private:
    vector<string> stickers;
    string target;
    vector<vector<int>> freq_char_of_stickers;
    int n, m, goal;
    
public:
    const int OVER_SIZE = 51;
    int memo[50][1 << 15];
    
    int dp(int i, int mask) {
        if (mask == goal) {
            return 0;
        }
        
        if (i == n) {
            return OVER_SIZE;
        }
        
        if (memo[i][mask] != -1) {
            return memo[i][mask];
        }
        
        vector<int> fcos = freq_char_of_stickers[i];
        
        int nextMask = mask;
        
        for (int j = 0; j < m; ++j) {
            if ((nextMask & (1 << j)) == 0 and fcos[target[j] - 'a']) {
                nextMask ^= (1 << j);
                fcos[target[j] - 'a']--;
            }
        }
        
        int not_next_step = OVER_SIZE;
        
        if (nextMask != mask) {
            not_next_step = 1 + dp(i, nextMask);
        }
        
        return memo[i][mask] = min(dp(i + 1, mask), not_next_step);
    }
    
    int minStickers(vector<string>& stickers, string target) {
        memset(memo, -1, sizeof(memo));
        
        this->stickers = stickers;
        this->target = target;
        n = stickers.size();
        m = target.size();
        goal = (1 << m) - 1;
        
        for (string sticker : stickers) {
            vector<int> freq(26, 0);
            
            for (char c : sticker) {
                freq[c - 'a']++;
            }
            
            freq_char_of_stickers.push_back(freq);
        }
        
        return dp(0, 0) < OVER_SIZE ? dp(0, 0) : -1;
    }
};