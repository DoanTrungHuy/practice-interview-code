class Solution:
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        adj = defaultdict(list)
        
        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)
            
        self.res = [0 for _ in range(n)]
        
        def dfs(node: int, parent: int) -> List[int]:
            cnt = [0 for _ in range(26)]
            
            for child in adj[node]:
                if child ^ parent:
                    cntChild = dfs(child, node)
                    for i in range(26):
                        cnt[i] += cntChild[i]
            
            cnt[ord(labels[node]) - ord('a')] += 1
            self.res[node] = cnt[ord(labels[node]) - ord('a')]
            
            return cnt
        
        dfs(0, -1)
        
        return self.res                   