class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int *a = A + m - 1, *b = B + n - 1;
        int *p = A + m + n - 1;
        
        while (a >= A || b >= B) {
            if (a < A) { *p-- = *b--; continue; }
            if (b < B) { *p-- = *a--; continue; }
            if (*a > *b) {
                *p-- = *a--;
            } else {
                *p-- = *b--;
            }
        }
    }
};