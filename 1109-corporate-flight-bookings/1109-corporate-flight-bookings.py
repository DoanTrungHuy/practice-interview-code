class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        line = [0] * n
        
        for book in bookings:
            x = book[0]
            y = book[1]
            s = book[2]
            
            line[x - 1] += s
            if y < n:
                line[y] -= s
            
        for i in range(1, n):
            line[i] += line[i - 1]
            
        return line