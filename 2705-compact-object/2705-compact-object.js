/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if (obj === null || typeof obj !== 'object') {
        return obj;
    }

    if (Array.isArray(obj)) {
        const result = [];
        for (const item of obj) {
            if (Boolean(item)) {
                result.push(compactObject(item));
            }
        }
        return result;
    }

    const result = {};
    for (const key in obj) {
        if (Boolean(obj[key])) {
            result[key] = compactObject(obj[key]);
        }
    }
    return result;
};