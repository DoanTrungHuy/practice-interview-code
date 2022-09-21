class Solution:
    def defangIPaddr(self, address: str) -> str:
        ans = ""
        
        for char in address:
            if '0' <= char <= '9':
                ans += char
            else:
                ans += '[.]'
                
        return ans