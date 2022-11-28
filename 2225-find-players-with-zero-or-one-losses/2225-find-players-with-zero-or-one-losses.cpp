class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> um;
        set<int> us;
        for (vector<int> matche : matches) {
            int winner = matche[0];
            int loser = matche[1];
            us.insert(winner);
            us.insert(loser);
            um[loser]++;
        }
        vector<vector<int>> ans(2);
        for (int person : us) {
            if (um.find(person) != um.end()) {
                if (um[person] == 1) {
                    ans[1].push_back(person);
                }
            } else {
                ans[0].push_back(person);
            }
        }
        return ans;
    }
};