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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* ans = head;

        while(true) {
            int minn = 1001, mini;

            for(int i = 0; i < lists.size(); i++) {
                if(lists[i] != nullptr and lists[i]->val <= minn) {
                    minn = lists[i]->val;
                    mini = i;
                }
            }
            if(minn == 1001) break;

            while(lists[mini] and lists[mini]->val == minn) {
                ListNode* dummy = new ListNode(minn);
                head->next = dummy;
                head = head->next;
                lists[mini] = lists[mini]->next;
            }
        }

        return ans->next;
    }
};
