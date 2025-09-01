class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> us;

        for (int f : friends) {
            us.insert(f);
        }

        vector<int> ans;

        for (int o : order) {
            if (us.count(o)) {
                ans.push_back(o);
            }
        }

        return ans;
    }
};