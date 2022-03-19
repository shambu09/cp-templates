class Solution {
  public:
	int n, m;
	bool boundry;

	int closedIsland(vector<vector<int>>& grid) {
		int islands = 0;
		m = grid.size();
		n = grid[0].size();

		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(grid[i][j] == 0) {
					boundry = false;
					bfs(grid, i, j);
					if(not boundry) islands++;
				}
			}
		}

		return islands;
	}

	void bfs(vector<vector<int>>& grid, int i, int j) {
		if(grid[i][j] == 1 or grid[i][j] == 2) return;
		if((i == 0 or j == 0 or i == m - 1 or j == n - 1)) boundry = true;

		grid[i][j] = 2;

		if(i <= m - 2) bfs(grid, i + 1, j);
		if(i >= 1) bfs(grid, i - 1, j);

		if(j <= n - 2) bfs(grid, i, j + 1);
		if(j >= 1) bfs(grid, i, j - 1);
	}
};