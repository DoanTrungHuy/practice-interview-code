class Solution {
private:
    vector<vector<int>> ans;
    int n;
    int sum = 0;
    
public:
    void backTracking(vector<int>& candidates, int target, vector<int> path, int i) {
        if (target < sum) {
            return;
        }
        if (target == sum) {
            ans.push_back(path);
            return;
        }
        for (int j = i; j < n; ++j) {
            path.push_back(candidates[j]);
            sum += candidates[j];
            backTracking(candidates, target, path, j);
            sum -= candidates[j];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->n = candidates.size();
        backTracking(candidates, target, {}, 0);
        return ans;
    }
};