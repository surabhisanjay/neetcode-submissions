class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        n = len(heights)
        maxArea = 0
        for i in range(n):
            start = i
            h = heights[i]
            while(stack and h < stack[-1][1]):
                idx,ht = stack.pop()
                maxArea = max(maxArea,ht*(i-idx))
                start = idx
            stack.append((start, h))
        n = len(heights)
        while stack:
            idx, height = stack.pop()
            maxArea = max(maxArea, height*(n-idx))
        return maxArea

