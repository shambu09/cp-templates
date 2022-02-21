class Solution {
  public:
	int minFallingPathSum(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();

		if(m == 1) return *min_element(matrix[0].begin(), matrix[0].end());
		int res = INT_MAX;

		for(int i = 1; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(j == 0)
					matrix[i][j] = matrix[i][j] +
								   min(matrix[i - 1][j], matrix[i - 1][j + 1]);

				else if(j == n - 1)
					matrix[i][j] = matrix[i][j] +
								   min(matrix[i - 1][j - 1], matrix[i - 1][j]);

				else
					matrix[i][j] = matrix[i][j] +
								   min({matrix[i - 1][j - 1], matrix[i - 1][j],
										matrix[i - 1][j + 1]});

				if(i == m - 1) {
					res = min(res, matrix[i][j]);
				}
			}
		}

		return res;
	}
};