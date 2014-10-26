#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
    	if (prices.size() <= 1) return 0;

        std::vector<int>::reverse_iterator riter = prices.rbegin();
        
        int res = 0;
        int max = *riter, max_pos = riter - prices.rbegin();
        int min = *riter, min_pos = riter - prices.rbegin();
        int temp_max = max;
        int temp_min = min;

        // Read all elements reversely
        for ( ;riter != prices.rend(); ++riter) {
        	if (*riter < max) { temp_min = *riter; min_pos = riter - prices.rbegin(); }
            
            if (max_pos <= min_pos) {
            	int temp_res = temp_max - temp_min;
            	res = temp_res > res ? temp_res : res;
            }
            
            if (*riter > max) { temp_max = *riter; max_pos = riter - prices.rbegin(); }

            if (max_pos <= min_pos) {
            	int temp_res = temp_max - temp_min;
            	res = temp_res > res ? temp_res : res;
            }
            
            max = temp_max;
            min = temp_min;
        }
        
        return res;
    }
};
