/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const res = new Array(functions.length);
        let count = 0;
        functions.forEach((fn, i) => {
            fn().then(val => {
                res[i] = val;
                count++;
                if (count === functions.length) {
                    resolve(res);
                }
            }).catch(err => {
                reject(err);
            });
        });
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */