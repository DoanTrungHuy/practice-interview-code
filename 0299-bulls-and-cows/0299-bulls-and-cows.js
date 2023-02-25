/**
 * @param {string} secret
 * @param {string} guess
 * @return {string}
 */

var getHint = function(secret, guess) {
    let cntS = Array(10).fill(0), cntG = Array(10).fill(0);
    
    for (let i = 0; i < 10; ++i) {
        cntS[i] = 0;
        cntG[i] = 0;
    }
    
    let n = secret.length;
    let bulls = 0, cows = 0;
    
    for (let i = 0; i < n; ++i) {
        if (secret[i] == guess[i]) {
            bulls++;
        }
        else {
            cntS[secret[i] - '0']++;
            cntG[guess[i] - '0']++;
        }
    }
    
    for (let i = 0; i < 10; ++i) {
        cows += Math.min(cntS[i], cntG[i]);
    }
    
    return `${bulls}A${cows}B`;
};