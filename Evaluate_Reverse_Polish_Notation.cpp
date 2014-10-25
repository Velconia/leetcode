#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> _stack;
        for (vector<string>::iterator iter = tokens.begin(); 
             iter != tokens.end(); ++iter) {
            if (*iter == "+") {
                int right    = _stack.top(); _stack.pop();
                int left     = _stack.top(); _stack.pop();
                _stack.push(left + right);
                continue;
            } 
            
            if (*iter == "-") {
                int right    = _stack.top(); _stack.pop();
                int left     = _stack.top(); _stack.pop();
                _stack.push(left - right);
                continue;
            }
            
            if (*iter == "*") {
                int right    = _stack.top(); _stack.pop();
                int left     = _stack.top(); _stack.pop();
                _stack.push(left - right);
                continue;
            }
            
            if (*iter == "/") {
                int right    = _stack.top(); _stack.pop();
                int left     = _stack.top(); _stack.pop();
                
                if (right == 0) return 0;
                
                _stack.push(left / right);
                continue;
            }
            
            _stack.push(transfer(*iter));
            cout << "Push: " << _stack.top() << endl;
        }
        return _stack.top();
    }

private:
    int transfer(string str) {
        int result = 0;
        int unit = 1;
        for (string::reverse_iterator riter = str.rbegin(); 
             riter != str.rend(); riter++) {
            if (*riter == '-') {
                result = ~result + 1;
                continue;
            }

            result  += (*riter - '0') * unit;
            cout << "Result :" << result << " unit: " << unit << endl;
            unit    *= 10;
        }
        return result;
    }
};

int main() {
    vector<string> v;
    v.push_back("0");
    v.push_back("-4");
    v.push_back("+");
    Solution s;
    cout << s.evalRPN(v) << endl;
}