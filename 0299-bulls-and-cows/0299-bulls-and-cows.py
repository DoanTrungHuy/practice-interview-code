class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls = sum(s == g for s, g in zip(secret, guess))
        boths = Counter(secret) & Counter(guess)
        return str(bulls) + 'A' + str(sum(boths.values()) - bulls) + 'B'