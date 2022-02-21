class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        int neg_product = 1, pos_product = 1;
        int max_product = nums[0];
        
        for(int i : nums){
            pos_product *= i;
            neg_product *= i;
            
            auto tmp = {neg_product, pos_product, i};
            neg_product = min(tmp);
            pos_product = max(tmp);
            max_product = max(max_product, pos_product);
        }
        
        return max_product;
        
    }
};