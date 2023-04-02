function lowerBound(potions: number[], success: number): number {
    const n = potions.length;
    let left = 0, right = n - 1;
    let ans = n;
    
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        
        if (potions[mid] < success) {
            left = mid + 1;
        }
        else {
            ans = mid;
            right = mid - 1;
        }
    }
    
    return ans;
}

function successfulPairs(spells: number[], potions: number[], success: number): number[] {
    potions.sort((a, b) => a - b);
    const n = potions.length;
    return spells.map(
        (spell) => n - lowerBound(potions, Math.ceil(success / spell))
    );
};