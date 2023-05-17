/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
    let inProgressCount=0;
    let Index=0;
    return new Promise((resolve)=>{
    const EatFiveStarAndDoNothing=()=>{
          while(inProgressCount<n&&Index<functions.length)   
          {
                inProgressCount+=1;
                const promise=functions[Index]();   
                Index+=1;
                promise.then(()=>{
                        inProgressCount-=1;
                        EatFiveStarAndDoNothing();  
                });
          }
          if(inProgressCount==0&&Index==functions.length)
          {
             resolve();
             return ;
          }
    }
    EatFiveStarAndDoNothing(); 
    }); 
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */