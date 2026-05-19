class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        letter_map = {}
        digitToChar = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "qprs",
            "8": "tuv",
            "9": "wxyz",
        }
        subset = ""
        res = []
        def backTrack(i,subset):
            
            if len(subset) == len(digits):
                res.append(subset)
                return 
            for k in digitToChar[digits[i]]:
                backTrack(i+1,subset+k)
        if digits:
            backTrack(0,"")
        return res

