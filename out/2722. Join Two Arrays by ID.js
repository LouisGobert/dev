/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
function getId(arr) {
    return arr.map(function (i) { return i.id; });
}
function mergeSameId(arr1, arr2, sameId) { }
var join = function (arr1, arr2) {
    var idArr1 = new Set(arr1);
    var idArr2 = new Set(arr2);
    var sameId = idArr1.intersection(idArr2);
};
//# sourceMappingURL=2722.%20Join%20Two%20Arrays%20by%20ID.js.map