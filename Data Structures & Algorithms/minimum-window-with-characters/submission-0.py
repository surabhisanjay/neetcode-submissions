# class Solution:

#     def minWindow(self, s: str, t: str) -> str:
#         currWindow = {}
#         t_win = {}
#         tset = set(t)
#         for ch in t:
#             t_win[ch] = t_win.get(ch, 0) + 1
#             currWindow[ch] = 0
#         minlength  = 1000
#         r = 0
#         res = ""
#         l=0
#         for i in t:
#             currWindow[i] = 0
#         while(r < len(s)):
#             if s[r] in tset :
#                 currWindow[s[r]] = min(currWindow[s[r]]+1,t_win[s[r]])

#             while currWindow == t_win:  
#                 if (r - l + 1) < minlength:
#                     minlength = r - l + 1          
#                     res = s[l:r+1]
#                 if s[l] in tset:
#                     currWindow[s[l]] -= 1
#                 l += 1  
#             r += 1
#         return res

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        currWindow = {}
        t_win = {}
        tset = set(t)

        # Build frequency map for t
        for ch in t:
            t_win[ch] = t_win.get(ch, 0) + 1
            currWindow[ch] = 0

        
        r = 0
        res = [-1,-1]
        reslen = float('inf')
        minlength  = float('inf')
        l = 0
        have = 0
        need = len(t_win)
        for r in range(len(s)):
            currWindow[s[r]] = currWindow.get(s[r],0)+1

            if s[r] in t_win and currWindow[s[r]] == t_win[s[r]]:
                have += 1
            while have == need:
                if (r - l + 1) < reslen:
                    res = [l,r]      # ✅ update minlength
                    reslen = r-l+1
                currWindow[s[l]] -= 1
                if s[l] in t_win and currWindow[s[l]] < t_win[s[l]]:
                    have-=1
                l += 1

            r += 1
        l,r = res
        return s[l:r+1] if reslen != float('inf') else ""

