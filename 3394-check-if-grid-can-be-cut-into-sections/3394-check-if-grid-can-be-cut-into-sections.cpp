class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        auto isValid = [&](int ax) -> bool {
            vector<pair<int, int>> events;
            
            for (auto& rect : rectangles) {
                if (ax == 0) {
                    events.push_back({rect[0], 1}); 
                    events.push_back({rect[2], -1}); 
                } 
                else { 
                    events.push_back({rect[1], 1}); 
                    events.push_back({rect[3], -1});
                }
            }

            sort(events.begin(), events.end());

            int line = 0, div = 0;

            for (auto [_, val] : events) {
                line += val;
                
                if (line == 0) {
                    div++;
                }
            }
            

            return div >= 3;
        };
        
        return isValid(0) || isValid(1);
    }
};
