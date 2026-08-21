/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    const map = new Map();

    for (const item of arr1) {
        map.set(item.id, { ...item });
    }

    for (const item of arr2) {
        if (map.has(item.id)) {
            map.set(item.id, { ...map.get(item.id), ...item });
        } else {
            map.set(item.id, { ...item });
        }
    }

    return Array.from(map.values()).sort((a, b) => a.id - b.id);
};