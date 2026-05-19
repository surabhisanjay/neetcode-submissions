class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        r = 0
        if len(s) == 0 or  len(s) == 1:
            return len(s)
        window = set()
        longest = 0
        for r in range(len(s)):
            
            while(s[r] in window):
                window.remove(s[l])
                l+=1
            window.add(s[r])
            longest = max(longest,r-l+1)
            
            
       
        return longest
                
            


            
