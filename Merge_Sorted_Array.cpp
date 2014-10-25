#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int *a = A + m - 1, *b = B + n - 1;
        int *p = A + m + n - 1;
        
        while (a >= A || b >= B) {
            if (a < A) { *p-- = *b--; continue; }

            if (b < B) { *p-- = *a--; continue; }

            cout << "A: " << *a << endl;
            cout << "B: " << *b << endl;

            if (*a > *b) {
                *p-- = *a--;
                cout << "A > B" << endl;
            } else {
                *p-- = *b--;
                cout << "B > A" << endl;
            }

            cout << *p << endl;
        }
    }
};

int main() {
    int A[6] = {1, 2, 3, 0, 0, 0};
    int B[3] = {2, 5, 6};

    Solution s;
    s.merge(A, 3, B, 3);

    return 0;
}