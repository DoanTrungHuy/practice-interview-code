class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1, q2;
        int n = senate.size();
        
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') {
                q1.push(i);
            }
            else {
                q2.push(i);
            }
        }
        
        while (!q1.empty() and !q2.empty()) {
            int idx1 = q1.front();
            q1.pop();
            int idx2 = q2.front();
            q2.pop();
            
            if (idx1 < idx2) {
                q1.push(idx1 + senate.size());
            }
            else {
                q2.push(idx2 + senate.size());
            }
        }
        
        return q1.empty() ? "Dire" : "Radiant";
    }
};