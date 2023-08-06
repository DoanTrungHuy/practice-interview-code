int memo[101][101];
const int MOD = 1e9 + 7;

class Solution {
private:
    int n, k;
    
public:
    int dp(int old_song, int goal) {
        if (goal == 0) {
            return old_song == n;
        }
        if (memo[old_song][goal] != -1) {
            return memo[old_song][goal];
        }
        long long ans = (1LL*dp(old_song + 1, goal - 1) * max(n - old_song, 0)) % MOD;
        ans = (ans + 1LL*dp(old_song, goal - 1) * max(old_song - k, 0)) % MOD;
        return memo[old_song][goal] = ans;
    }
    
    int numMusicPlaylists(int n, int goal, int k) {
        memset(memo, -1, sizeof(memo));
        this->n = n;
        this->k = k;
        return dp(0, goal);
    }
};