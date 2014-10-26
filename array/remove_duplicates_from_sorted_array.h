class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        
        int *push_ptr = A;
        int *incre_ptr = push_ptr + 1;
        
        // O(n)
        for (int i = 1; i != n; i++, incre_ptr++) 
        {
            if (*incre_ptr != *push_ptr && incre_ptr != ++push_ptr)
            {
                *push_ptr = *incre_ptr;
            }
        }
        
        return push_ptr - A + 1;
    }
};