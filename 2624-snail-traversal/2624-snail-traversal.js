/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(rowsCount, colsCount) {
    if (rowsCount*colsCount != this.length) {
        return [];
    }
    
    let result = Array(rowsCount).fill([]).map(() => []);
    let idx = 0;
    
    for (let j = 0; j < colsCount; ++j) {
        for (let i = 0; i < rowsCount; ++i) {
            if (j % 2 == 0) {
                result[i][j] = this[idx++];
            }
            else {
                result[rowsCount - 1 - i][j] = this[idx++];
            }
        }
    }
    
    return result;
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */