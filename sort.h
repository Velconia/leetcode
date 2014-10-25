#ifndef SORT_H
#define SORT_H

#include <vector>
#include <iostream>

/*
 * 所有sort算法的简单实现，给出了所有复杂度的可能情况
 */

using namespace std;

void swap(int *a, int *b) 
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void max_heapify_aux(int *current, int *first, const int size) 
{	
	const size_t pos = current - first + 1;
	int *left = first + pos * 2 - 1;
	int *right = first + pos * 2;
	cout << "size: " << size << endl;
	cout << "p: " << pos << " l: " << left - first + 1 << " r: " << right - first + 1 << endl;

	if (pos > size / 2 || size == 1) return;

	int *largest = current;
	if (*left > *largest) {
		largest = left;
		if (*right > *largest && size >= 3) {
			largest = right;
		} 
		swap(largest, current);
		max_heapify_aux(largest, first, size);
	} else {
		if (*right > *largest && size >= 3) {
			largest = right;
			swap(largest, current);
			max_heapify_aux(largest, first, size);
		}
	}
}

void max_heapify(int *first, int *last)
{
	max_heapify_aux(first, first, last - first);	
}

void build_max_heapify(int *first, int *last)
{
	for (int *current = first + (last - first) / 2 - 1; // O(1)
	 	 current >= first; --current) {					// n/2 times
		max_heapify_aux(current, first, last - first);	// O(1)
	}
}

// 最佳复杂度: nlgn
// 一般复杂度: nlgn
// 最差复杂度: nlgn
// 堆排序会对数组内的值进行无差别的max-heapify操作，这个操作
// 保证时间复杂度~O(lgn)，所以堆排序的复杂度一直是O(nlgn)
void heap_sort(int *first, int *last)
{
	build_max_heapify(first, last); // O(n)
	for (int *i = first; i != last; ++i) {
		cout << *i << endl;
	}
	while (first != last--)
	{
		swap(first, last);
		max_heapify(first, last); // O(lgn)
		cout << last - first << ": ";
		for (int *i = first; i <= last; ++i) {
			cout << *i << " ";
		}
		cout << endl;
	}
}

#endif // SORT_H