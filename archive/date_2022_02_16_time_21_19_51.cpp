class Solution {
  public:
	vector<vector<int>> prefix;
	int get_sum(int i, int j) {
		if(i < 0 or j < 0) return 0;
		i = min(i, (int)prefix.size() - 1);
		j = min(j, (int)prefix[0].size() - 1);

		return prefix[i][j];
	}

	int isSquare(int i, int j, int win, vector<vector<char>>& mat) {
        int ei = i + win - 1;
        int ej = j + win - 1;
            
		int sum = get_sum(ei, ej) - get_sum(i - 1, ej) -
				  get_sum(ei, j - 1) + get_sum(i - 1, j - 1);
		if(sum == win * win) return sum;
		return 0;
	}

	int maximalSquare(vector<vector<char>>& mat) {
		int m = mat.size();
		int n = mat[0].size();

		if(m == n and m == 1) return mat[0][0] - '0';

		prefix = vector<vector<int>>(m, vector<int>(n, 0));

		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				prefix[i][j] = (mat[i][j] - '0') + get_sum(i - 1, j) +
							   get_sum(i, j - 1) - get_sum(i - 1, j - 1);
			}
		}

		int smax = (max(m, n) / 2) * 2;
		int res	 = 0;

		for(int i = 1; i <= smax; i++) {
			for(int j = 0; j <= m - i; j++) {
				for(int k = 0; k <= n - i; k++) {
					res = max(res, isSquare(j, k, i, mat));
				}
			}
		}

		return res;
	}
};