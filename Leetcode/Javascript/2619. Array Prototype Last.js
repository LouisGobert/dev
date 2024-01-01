/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function () {
    const r = this.length === 0 ? -1 : this[this.length - 1];
    return r;
};

const arr = [];
console.log(arr.last()); // 3
