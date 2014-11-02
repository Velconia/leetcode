#include <queue>
#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::queue;
using std::vector;
using std::unordered_set;
using std::string;

class Node {
	friend class Solution;
private:
	string val;
	// bool visited;
	vector<Node *> links;

public:
	explicit Node(const string& _v) : val(_v) /*, visited(false)*/, links() { }

	void add_link(Node *next) {
		this->links.push_back(next);
	}

	const vector<Node *>& link() const {
		return links;
	}

	// void set_visited(bool b) {
	// 	this->visited = b;
	// }

	// bool is_visited() const {
	// 	return this->visited;
	// }

	void set_val(const string& str) {
		this->val = str;
	}

	const string& value() const {
		return val;
	}
};

class Solution {
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		vector<vector<Node *> > result;

		queue<vector<Node *> > _queue;

		if (dict.empty()) return vector<vector<string> >();

		// Storage to store the Node *
		vector<Node *> v;

		// Initialize the storage
		v.push_back(new Node(end));
		for (unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter) {
			v.push_back(new Node(*iter));
		}
		v.push_back(new Node(start));

		// Create Tree
		for (vector<Node *>::iterator iter = v.begin(); iter != v.end(); ++iter) {
			for (vector<Node *>::iterator n_iter = iter + 1; n_iter != v.end(); ++n_iter) {
				if (compare((*iter)->val, (*n_iter)->val)) {
					(*iter)->add_link(*n_iter);
					(*n_iter)->add_link(*iter);
				}
			}
		}
        
		// BFS
		// Create the first sequence
		vector<Node *> sequence; 
		sequence.push_back(v[0]); 
		// v[0]->set_visited(true);

		// Push the first one into stack
		_queue.push(sequence);

		// Set flag
		bool find_answer = false;
        int min_length = 0;
        
		while (!_queue.empty()) {
			vector<Node *> top_v = _queue.front(); _queue.pop();
			Node *back_n = top_v[top_v.size() - 1];

			if (find_answer) {
				// Just check the top vector
				// do NOT inflate the stack again
				if (back_n->val == start) {
					// cout << "Find: when result's size is " << result.size() << endl;
					// for (vector<Node *>::iterator i = top_v.begin(); i != top_v.end(); ++i) {
					// 	cout << (*i)->val << " ";
					// }
					// cout << endl;
				    if (top_v.size() == min_length)
					    result.push_back(top_v);
					else 
					    break;
				}
			} else {
				if (back_n->val == start) {
					// cout << "Find: when result's size is " << top_v.size() << endl;
					// for (vector<Node *>::iterator i = top_v.begin(); i != top_v.end(); ++i) {
					// 	cout << (*i)->val << " ";
					// }
					// cout << endl;
					result.push_back(top_v);
					min_length = top_v.size();
					// cout << "Set length to " << top_v.size() << endl;
					find_answer = true;
				} else {
					// Inflate the stack with new vector
					const vector<Node *>& children = back_n->link();
					for (vector<Node *>::const_iterator i = children.cbegin(); i != children.cend(); ++i) {
						// if (!(*i)->is_visited()) {
							vector<Node *> tmp(top_v);
							tmp.push_back(*i);
							// (*i)->set_visited(true);
							_queue.push(tmp);
						// }
					}
				}
			}
		}

		vector<vector<string> > res;
		for (vector<vector<Node *>>::iterator iter = result.begin(); iter != result.end(); ++iter) {
			vector<string> tmp;
			for (vector<Node *>::reverse_iterator i = (*iter).rbegin(); i != (*iter).rend(); ++i) {
				tmp.push_back((*i)->val);
			}
			res.push_back(tmp);
		}

		return res;
	}

private:
	// Still have room to be improved
	bool compare(string& a, string& b) {
		int diff = 0;
		for (string::iterator ai = a.begin(), bi = b.begin(); ai != a.end() && bi != b.end(); ++ai, ++bi) {
			if (*ai != *bi) ++diff;
			if (diff > 1) return false;
		}
		return true;
	}
};