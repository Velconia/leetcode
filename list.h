#ifndef LIST_H
#define LIST_H

/*
 * 简单链表实现，给出了各操作的复杂度
 */

#include "container.h"

struct node {
	friend class list;
	private: 
		explicit node(int value = 0, node *next = 0) : 
			_value(value), _next(next) { }
		node *_next;
		int _value;
};

class list : public easy_container {
private:
	node *_first;
	node *_last;

public:
	explicit list() : easy_container(), _first(0), _last(0) {}
	~list() {}

	// O(1)
	virtual void add(int value)
	{
		if (_first == 0) 
		{
			_first = new node(value, 0);
			_last = _first;
		} else {
			_last->_next = new node(value, 0);
			_last = _last->_next;
		}
	}

	// O(pos) ~~ O(n)
	virtual void remove(int pos)
	{
		node *current = _first;
		int cur_pos = 0;
		if (pos == 0) {
			_first = current->_next;
			delete current;
			return;
		}

		while (current != 0) {
			if (cur_pos++ == pos - 1) {
				node *removeable = current->_next;
				current->_next = current->_next->_next;
				delete removeable;
				break;
			}
			current = current->_next;
		}
	}

	// O(pos) ~~ O(n)
	virtual void set(int pos, int value)
	{
		node *current = _first;
		int cur_pos = 0;
		while (current != 0) {
			if (cur_pos++ == pos) {
				current->_value = value;
				break;
			}
			current = current->_next;
		}
	}

	// O(n)
	virtual int pos(int value)
	{
		node *current = _first;
		int result = 0;
		while (current != 0) {
			if (current->_value == value) 
				return result;
			++result;
			current = current->_next;
		}
		return -1;
	}
};

#endif // LIST_H