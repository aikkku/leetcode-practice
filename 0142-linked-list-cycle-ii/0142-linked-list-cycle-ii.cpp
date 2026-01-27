/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* f = head;
        ListNode* s = head;

        while(f and f->next) {
            f = f->next->next;
            s = s->next;
            if(f == s) break;
        }

        if(!f or !f->next) return nullptr;

        ListNode* ss = head;

        while(ss != s) {
            s = s->next;
            ss = ss->next;
        }

        return s;
    }
};