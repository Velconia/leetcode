#ifndef MAX_PRODUCT_SUBARRAY_H
#define MAX_PRODUCT_SUBARRAY_H

// There is a best practice of this kind of problem
// I named this kind of problem with "thisSum and maxSum method"
// We always keep two values - "thisSum" and "maxSum"
// thisSum represent the the sum of this subarray
// maxSum represent the max sum of all subarraies which we have gone through
class Solution {
public:
    int maxProduct(int A[], int n)
	{
		int size = n;

		// Prepare the data.
		int *cur = A;
		int temp = *cur;
		int res = *cur > 0 ? *cur : 0;

		// Extra condition.
		if (n == 0) return 0;

		if (n == 1) return *cur;

		// Foreach the A array.
		while (--size != 0 && ++cur)
		{
			temp *= *cur;

			if (temp >= res)
			{
				res = temp > *cur ? temp : *cur;
				temp = temp < *cur ? *cur : temp;
			}
		}

        cur = A + n;
        size = n;
		temp = 1;
		while (--size != 0 && --cur)
		{
			temp *= *cur;

			if (temp > res)
			{
				res = temp;
			}
		}

		return res;
	}
};

#endif // MAX_PRODUCT_SUBARRAY_H