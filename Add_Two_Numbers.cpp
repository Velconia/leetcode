#include <iostream>

using std::cout;
using std::endl;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode *result = l1;
        ListNode *prev_l1 = NULL;
        int extra_num = 0;
        
        while (true) {
            if (l1 == NULL && l2 == NULL) {
                if (extra_num == 1) { 
                    l1 = new ListNode(1);
                    prev_l1->next = l1;
                    extra_num = 0;
                    l1 = l1->next;
                    continue;
                } else {
                    break;   
                }
            }
            
            if (l1 == NULL) {
                plus(l2, extra_num);
                l2 = l2->next;
                continue;
            }
            
            if (l2 == NULL) {
                l1->val += extra_num;
                if (l1->val >= 10) {
                    l1->val -= 10;
                    extra_num = 1;
                } else {
                    extra_num = 0;
                }
                l1 = l1->next;
                continue;
            }
            
            plus(l1, l2, extra_num);
            prev_l1 = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        return result;
    }
    
    void plus(ListNode *l, int& extra_num) {
        l->val += extra_num;
        if (l->val >= 10) {
            l->val -= 10;
            extra_num = 1;
        } else {
            extra_num = 0;
        }
    }
    
    void plus(ListNode *l1, ListNode *l2, int& extra_num) {
        int val = l1->val + l2->val;
        
        if (val >= 10) {
            val -= 10;
            val += extra_num;
            extra_num = 1;
        } else {
            val += extra_num;
            
            if (val >= 10) {
                val -= 10;
                extra_num = 1;
            } else {
                extra_num = 0;
            }
        }
        
        l1->val = val;
    }
};

int main() {
    ListNode *n1 = new ListNode(5);
    ListNode *n2 = new ListNode(5);

    Solution s;
    ListNode *n = s.addTwoNumbers(n1, n2);
    while (n != NULL) {
        cout << n->val << endl;
        n = n->next;
    }
}