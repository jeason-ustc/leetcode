class Solution(object):
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        for x in range(32):
            mask = 1 << x
            zero = one = 0
            for num in nums:
                if num & mask:
                    one += 1
                else:
                    zero += 1
            ans += zero * one
        return ans
