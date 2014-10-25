#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Question: 
//
// Given an array of integers, find two numbers such that they add up to a specific target number.
//
// The function twoSum should return in dices of the two numbers such that they add up to the target, 
// where index1 must be less than index 2. Please note that your returned answers (both index1 and index2) 
// are not zero-based.
//
// You may assume that each input would have exactly one solution.
//
// Input: numbers = {2, 7, 11, 15}, target = 9
// Output: index1=1, index2=2

// O(nlgn)
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

void counting_sort(vector<int>& numbers)
{
    // Do a counting sort first
    vector<int> pos_vec(100000, 0);     // For positive numbers
    vector<int> _pos_vec(100000, 0);    // For negative numbers
    vector<int> sorted_vec(numbers);

    // initialize two arrays
    for (vector<int>::iterator iter = numbers.begin(); 
         iter != numbers.end(); ++iter)
    {
        if (*iter >= 0)
            ++pos_vec[*iter];
        else 
            ++_pos_vec[-*iter];
    }
    
    // Set every elements' location
    for (vector<int>::iterator _b_iter = _pos_vec.end() - 2;
         _b_iter >= _pos_vec.begin(); --_b_iter) *_b_iter += *(_b_iter + 1);

    *pos_vec.begin() += *_pos_vec.begin();

    for (vector<int>::iterator iter = ++pos_vec.begin(); 
         iter != pos_vec.end(); ++iter) *iter += *(iter - 1);
    
    // Set every number back
    for (vector<int>::iterator b_iter = --numbers.end();
         b_iter >= numbers.begin(); --b_iter) 
    {
        if (*b_iter >= 0)
            sorted_vec[--pos_vec[*b_iter]] = *b_iter; 
        else 
            sorted_vec[--_pos_vec[-*b_iter]] = *b_iter; 
    }
    
    copy(sorted_vec.begin(), sorted_vec.end(), numbers.begin());     
}

// O(n) 这个使用了计数排序，所以时间复杂度为O(n)
// 但是，有最大和最小数的限制，已经考虑了正负数
vector<int> twoSum2(vector<int> &numbers, int target) {
        vector<int> result;
        
        vector<int> sorted_vec(numbers);
        counting_sort(numbers);

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

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);  
    twoSum(v, 6);
    return 0;
}