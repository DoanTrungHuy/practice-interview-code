/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let num = init;
    
    function increment() {
        return ++num;
    }
    
    function decrement() {
        return --num;
    }
    
    function reset() {
        return num = init;
    }
    
    return { increment, reset, decrement };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */