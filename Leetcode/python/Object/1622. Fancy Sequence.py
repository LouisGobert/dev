from collections import namedtuple
from typing import List, NamedTuple, Tuple

MODULO = 10**9 + 7


class Fancy:
    arr: List[int]

    cum_add_ops: List[int]
    cum_mul_ops: List[int]

    def __init__(self):
        self.cum_add_ops = []
        self.cum_mul_ops = []
        self.arr = []

    def append(self, val: int) -> None:
        self.arr.append(val)

        if len(self.arr) == 1:
            self.cum_add_ops.append(0)
            self.cum_mul_ops.append(1)
            return

        self.cum_add_ops.append(self.cum_add_ops[-1])
        self.cum_mul_ops.append(self.cum_mul_ops[-1])

    def addAll(self, inc: int) -> None:
        if len(self.arr) == 0:
            return
        self.cum_add_ops[-1] += inc

    def multAll(self, m: int) -> None:
        if len(self.arr) == 0:
            return
        self.cum_add_ops[-1] *= m
        self.cum_mul_ops[-1] *= m

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.arr):
            return -1

        # (a*b)+c
        # (2*3) + 5 = 11
        """
        11 = start number
        2 = (11 - 5) / 3
        
        10 mul
        add 6
        
        26 = (2 * 10) + 6
        == ( ( (11-5) / 3 ) * 10 ) + 6  
        
        11, 5, 3, 2, 10, 6
        26 = 
        
        ---------------
        val = (12 - 4541248) / 4064256
        val = (val * 51197920542720000) + 
        
        """

        val = self.arr[idx]

        if idx == 0:
            val = (val * self.cum_mul_ops[-1]) + self.cum_add_ops[-1]
        else:
            # val = (val / self.cum_mul_ops[idx - 1]) - self.cum_add_ops[idx - 1]
            val = (
                ((val - self.cum_add_ops[idx - 1]) / self.cum_mul_ops[idx - 1]) * self.cum_mul_ops[-1]
            ) + self.cum_add_ops[-1]
        return round(val) % (10**9 + 7)


# Your Fancy object will be instantiated and called as such:
# obj = Fancy()

