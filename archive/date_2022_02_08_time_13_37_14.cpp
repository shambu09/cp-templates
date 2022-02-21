class Solution {
public:
    map<int, bool> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        return _backtrack(s, wordDict, 0);        
    }
    
    
    bool _backtrack(string& s, vector<string>& wordDict, int i){
        if(memo.count(i) != 0)
            return memo[i];
        
        if(i >= s.size()){
            return true;
        }
        
        bool res = false;
        for(int j = i; j < s.size(); j++){
            string tmp = s.substr(i, j - i + 1);
            
            if(find(wordDict.begin(), wordDict.end(), tmp) != wordDict.end()){
                res = res || _backtrack(s, wordDict, j+1);
            }
        }
        
        memo[i] = res;
        return res;               
    }
};