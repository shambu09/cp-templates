#include <bits/stdc++.h>

#ifndef SIZE_TYPE
#define SIZE_TYPE int
#endif

#ifndef STORAGE_TYPE
#define STORAGE_TYPE int
#endif

//--------------- Printing a std::vector | tags - printing, vector, print----------------//

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
	os << "[";
	for(SIZE_TYPE i = 0; i <= (SIZE_TYPE)vec.size() - 2; i++)
		os << vec[i] << ", ";
	return os << vec.back() << "]";
}

template <class T>
std::ostream& operator<<(std::ostream& os,
						 const std::vector<std::vector<T>>& vec) {
	os << "[ " << vec[0] << ",\n";
	for(SIZE_TYPE i = 1; i <= (SIZE_TYPE)vec.size() - 2; i++)
		os << "  " << vec[i] << ",\n";
	return os << "  " << vec.back() << " ]";
}

//----------------------------------------------------------------------------------------//

//----------------------shortcut for vector.begin() and vector.end()----------------------//
#ifndef all
#define all(s) s.begin(), s.end()
#endif
//----------------------------------------------------------------------------------------//

class Solution {
  public:
	vector<vector<int>> dp;

	int extractSum(int i, int j) {
		if(i < 0 or j < 0) return 0;

		i = min(i, (int)dp.size() - 1);
		j = min(j, (int)dp[0].size() - 1);

		return dp[i][j];
	}

	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
		int m = mat.size();
		int n = mat[0].size();

		dp = vector<vector<int>>(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				dp[i][j] = mat[i][j] + extractSum(i - 1, j) +
						   extractSum(i, j - 1) - extractSum(i - 1, j - 1);
			}
		}

		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				mat[i][j] = extractSum(i + k, j + k) -
							extractSum(i + k, j - k - 1) -
							extractSum(i - k - 1, j + k) +
							extractSum(i - k - 1, j - k - 1);
			}
		}

		return mat;
	}
};