class Solution {
  public:
	int longestCommonSubsequence(string s, string t) {
		int n = s.size();
		int m = t.size();

		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(s[i] == t[j])
					dp[i + 1][j + 1] = dp[i][j] + 1;
				else
					dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}

		return dp.back().back();
	}
};

// Efficient Solution
// class Solution {
//   public:
// 	int longestCommonSubsequence(string s, string t) {
// 		int n = s.size();
// 		int m = t.size();

// 		vector<int> dp(m + 1);
// 		int prev, curr;

// 		for(int i = 0; i < n; i++) {
// 			prev = dp[0];
// 			for(int j = 0; j < m; j++) {
// 				curr = dp[j + 1];

// 				if(s[i] == t[j])
// 					dp[j + 1] = prev + 1;
// 				else
// 					dp[j + 1] = max(dp[j], curr);

// 				prev = curr;
// 			}
// 		}

// 		return dp.back();
// 	}
// };