/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st; 
        ListNode* s = head;
        ListNode* f = head;
        while(f and f->next) {
            f = f->next->next;
            st.push(s->val);
            s = s->next;
        }

        int largest = 0;

        while(!st.empty()) {
            largest = max(largest, st.top() + s->val);
            s = s->next;
            st.pop();
        }

        return largest;


    }
};