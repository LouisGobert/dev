/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */

function getId(arr) {
    return arr.map((i) => i.id);
}

function toDict(arr) {
    let dict = {};
    arr.forEach((element) => {
        dict[element.id] = element;
    });
    return dict;
}

function mergeSameId(ob1, ob2) {
    let r = { ...ob1 };
    r = { ...r, ...ob2 };
    return r;
}

var join = function (arr1, arr2) {
    // let = arr1Dict = toDict(arr1);
    let resultArray = [];
    let arr2Dict = toDict(arr2);

    let keySeenIfArr1 = new Set();
    arr1.forEach((item) => {
        if (item.id in arr2Dict) {
            resultArray.push(mergeSameId(item, arr2Dict[item.id]));
            keySeenIfArr1.add(item.id);
        } else {
            resultArray.push(item);
        }
    });

    resultArray.push(...arr2.filter((i) => !keySeenIfArr1.has(i.id)));
    resultArray.sort((a, b) => (a.id > b.id ? 1 : -1));

    return resultArray;
};

// console.log(
//     join(
//         [
//             { id: 1, x: 1 },
//             { id: 2, x: 9 },
//         ],
//         [{ id: 3, x: 5 }]
//     )
// );

console.log(
    join(
        [
            { id: 2, x: 3, y: 6 },
            { id: 1, x: 2, y: 3 },
        ],
        [
            { id: 2, x: 10, y: 20 },
            { id: 3, x: 0, y: 0 },
        ]
    )
);
// Output:
// [
//     {"id": 1, "x": 2, "y": 3},
//     {"id": 2, "x": 10, "y": 20},
//     {"id": 3, "x": 0, "y": 0}
// ]
