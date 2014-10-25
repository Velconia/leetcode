#include "sort.h"
#include <iostream>

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

int main()
{
	int array[] = { 12, 24, 25, 22, 26 };
	for (int i = 0; i != 5; i++)
		cout << array[i] << " ";
	cout << endl;
	heap_sort(array, array + 5);
	for (int i = 0; i != 5; i++)
		cout << array[i] << " ";
	cout << endl;
}