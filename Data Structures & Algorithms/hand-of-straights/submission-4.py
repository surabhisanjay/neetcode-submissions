from collections import Counter

class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int):

        if len(hand) % groupSize:
            return False

        nums = Counter(hand)
        avail = set(nums.keys())

        while avail:
            currmin = min(avail)

            i = 0
            while i < groupSize and currmin + i in avail:
                nums[currmin + i] -= 1

                if nums[currmin + i] == 0:
                    avail.remove(currmin + i)

                i += 1

            if i < groupSize:
                return False

        return True