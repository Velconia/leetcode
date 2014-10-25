#include <iostream>
#include <vector>

using namespace std;

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
        	if (*riter < max) { temp_min = *riter; min_pos = riter - prices.rbegin(); 
            cout << "min_pos: " << min_pos << endl;}
            
            cout << "temp_min: " << temp_min << endl;

            if (max_pos <= min_pos) {
            	int temp_res = temp_max - temp_min;
            	res = temp_res > res ? temp_res : res;
            }
            
            if (*riter > max) { temp_max = *riter; max_pos = riter - prices.rbegin(); 
           	cout << "max_pos: " << max_pos << endl; }
            
            cout << "temp_max: " << temp_max << endl;

            if (max_pos <= min_pos) {
            	int temp_res = temp_max - temp_min;
            	res = temp_res > res ? temp_res : res;
            	cout << "Res2: " << res << endl;
            }
            
            max = temp_max;
            min = temp_min;
        }
        
        return res;
    }
};

int main() {
	std::vector<int> v;
	v.push_back(6);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	v.push_back(7);

	Solution s;
	cout << s.maxProfit(v) << endl;
	return 0;
}