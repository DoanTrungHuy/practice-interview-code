class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        dq = deque([start])
        visited = set([start])
        step = 0
        bank = set(bank)
        
        while dq:
            n = len(dq)
            for _ in range(n):
                gene = dq.popleft()
                if gene == end:
                    return step
                visited.add(gene)
                m = len(gene)
                gene = list(gene)
                for i in range(m):
                    tmp = gene[i]
                    for char in 'ACGT':
                        gene[i] = char
                        dummy = ''.join(gene)
                        if dummy in bank and dummy not in visited:
                            dq.append(dummy)
                    gene[i] = tmp
                    
            step += 1
            
        return -1