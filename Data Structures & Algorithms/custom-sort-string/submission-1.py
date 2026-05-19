class Solution:
    def customSortString(self, order: str, s: str) -> str:
        res = []
        s_list = list(s)
        for i in order:
            while i in s_list:
                res.append(i)
                s_list.remove(i)

        
        return "".join(res)+"".join(s_list) if s_list else "".join(res)