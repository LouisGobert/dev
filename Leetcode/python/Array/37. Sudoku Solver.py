import heapq
from copy import deepcopy
from types import new_class
from typing import List, Tuple

NUMBERS = [1, 2, 3, 4, 5, 6, 7, 8, 9]
VOID = "."


def is_valid_sudoku(board: List[List[str | int]], void=".") -> bool:
    # check horizontally
    h_board = {}
    h_hor = {}
    for x in range(9):
        for y in range(9):
            if board[x][y] in h_hor and board[x][y] != void:
                return False
            h_hor[board[x][y]] = y

            # add the row into hash board
        h_board[x] = dict(h_hor)
        h_hor.clear()

    h_ver = {}
    for x in range(9):
        for i in range(9):
            if board[i][x] in h_ver and board[i][x] != void:
                return False
            else:
                h_ver[board[i][x]] = i

        h_ver.clear()

    h_block = {}
    for cube_x in range(0, 7, 3):
        for cube_y in range(0, 7, 3):
            for x in range(3):
                for y in range(3):
                    if board[x + cube_x][y + cube_y] in h_block and board[x + cube_x][y + cube_y] != void:
                        return False
                    else:
                        h_block[board[x + cube_x][y + cube_y]] = y
            h_block.clear()

    return True


Board = List[List[int | str]]
PotentialBoard = List[Tuple[int, Tuple[int, int], List[int]]]


def compute_potential_number(board: Board) -> PotentialBoard:
    # potentials = [[[]] * 9] * 9

    minheap: PotentialBoard = []
    for row in range(9):
        for col in range(9):
            if board[row][col] != VOID:
                continue
            initial_value = board[row][col]
            potentials = []
            for number in range(1, 9):
                board[row][col] = number
                if is_valid_sudoku(board):
                    potentials.append(number)

            minheap.append((len(potentials), (row, col), potentials))
            board[row][col] = initial_value

    return sorted(minheap, key=lambda t: t[0])


class Solution:
    index: int
    positions: List[List[int]]
    potentials_by_cell: PotentialBoard

    board: Board

    def _rollback(self, row, col) -> None:
        self.index -= 1
        self.board[row][col] = VOID
        nc, nr = self.potentials_by_cell[self.index][1]
        self.board[nc][nr] += 1

    def solveSudoku(self, board: List[List[str | int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.board = board

        for row in range(9):
            for col in range(9):
                # # CHeck if in the base board there is a number
                # if board[row][col] == VOID:
                #     self.empty_positions.append([row, col])
                if board[row][col] != VOID:
                    board[row][col] = int(board[row][col])

        self.potentials_by_cell = compute_potential_number(board)

        self.index = 0
        while self.index < len(self.potentials_by_cell):
            r, c = self.potentials_by_cell[self.index][1]

            cell_val = board[r][c]
            if cell_val == VOID:
                cell_val = 1

            if cell_val > 9:  # type: ignore
                self._rollback(r, c)
                continue

            board[r][c] = cell_val
            if is_valid_sudoku(board):
                self.index += 1
            else:
                board[r][c] += 1
                if board[r][c] > 9:
                    self._rollback(r, c)

        for r in range(9):
            for c in range(9):
                board[r][c] = str(board[r][c])


if __name__ == "__main__":
    board = [
        [".", ".", ".", ".", ".", "7", ".", ".", "9"],
        [".", "4", ".", ".", "8", "1", "2", ".", "."],
        [".", ".", ".", "9", ".", ".", ".", "1", "."],
        [".", ".", "5", "3", ".", ".", ".", "7", "2"],
        ["2", "9", "3", ".", ".", ".", ".", "5", "."],
        [".", ".", ".", ".", ".", "5", "3", ".", "."],
        ["8", ".", ".", ".", "2", "3", ".", ".", "."],
        ["7", ".", ".", ".", "5", ".", ".", "4", "."],
        ["5", "3", "1", ".", "7", ".", ".", ".", "."],
    ]
    output = [
        ["5", "3", "4", "6", "7", "8", "9", "1", "2"],
        ["6", "7", "2", "1", "9", "5", "3", "4", "8"],
        ["1", "9", "8", "3", "4", "2", "5", "6", "7"],
        ["8", "5", "9", "7", "6", "1", "4", "2", "3"],
        ["4", "2", "6", "8", "5", "3", "7", "9", "1"],
        ["7", "1", "3", "9", "2", "4", "8", "5", "6"],
        ["9", "6", "1", "5", "3", "7", "2", "8", "4"],
        ["2", "8", "7", "4", "1", "9", "6", "3", "5"],
        ["3", "4", "5", "2", "8", "6", "1", "7", "9"],
    ]
    s = Solution()
    s.solveSudoku(board=board)
    assert board == output
