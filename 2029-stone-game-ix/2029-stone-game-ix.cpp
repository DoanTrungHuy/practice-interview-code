class Solution {
private:
    int n;
    
public:
    bool pick(int k, vector<int> cnt) {
        if (cnt[k] < 1) {
            return false;
        }
        cnt[k]--;
        int sum = k;
        for (int i = 1; i < n; ++i) {
            if (cnt[1] and (sum + 1) % 3 != 0) {
                cnt[1]--;
                sum += 1;
            }
            else if (cnt[2] and (sum + 2) % 3 != 0) {
                cnt[2]--;
                sum += 2;
            }
            else if (cnt[0] and (sum + 3) % 3 != 0) {
                cnt[0]--;
                sum += 3;
            }
            else {
                return i & 1;
            }
        }
        return false;
    }
    
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3);
        this->n = stones.size();
        for (int stone : stones) {
            cnt[stone % 3]++;
        }
        return pick(1, cnt) or pick(2, cnt);
    }
};