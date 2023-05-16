var timeLimit = function(fn, t) {
	return async function(...args) {
           const originalPromise=fn(...args);
           const rejectPromise=new Promise((resolve,reject)=>{setTimeout(()=>{
               reject("Time Limit Exceeded")
           },t);
           });
          return Promise.race([originalPromise,rejectPromise]);  
    }
};