class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> result;
        vector<int> vecAbove;
        
        int curRow = 0;
        while (curRow != numRows) {
            vector<int> tmpVec;
            
            // Push the first 1
            tmpVec.push_back(1);
            
            int curColumn = 1;
            while (curColumn <= curRow - 1) {
                tmpVec.push_back(vecAbove[curColumn - 1] + vecAbove[curColumn]);
                curColumn++;
            }
            
            // Push the last 1
            if (curRow > 0) tmpVec.push_back(1);
            
            vecAbove = tmpVec;
            result.push_back(tmpVec);
            ++curRow;
        }
        
        return result;
    }
};