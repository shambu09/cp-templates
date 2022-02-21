class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        @cache
        def backtrack(i):
            if i >= len(s):
                return True
            
            res = False
            for j in range(i, len(s)):
                tmp = s[i: j + 1]
                if tmp in wordDict:
                    res = res or backtrack(j + 1);
                
            return res;
        
        return backtrack(0)