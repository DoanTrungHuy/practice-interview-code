class Solution {
private:
    vector<int> ans;
    int limit;
    
public:
    void dfs(int num) {
        if (num > limit) {
            return;
        }
        ans.push_back(num);
        for (int suff = 0; suff <= 9; suff++) {
            dfs(num * 10 + suff);
        }
    }
    vector<int> lexicalOrder(int n) {
        limit = n;
        for (int num = 1; num <= 9; ++num) {
            dfs(num);
        }
        return ans;
    }
};