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
    int ans;
    
public:
    void dfs(string &s, int i, int l) {
        if (n - i + l <= ans) {
            return;
        }
        
        if (i == n) {
            ans = max(ans, l);
            return;
        }
        
        TrieNode *curr = root;
        
        for (int j = i; j < n; ++j) {
            int c = s[j] - 'a';
            
            if (!curr->child[c]) {
                curr->child[c] = new TrieNode();
            }
            
            curr = curr->child[c];
            
            if (!curr->is_word) {
                curr->is_word = true;
                dfs(s, j + 1, l + 1);
                curr->is_word = false;
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        ans = 0;
        root = new TrieNode();
        this->n = s.size();
        dfs(s, 0, 0);
        return ans;
    }
};