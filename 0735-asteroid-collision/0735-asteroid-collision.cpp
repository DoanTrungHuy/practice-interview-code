class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (int asteroid : asteroids) {
            bool flag = false;
            while (!st.empty() and asteroid < 0 and st.top() > 0) {
                if (abs(st.top()) < abs(asteroid)) {
                    st.pop();
                    continue;
                }
                if (abs(asteroid) == abs(st.top())) {
                    st.pop();
                }

                flag = true;
                break;
            }
            
            if (!flag) {
                st.push(asteroid);
            }
        }
        
        vector<int> ans;
        
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};