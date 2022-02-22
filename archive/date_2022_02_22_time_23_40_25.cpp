#include <bits/stdc++.h>

#include "templates.h"
using namespace std;

class Solution {
  public:
	int find(vector<int>& parent, int i) {
		if(parent[i] == -1) return i;

		return parent[i] = find(parent, parent[i]);
	}

	void make_union(vector<int>& parent, vector<int>& rank, int x, int y) {
		if(rank[x] < rank[y]) {
			parent[x] = y;
			rank[y] += rank[x];
		} else {
			parent[y] = x;
			rank[x] += rank[y];
		}
	}

	int minCostConnectPoints(vector<vector<int>>& ps) {
		int n = (int)ps.size();
		vector<array<int, 3>> edges;
		vector<int> parent(n, -1);
		vector<int> rank(n, 1);
		int res = 0, un = 0;

		for(int i = 0; i <= n - 2; i++) {
			for(int j = i + 1; j <= n - 1; j++) {
				edges.push_back(
					{abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]), i,
					 j});
			}
		}

		make_heap(all(edges), greater<array<int, 3>>());

		while(!edges.empty()) {
			pop_heap(all(edges), greater<array<int, 3>>());
			auto [dist, i, j] = edges.back();
			edges.pop_back();

			i = find(parent, i);
			j = find(parent, j);

			if(i != j) {
				res += dist;
				make_union(parent, rank, i, j);
				un++;
				if(un == n - 1) {
					break;
				}
			}
		}

		return res;
	}
};

int main() {
	int n;
	vector<vector<int>> points;
	cin >> n;

	int x, y;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		points.push_back({x, y});
	}

	Solution s = Solution();
	cout << s.minCostConnectPoints(points);
	return 0;
}