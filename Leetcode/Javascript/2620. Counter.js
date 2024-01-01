var createCounter = function (n) {
    this.n = n + 1;
    return function () {
        this.n += 1;
        return this.n;
    };
};

const counter = createCounter(10);
counter(); // 11
counter(); // 12
console.log(counter());
