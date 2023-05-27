class Solution {
private:
	vector<int> piles;
	int n;

public:
	int memo[501];

	int dp(int i) {
		if (i == n / 2) {
			return 0;
		}
		if (memo[i] != -1) {
			return memo[i];
		}
		int head = piles[i] + dp(i + 1);
		int tail = piles[n - 1 - i] + dp(i + 1);
		return memo[i] = max(head, tail);
	}
    bool stoneGame(vector<int>& piles) {
		this->piles = piles;
		this->n = piles.size();
		memset(memo, -1, sizeof(memo));
		int alice = dp(0);
		int total = 0;
		for (int i = 0; i < n; ++i) {
			total += piles[i];
		}
		return 2 * alice > total;
    }
};