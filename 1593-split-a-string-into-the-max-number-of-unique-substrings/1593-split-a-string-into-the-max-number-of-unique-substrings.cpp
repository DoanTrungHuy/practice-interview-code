struct TrieNode {
    bool is_word;
    TrieNode *child[26];
    
    TrieNode() {
        is_word = false;
        memset(child, 0, sizeof child);
    }
};

class Solution {
private:
    TrieNode *root;
    int n;
    
public:
    int dfs(string &s, int i) {
        if (i == n) {
            return 0;
        }
        
        int ans = 0;
        TrieNode *curr = root;
        
        for (int j = i; j < n; ++j) {
            int index = s[j] - 'a';
            
            if (!curr->child[index]) {
                curr->child[index] = new TrieNode();
            }
            
            curr = curr->child[index];
            
            if (!curr->is_word) {
                curr->is_word = true;
                ans = max(ans, 1 + dfs(s, j + 1));
                curr->is_word = false;
            }
        }
        
        return ans;
    }
    
    int maxUniqueSplit(string s) {
        root = new TrieNode();
        this->n = s.size();
        return dfs(s, 0);
    }
};