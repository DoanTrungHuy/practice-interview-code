class Solution {
private:
    vector<int> nums;
    unordered_map<int, int> cnt;
    vector<int> path;
    vector<vector<int>> ans;
    int n;
    
public:
    void dfs() {
        if (path.size() == n) {
            ans.push_back(path);
            return;
        }
        for (auto &[key, _] : cnt) {
            if (cnt[key] > 0) {
                cnt[key]--;
                path.push_back(key);
                dfs();
                path.pop_back();
                cnt[key]++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        for (int num : nums) {
            cnt[num]++;
        }
        dfs();
        return ans;
    }
};