/**
 * @param {Function} fn
 * @return {Function}
 */
var curry = function(fn) {
    return function curried(...args) {
        if (fn.length == args.length) {
            return fn(...args);
        }
        return function(...newArgs) {
            return curried(...args, ...newArgs);
        }
    };
};

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */
