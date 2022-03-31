class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return 0

        addition = [[] for _ in range(len(num2))]

        for i, val in enumerate(num2):

            """ 1
              745
            x  12
            1490
            7450"""

            for x in top in enumerate(num1):

                addition[i].append("0" * i)
