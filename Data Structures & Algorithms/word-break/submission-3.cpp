class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> memo;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return canBreak(s, dict, memo);
    }

private:
    bool canBreak(string s, unordered_set<string>& dict, unordered_map<string, bool>& memo) {
        if (s.empty()) return true;
        if (memo.count(s)) return memo[s];

        for (int i = 1; i <= s.length(); ++i) {
            string prefix = s.substr(0, i);
            if (dict.count(prefix)) {
                if (canBreak(s.substr(i), dict, memo)) {
                    return memo[s] = true;
                }
            }
        }

        return memo[s] = false;
    }
};
