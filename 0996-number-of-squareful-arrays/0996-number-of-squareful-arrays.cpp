class Solution {
private:
    vector<int> nums, path;
    unordered_map<int, int> cnt;
    int n, ans;
    
public:
    bool checkSquare(int num) {
        int s = sqrt(num);
        return num == s*s;
    }
    
    void dfs(int prev) {
        if (path.size() == n) {
            ans++;
            return;
        }
        for (auto &[key, _] : cnt) {
            if (cnt[key] > 0) {
                if (prev == -1 or checkSquare(prev + key)) {
                    cnt[key]--;
                    path.push_back(key);
                    dfs(key);
                    cnt[key]++;
                    path.pop_back();
                }
            }
        }
    }
    
    int numSquarefulPerms(vector<int>& nums) {
        n = nums.size(), ans = 0;
        this->nums = nums;
        for (int num : nums) {
            cnt[num]++;
        }
        dfs(-1);
        return ans;
    }
};