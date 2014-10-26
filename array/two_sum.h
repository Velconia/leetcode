#include <vector>
#include <algorithm>

using namespace std;

void counting_sort(vector<int>& numbers)
{
    // Do a counting sort first
    vector<int> pos_vec(10, 0);
    vector<int> sorted_vec(numbers);

    for (vector<int>::iterator iter = numbers.begin(); 
         iter != numbers.end(); ++iter)
    {
        ++pos_vec[*iter + 0x0fffffff];
    }
        
    for (vector<int>::iterator iter = ++pos_vec.begin(); 
         iter != pos_vec.end(); ++iter)
    {
        *iter += *(iter - 1);
    }
        
    for (vector<int>::iterator b_iter = --numbers.end();
         b_iter >= numbers.begin(); --b_iter) 
    {
        sorted_vec[--pos_vec[*b_iter + 0x0fffffff]] = *b_iter; 
    }
        
    for (vector<int>::iterator i = sorted_vec.begin(); 
        i != sorted_vec.end(); i++)
        cout << *i << " " << endl;        
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        
        vector<int> sorted_vec(numbers);
        sort(sorted_vec.begin(), sorted_vec.end());

        // Give two pointers, one moves forward and another one
        // moves backward
        vector<int>::iterator f_iter = sorted_vec.begin();
        vector<int>::iterator b_iter = --sorted_vec.end();
        
        while (f_iter != b_iter)
        {
            int sum = *f_iter + *b_iter;
            
            if (sum == target)
            {
                // Find the two values from the vector
                for (vector<int>::iterator f_i = numbers.begin();
                     f_i != numbers.end(); f_i++) {
                    if (*f_i == *f_iter) {
                        f_iter = f_i;
                        break;
                    }
                }

                for (vector<int>::iterator b_i = --numbers.end();
                     b_i >= numbers.begin(); b_i--) {
                    if (*b_i == *b_iter) {
                        b_iter = b_i;
                        break;
                    }
                }
                
                result.push_back(min(f_iter, b_iter) - numbers.begin() + 1);
                result.push_back(max(f_iter, b_iter) - numbers.begin() + 1);
                return result;
            }
            
            if (sum < target) f_iter++;
            
            if (sum > target) b_iter--;
        }
        
        return result;
    }
};