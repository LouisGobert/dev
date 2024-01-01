/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function (arr, fn) {
    let filtered = [];
    arr.forEach((value, index) => {
        if (fn(value, index)) {
            filtered.push(value);
        }
    });
    return filtered;
};
