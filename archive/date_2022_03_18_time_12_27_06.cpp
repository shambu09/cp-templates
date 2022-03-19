class Solution {
  public:
	int n, m;
	vector<vector<int>> floodFill(vector<vector<int>>& image,
								  int sr,
								  int sc,
								  int newColor) {
		n = image.size();
		m = image[0].size();

		if(image[sr][sc] != newColor)
			flood_fill(sr, sc, newColor, image, image[sr][sc]);
		return image;
	}

	void flood_fill(int sr,
					int sc,
					int new_color,
					vector<vector<int>>& image,
					int org_color) {
		if(image[sr][sc] != org_color) return;
		image[sr][sc] = new_color;

		if(sr <= n - 2) flood_fill(sr + 1, sc, new_color, image, org_color);
		if(sr >= 1) flood_fill(sr - 1, sc, new_color, image, org_color);

		if(sc <= m - 2) flood_fill(sr, sc + 1, new_color, image, org_color);
		if(sc >= 1) flood_fill(sr, sc - 1, new_color, image, org_color);
	}
};