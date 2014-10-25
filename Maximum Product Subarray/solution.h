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