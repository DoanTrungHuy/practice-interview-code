/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let ans = [];
    let n = arr.length;
    
    for (let i = 0; i < n; ++i) {
        ans.push(fn(arr[i], i));
    }
    
    return ans;
};