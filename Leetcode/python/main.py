from Array.letter_case_permutation import *
from BinaryTree.TreeNode import *

def start():
    res = Solution()
    resultat = res.letterCasePermutation("12345")
    """
    1 1 1 5
    1 1 0 5
    1 0 1 5
    """
    print(resultat)


def startTree():

    b3 = TreeNode.getTree(3)
    b4 = TreeNode.getTree(4)

    res = Solution()

    resu = res.mergeTrees(b3, b4)

    print(resu)


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    start()
