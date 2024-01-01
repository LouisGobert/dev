function createCounter(n) {
    this.n = n;
    return function () {
        this.n += 1;
        return this.n;
    };
}
var counter = createCounter(10);
counter(); // 11
counter(); // 12
console.log(counter());
//# sourceMappingURL=2620.%20Counter.js.map