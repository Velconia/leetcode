class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        
        if (rowIndex < 0) return result;
        
        if (rowIndex == 0) { result.push_back(1); return result; }
        
        result.push_back(1); 
        result.push_back(1);
        
        int curRow = 1;
        while (curRow != rowIndex) {
            int prev_val = *result.begin();
            for (vector<int>::iterator iter = result.begin() + 1; iter != result.end(); ++iter) {
                int tmp = *iter;
                *iter = prev_val + *iter;
                prev_val = tmp;
            }
            result.push_back(1);
            
            ++curRow;
        }
        
        return result;
    }
};