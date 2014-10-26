class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (n == 0) return n;
        
        int sam_num = 0;
        int *cur = A;
        int *walker = A;
        while (walker != A + n) {
            if (*walker != elem) {
                *cur++ = *walker++;
            } else {
                ++sam_num;
                ++walker;   
            }
        }
        
        return n - sam_num;
    }
};