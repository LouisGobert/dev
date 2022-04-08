from typing import List

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:

        if not len(image):
            return image

        building = [None] * len(image[0])

        explored = []
        for i in range(len(image)):
            explored.append(building.copy())

        self.fill(sc, sr, newColor, image[sr][sc], image, explored)



        return image

    def fill(self, x, y, new_color, present_color, image, explored):

        image[y][x] = new_color
        explored[y][x] = True


        if y != 0 and image[y-1][x] == present_color and not explored[y-1][x]:
            self.fill(x, y-1, new_color, present_color, image, explored)

        if x != 0 and image[y][x-1] == present_color and not explored[y][x-1]:
            self.fill(x-1, y, new_color, present_color, image,explored)

        if y != len(image)-1 and image[y + 1][x] == present_color and not explored[y+1][x]:
            self.fill(x, y + 1, new_color, present_color, image, explored)

        if x != len(image[0])-1 and image[y][x + 1] == present_color and not explored[y][x+1]:
            self.fill(x + 1, y, new_color, present_color, image, explored)
