class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int neg_count = 0, pos_count = 0;
        int max_count = 0;
        
        
        for(int i : nums){
            if(i == 0){
                neg_count = 0;
                pos_count = 0;
            }
            
            else if(i < 0){
                swap(neg_count, pos_count);
                neg_count++;
                if(pos_count != 0)
                    pos_count++;
            }
            
            else{
                pos_count++;
                if(neg_count != 0)
                    neg_count++;
            }
            
            max_count = max(max_count, pos_count);
        }
        
        return max_count;
    }
};