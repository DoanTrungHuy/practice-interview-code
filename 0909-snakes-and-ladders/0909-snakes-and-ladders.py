class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        arr, powN = [0], len(board)**2
        
        for idx, row in enumerate(board[::-1]):
            arr += row if not idx & 1 else row[::-1]
            
        dq, visited, move = deque([1]), set([1]), 0
        
        while dq:
            size = len(dq)
            for _ in range(size):
                square = dq.popleft()
                if square == powN:
                    return move
                for step in [1, 2, 3, 4, 5, 6]:
                    nextSquare = square + step
                    if nextSquare <= powN and nextSquare not in visited:
                        dq.append(nextSquare if arr[nextSquare] == -1 else arr[nextSquare])
                        visited.add(nextSquare)
            move += 1
            
        return -1