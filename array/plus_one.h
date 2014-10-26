class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        
        for (vector<int>::reverse_iterator iter = digits.rbegin(); iter != digits.rend(); ) {
            if (*iter != 9) {
                (*iter)++;
                break;
            } else {
                *iter++ = 0;
                if (iter == digits.rend()) {
                    res.push_back(1);
                }
            }
        }
        
        for (vector<int>::iterator iter = digits.begin(); iter != digits.end(); ++iter) {
            res.push_back(*iter);
        } 
        
        return res;
    }
};