class Solution { 
public: 
    int shortestSequence(vector<int>& rolls, int k) { 
        int n = rolls.size(); 
        set<int> ss; 
        int ind = 0, ans = 1; 
        while(true) { 
            int cnt = 0, j = 0; 
            ss.clear(); 
            for(int i = ind; i < n; i++) { 
                if(ss.find(rolls[i]) != ss.end()) {
                    continue; 
                }
                else { 
                    ss.insert(rolls[i]); 
                    cnt++; 
                    j = max(j, i); 
                    if(ss.size() == k) {
                        break;
                    }
                } 
            } 
            if(cnt < k) {
                return ans; 
            }
            ind = j + 1; 
            ans++; 
        } 
    } 
};