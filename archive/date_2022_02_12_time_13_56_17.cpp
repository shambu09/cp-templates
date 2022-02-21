class Solution {
  public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int m = triangle.size();
		if(m == 1) return triangle[0][0];
		int res = INT_MAX;

		for(int i = 1; i < m; i++) {
			for(int j = 0; j <= i; j++) {
				if(j == 0)
					triangle[i][j] = triangle[i][j] + triangle[i - 1][j];

				else if(j == i)
					triangle[i][j] = triangle[i][j] + triangle[i - 1][j - 1];

				else {
					triangle[i][j] =
						triangle[i][j] +
						min(triangle[i - 1][j], triangle[i - 1][j - 1]);
				}

				if(i == m - 1) res = min(res, triangle[i][j]);
			}
		}

		return res;
	}
};