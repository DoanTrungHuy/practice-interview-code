function isUgly(n: number): boolean {
    if (n <= 0) {
        return false;
    }
    for (let ele of [2, 3, 5]) {
        while (n % ele == 0) {
            n /= ele
        }
    }
    return n == 1
};