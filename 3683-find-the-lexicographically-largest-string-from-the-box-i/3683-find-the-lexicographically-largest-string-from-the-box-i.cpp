class Solution { 
public: 
    string answerString(string word, int numFriends) { 
        const int n = word.size(); 
        
        if (numFriends == 1) {
            return word;
        }
        
        char max_char = '0';
        
        for (char c : word) {
            max_char = max(max_char, c);
        }
        
        string ans = ""; 

        for (int i = 0; i < n; ++i) { 
            if (word[i] != max_char) { 
                continue;
            } 
            int max_len = min(n - i, n - numFriends + 1); 
            string tmp = word.substr(i, max_len); 
            if (tmp > ans) { 
                ans = tmp;
            } 
        }
        
        return ans; 
    } 
};
