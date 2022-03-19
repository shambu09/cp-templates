class Solution {
  public:
	int n, m;
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int islands = 0, max_area = 0;
		m = grid.size();
		n = grid[0].size();

		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(grid[i][j]) {
					islands++;
					max_area = max(max_area, bfs(grid, i, j));
				}
			}
		}

		return max_area;
	}

	int bfs(vector<vector<int>>& grid, int i, int j) {
		if(not grid[i][j]) return 0;

		int sum = 1;
		grid[i][j] = 0;

		if(i <= m - 2) sum += bfs(grid, i + 1, j);

		if(i >= 1) sum += bfs(grid, i - 1, j);

		if(j <= n - 2) sum += bfs(grid, i, j + 1);

		if(j >= 1) sum += bfs(grid, i, j - 1);

		return sum;
	}
};