class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxSum = A[0];
        int thisSum = A[0];
        for (int i = 1; i != n; i++) {
            if (thisSum >= 0) {
                thisSum += A[i];
            } else {
                if (A[i] >= 0) {
                    thisSum = A[i];
                } else {
                    thisSum = A[i] > thisSum ? A[i] : thisSum;
                }
            }
            
            maxSum = maxSum > thisSum ? maxSum : thisSum;
        }
        return maxSum;
    }
};