class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    
public:
    void dfs(int i, int k, int n) {
        if (n <= 0) {
            if (n == 0 and k == 0) {
                ans.push_back(tmp);
            }
            return;
        }
        for (int j = i; j <= 9; ++j) {
            tmp.push_back(j);
            dfs(j + 1, k - 1, n - j);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return ans;
    }
};