class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        busy = []
        available = [room for room in range(n)]
        freq = [0] * n
        meetings.sort()
        
        for start, end in meetings:
            while busy and busy[0][0] <= start:
                _, room = heappop(busy)
                heappush(available, room)
                
            if available:
                room = heappop(available)
                heappush(busy, (end, room))
            else:
                time, room = heappop(busy)
                heappush(busy, (time + end - start, room))
                
            freq[room] += 1
            
        return freq.index(max(freq))