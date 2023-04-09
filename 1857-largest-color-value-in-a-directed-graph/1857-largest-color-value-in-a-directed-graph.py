class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        N = len(colors)                                     
        incoming, Graph = [0]*N, [[] for _ in range(N)]     
        for _, v in edges: incoming[v]+=1                   
        for u, v in edges: Graph[u].append(v)               
        stack = [u for u in range(N) if incoming[u]==0]     
        cnts = [[0]*26 for _ in range(N)]                    

        while stack:                                        
            u = stack.pop()                                 
            cnts[u][ord(colors[u])-ord('a')] += 1           
            for v in Graph[u]:                              
                cnts[v] = list(map(max, cnts[v], cnts[u]))  
                incoming[v] -= 1                            
                if incoming[v]==0: stack.append(v)          

        return -1 if sum(incoming)>0 else max([max(node) for node in cnts])