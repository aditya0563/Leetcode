/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    if (n === 0) return arr;
    
    const result = [];
    
    function flatten(currentArr, depth) {
        for (const item of currentArr) {
            if (Array.isArray(item) && depth < n) {
                flatten(item, depth + 1);
            } else {
                result.push(item);
            }
        }
    }
    
    flatten(arr, 0);
    return result;
};