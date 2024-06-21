/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function (nums, fn, init) {
    let res = init;
    nums.forEach((n) => {
        res = fn(res, n);
    });
    return res;
};

let x = [1, 2, 3, 4];
let fn = function sum(accum, curr) {
    return accum + curr;
};
console.log(reduce(x, fn, 0));
