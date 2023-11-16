class Solution {
private:
    int n;
    unordered_set<string> us;
    
public:
    string dfs(int i, string path) {
        if (i == n) {
            return (!us.count(path)) ? path : "";
        }
        for (int j = 0; j < 2; ++j) {
            string t = dfs(i + 1, path + to_string(j));
            if (t != "") {
                return t;
            }
        }
        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for (string num : nums) {
            us.insert(num);
        }
        n = nums[0].size();
        return dfs(0, "");
    }
};