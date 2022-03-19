class Solution {
  public:
	int n, m;
	int numIslands(vector<vector<char>>& grid) {
		int islands = 0;
		m = grid.size();
		n = grid[0].size();

		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(grid[i][j] == '1') {
					islands++;
					bfs(grid, i, j);
				}
			}
		}

		return islands;
	}

	void bfs(vector<vector<char>>& grid, int i, int j) {
		if(grid[i][j] == '0') return;
		grid[i][j] = '0';

		if(i <= m - 2) bfs(grid, i + 1, j);
		if(i >= 1) bfs(grid, i - 1, j);

		if(j <= n - 2) bfs(grid, i, j + 1);
		if(j >= 1) bfs(grid, i, j - 1);
	}
};