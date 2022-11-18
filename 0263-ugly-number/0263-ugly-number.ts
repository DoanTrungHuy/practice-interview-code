function isUgly(n: number): boolean {
    for (let ele of [2, 3, 5]) {
        while (n % ele == 0 && n > 1) {
            n /= ele
        }
    }
    return n == 1
};