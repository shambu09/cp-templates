#include <bits/stdc++.h>

#include "templates.h"
using namespace std;

namespace bin_idx_tree {
	struct tree {
		int* nodes;

		tree(int n) {
			n++;
			nodes = (int*)malloc(n * sizeof(int));
			memset(nodes, 0, n * sizeof(int));
		}

		int get(int idx) {
			int res = nodes[idx];
			for(idx++; idx > 0; idx -= idx & (-idx)) res = max(res, nodes[idx]);
			return res;
		}

		void update(int n, int idx, int val) {
			for(idx++; idx <= n; idx += idx & (-idx))
				nodes[idx] = max(nodes[idx], val);
		}
	};

}  // namespace bin_idx_tree

const int nax = 1e4 + 1;

class Solution {
  public:
	int lengthOfLIS(vector<int>& nums) {
		bin_idx_tree::tree t(2 * nax);

		for(int i : nums) {
			int l = t.get(nax + i - 1);
			t.update(2 * nax - 1, nax + i, l + 1);
		}

		return t.get(2 * nax - 1);
	}
};

int main() {
	int n;
	vector<int> arr;

	cin >> n;
	while(n--) {
		arr.push_back(0);
		cin >> arr.back();
	}

	Solution s = Solution();
	cout << s.lengthOfLIS(arr) << endl;
}