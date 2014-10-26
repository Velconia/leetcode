#ifndef CONTAINER_WITH_MOST_WATER_H
#define CONTAINER_WITH_MOST_WATER_H

#include <vector>
#include <iostream>

class Node {
	friend class Solution;
	int pos;
	int value;
	explicit Node(int _v, int _p) : value(_v), pos(_p) { }
};

class Solution {
public:
	int maxArea(std::vector<int> &height) {
		if (height.size() <= 1) return 0;

		std::vector<Node> left_side;
		std::vector<Node> right_side;

		// Find the suitable right sides and left sides
		int temp = -1;
		for (std::vector<int>::iterator iter = height.begin(); iter != height.end(); ++iter) {
			if (*iter > temp) { left_side.push_back(Node(*iter, iter - height.begin())); temp = *iter; }
		}

		temp = -1;
		for (std::vector<int>::reverse_iterator riter = height.rbegin(); riter != height.rend(); ++riter) {
			if (*riter > temp) { right_side.push_back(Node(*riter, height.rend() - riter - 1)); temp = *riter; }
		}

		// Read all sides and find the max
		int maxSum = 0;
		int thisSum = 0;
		for (std::vector<Node>::iterator l_iter = left_side.begin(), r_iter = right_side.begin(); 
			 l_iter != left_side.end() || r_iter != right_side.end(); ) {
				// Remove the not sides which right side's pos is smaller than the left side's pos
				int distance = r_iter->pos - l_iter->pos;
				
				if (distance <= 0) {
					// Move the pointers
					if (l_iter == left_side.end() - 1) {
						if (r_iter == right_side.end() - 1) {
							break;
						} else {
							++r_iter; continue;
						}
					}

					if (r_iter == right_side.end() - 1) {
						if (l_iter == left_side.end() - 1) {
							break;
						} else {
							++l_iter; continue;
						}
					}

					if (l_iter->value >= r_iter->value) ++r_iter;
					else ++l_iter;

					continue;
				}

				// Get the area for this time
				thisSum = l_iter->value >= r_iter->value ? r_iter->value * distance : l_iter->value * distance;

				// Update the max area
				maxSum = maxSum >= thisSum ? maxSum : thisSum;

				// Move the pointers
				if (l_iter == left_side.end() - 1) {
					if (r_iter == right_side.end() - 1) {
						break;
					} else {
						++r_iter; continue;
					}
				}

				if (r_iter == right_side.end() - 1) {
					if (l_iter == left_side.end() - 1) {
						break;
					} else {
						++l_iter; continue;
					}
				}

				if (l_iter->value >= r_iter->value) ++r_iter;
				else ++l_iter;
		}

		return maxSum;
	}
};

#endif // CONTAINER_WITH_MOST_WATER_H