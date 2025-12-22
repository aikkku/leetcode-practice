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
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* prev_prev = head;
        head = head->next;
        prev_prev->next = nullptr;
        ListNode* prev = head;
        head = head->next;
        prev->next = prev_prev;
        while(head) {
            prev_prev = prev;
            prev = head;
            head = head->next;
            prev->next = prev_prev;
            prev_prev = prev;
        }
        return prev;
    }
};