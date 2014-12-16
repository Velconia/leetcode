#include <stack>

// Normal Solution
class MinStack {
public:
	explicit MinStack() : _m(), _s() {}

	void push(int x) {
		if (_m.empty()) {
			_m.push(x);
		} else {
			if (_m.top() >= x) {
				_m.push(x);
			}
		}

		_s.push(x);
	}

	void pop() {
		if (_m.top() == _s.top()) {
			_m.pop();
		}
		_s.pop();	
	}

	int top() {
		return _s.top();
	}		

	int getMin() {
		return _m.top();
	}
private:
	stack<int> _m; // Stack stores the minimum numbers 
	stack<int> _s; // Stack stores the data
};

// Genius Solution
class MinStack {
public:
	explicit MinStack() : minNum(0), _s() { }

	void push(int x) {
		if (_s.empty()) {
			_s.push(minNum - x);
			minNum = x;
		} else {
			_s.push(x - minNum);
			if (x < minNum) {
				minNum = x;
			}
		}
	}

	void pop() {
		if (_s.top() < 0) {
			minNum -= _s.top();
		}
		_s.pop();
		
	}

	int top() {
		if (_s.top() < 0) {
			return minNum;
		} else {
			return _s.top() + minNum;
		}
	}		

	int getMin() {
		return minNum;
	}

private:
	int minNum;
	stack<int> _s;
};

