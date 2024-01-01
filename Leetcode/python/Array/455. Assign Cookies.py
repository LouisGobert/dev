"""Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; 
and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content.
Your goal is to maximize the number of your content children and output the maximum number.

 

Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2."""


from typing import List


class Solution:
    def next_cookie_index(self, cookies: List[int], start: int, min_fedd: int) -> int:
        for index in range(start, len(cookies)):
            if cookies[index] >= min_fedd:
                return index

        return -1

    def findContentChildren(self, childs: List[int], cookies: List[int]) -> int:
        childs.sort()
        cookies.sort()

        cookie_index = 0
        child_feeded = 0
        for count, child_min_feed in enumerate(childs):
            cookie_index = self.next_cookie_index(cookies, cookie_index, child_min_feed)
            if cookie_index == -1:
                return child_feeded

            child_feeded += 1
            cookie_index += 1
        return child_feeded


if __name__ == "__main__":
    s = Solution()

    assert s.findContentChildren([1, 2, 3], [1, 1]) == 1
    assert s.findContentChildren([1, 2], [1, 2, 3]) == 2
    assert s.findContentChildren([5], [1, 2, 3, 4]) == 0
    assert s.findContentChildren([2, 2, 3], [1, 1, 1, 4]) == 1
