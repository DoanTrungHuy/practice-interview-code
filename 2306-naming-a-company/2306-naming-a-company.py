class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        s = [set() for _ in range(26)]
        ideas = set(ideas)
        
        for idea in ideas:
            s[ord(idea[0]) - ord('a')].add(idea[1:])
            
        ans = 0
            
        for i in range(25):
            for j in range(i + 1, 26):
                dup = len(s[i] & s[j])
                ans += 2 * (len(s[i]) - dup) * (len(s[j]) - dup)
                
        return ans