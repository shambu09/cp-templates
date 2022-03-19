class Solution {
  public:
	void rotate(vector<int>& nums, int k) {
		k %= (int)nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}
};

// class Solution {
//   public:
// 	void rotate(vector<int>& nums, int k) {
// 		int n = (int)nums.size();
// 		int start = 0;

// 		for(; k %= n; n -= k, start += k) {
// 			for(int i = 0; i < k; i++) {
// 				swap(nums[start + i], nums[start + n - k + i]);
// 			}
// 		}
// 	}
// };