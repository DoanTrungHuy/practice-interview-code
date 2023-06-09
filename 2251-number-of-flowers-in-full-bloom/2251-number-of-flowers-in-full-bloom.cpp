class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> line;
        
        for (vector<int> flower : flowers) {
            int start = flower[0], end = flower[1];
            line[start]++;
            line[end + 1]--;
        }
        
        line[0] = 0;
        int sum = 0;
        
        for (auto &[position, flower] : line) {
            sum += flower;
            flower = sum;
        }
        
        vector<int> ans;
        
        for (int member : people) {
            auto index = line.upper_bound(member);
            index--;
            ans.push_back(index->second);
        }
        
        return ans;
    }
};