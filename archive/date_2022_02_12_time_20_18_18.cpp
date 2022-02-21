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

class NumMatrix {
  public:
	vector<vector<int>> matrix;
	int extractMin(int i, int j) {
		if(i < 0 or j < 0) return 0;

		i = min(i, (int)matrix.size() - 1);
		j = min(j, (int)matrix[0].size() - 1);

		return matrix[i][j];
	}

	NumMatrix(vector<vector<int>>& mat) {
		matrix = mat;

		for(int i = 0; i < matrix.size(); i++) {
			for(int j = 0; j < matrix[0].size(); j++) {
				matrix[i][j] += extractMin(i - 1, j) + extractMin(i, j - 1) -
								extractMin(i - 1, j - 1);
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return extractMin(row2, col2) - extractMin(row1 - 1, col2) -
			   extractMin(row2, col1 - 1) + extractMin(row1 - 1, col1 - 1);
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