# param_4 = obj.getIndex(idx)
if __name__ == "__main__":
    obj = Fancy()

    obj.addAll(5)
    assert obj.getIndex(0) == -1

    obj = Fancy()
    obj.append(2)
    obj.addAll(3)
    obj.append(7)
    obj.multAll(2)
    assert obj.getIndex(0) == 10
    obj.addAll(3)
    obj.append(10)
    obj.multAll(2)
    obj.append(1)
    obj.append(1)
    obj.append(1)
    obj.multAll(2)

    assert obj.getIndex(0) == 26 * 2
    assert obj.getIndex(1) == 34 * 2
    assert obj.getIndex(2) == 20 * 2
    assert obj.getIndex(3) == 2

    func = [
        "append",
        "addAll",
        "append",
        "multAll",
        "getIndex",
        "addAll",
        "append",
        "multAll",
        "getIndex",
        "getIndex",
        "getIndex",
    ]
    vals = [[2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
    exps = [None, None, None, None, 10, None, None, None, 26, 34, 20]
    f = Fancy()
    for i in range(len(vals)):
        r = getattr(f, func[i])(vals[i][0])
        if exps[i] is not None:
            assert exps[i] == r
    func = [
        "append",
        "getIndex",
        "append",
        "multAll",
        "addAll",
        "multAll",
        "addAll",
        "append",
        "append",
        "append",
        "append",
        "multAll",
        "addAll",
        "append",
        "append",
        "append",
        "append",
        "multAll",
        "append",
        "getIndex",
        "append",
        "getIndex",
        "getIndex",
    ]
    vals = [
        [10],
        [0],
        [4],
        [5],
        [3],
        [3],
        [10],
        [7],
        [3],
        [2],
        [6],
        [8],
        [8],
        [8],
        [6],
        [7],
        [7],
        [9],
        [6],
        [3],
        [10],
        [7],
        [11],
    ]
    exps = [
        None,
        10,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        288,
        None,
        54,
        10,
    ]
    f = Fancy()
    for i in range(len(vals)):
        r = getattr(f, func[i])(vals[i][0])
        if exps[i] is not None:
            assert exps[i] == r
    func = [
        "append",
        "append",
        "append",
        "append",
        "append",
        "append",
        "addAll",
        "multAll",
        "multAll",
        "append",
        "addAll",
        "append",
        "getIndex",
        "addAll",
        "append",
        "append",
        "append",
        "getIndex",
        "multAll",
        "getIndex",
        "getIndex",
        "multAll",
        "getIndex",
        "getIndex",
        "multAll",
        "append",
        "append",
        "append",
        "append",
        "multAll",
        "append",
        "multAll",
        "addAll",
        "getIndex",
        "addAll",
        "addAll",
        "addAll",
        "getIndex",
        "addAll",
        "append",
        "addAll",
        "addAll",
        "addAll",
        "append",
        "multAll",
        "addAll",
        "append",
        "append",
        "addAll",
        "append",
        "addAll",
        "getIndex",
        "append",
        "multAll",
        "getIndex",
        "addAll",
        "multAll",
        "append",
        "append",
        "addAll",
        "append",
        "getIndex",
        "multAll",
        "append",
        "addAll",
        "append",
        "append",
        "getIndex",
        "getIndex",
        "addAll",
        "multAll",
        "getIndex",
        "multAll",
        "getIndex",
        "multAll",
        "append",
        "append",
        "multAll",
        "getIndex",
        "getIndex",
        "multAll",
        "append",
        "multAll",
        "addAll",
        "multAll",
        "multAll",
        "getIndex",
        "append",
        "getIndex",
    ]
    vals = [
        [15],
        [6],
        [9],
        [13],
        [13],
        [7],
        [1],
        [14],
        [14],
        [10],
        [8],
        [2],
        [0],
        [15],
        [3],
        [12],
        [1],
        [2],
        [12],
        [7],
        [9],
        [2],
        [4],
        [1],
        [9],
        [1],
        [8],
        [13],
        [4],
        [12],
        [7],
        [8],
        [10],
        [1],
        [15],
        [14],
        [1],
        [15],
        [4],
        [9],
        [2],
        [7],
        [11],
        [12],
        [3],
        [14],
        [4],
        [2],
        [3],
        [4],
        [12],
        [7],
        [8],
        [12],
        [10],
        [1],
        [9],
        [4],
        [13],
        [4],
        [8],
        [15],
        [12],
        [12],
        [11],
        [8],
        [14],
        [18],
        [3],
        [15],
        [4],
        [0],
        [5],
        [13],
        [10],
        [6],
        [3],
        [15],
        [17],
        [0],
        [4],
        [12],
        [9],
        [14],
        [3],
        [10],
        [17],
        [8],
        [0],
    ]
    exps = [
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        3144,
        None,
        None,
        None,
        None,
        1983,
        None,
        204,
        144,
        None,
        66408,
        33480,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        28926730,
        None,
        None,
        None,
        96,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        None,
        1057757,
        None,
        None,
        749148,
        None,
        None,
        None,
        None,
        None,
        None,
        42025,
        None,
        None,
        None,
        None,
        None,
        24791,
        80163678,
        None,
        None,
        735272514,
        None,
        102776440,
        None,
        None,
        None,
        None,
        253266000,
        454381643,
        None,
        None,
        None,
        None,
        None,
        None,
        527278509,
        None,
        732171430,
    ]
    f = Fancy()
    for i in range(len(vals)):
        r = getattr(f, func[i])(vals[i][0])
        if exps[i] is not None:
            assert exps[i] == r
