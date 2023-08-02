class Solution {
private:
    vector<int> path, nums;
    vector<bool> visited;
    vector<vector<int>> ans;
    int n;
    
public:
    void dfs(int cnt) {
        if (cnt == n) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                path.push_back(nums[i]);
                visited[i] = true;
                dfs(cnt + 1);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        this->n = nums.size();
        visited.resize(n, false);
        this->nums = nums;
        dfs(0);
        return ans;
    }
};