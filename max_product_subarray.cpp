#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <bitset>

using namespace std;

class Decimal {
public:
	Decimal(int num) : _bit_vec(parse(num))
	{

	}

	Decimal(const Decimal& new_decimal)
	{

	}

private:
	vector<char> _bit_vec;

	vector<char>& parse(int num)
	{
		// We assume that the int type has 32 bits
		const unsigned int int_type_length = 32;
		bitset<int_type_length> bit_set(num);
		
	}
};

class Solution {
public:
	int maxProduct(int A[], int n)
	{
		int size = n;

		// Prepare the data.
		int *cur = A;
		int temp = *cur;
		int res = *cur > 0 ? *cur : 1;
		int res = *cur;

		// Extra condition.
		if (n == 0) return 0;

		if (n == 1) return res;

		// Foreach the A array.
		while (--size != 0 && ++cur)
		{
			temp *= *cur;

			if (temp > 0)
			{
				res = temp;
			}
		}

		return res;
	}
};

int main()
{
	int A[] = { 2, 3, -1, 4 };
	Solution solution;
	cout << solution.maxProduct(A, 4) << endl;
	return EXIT_SUCCESS;
}