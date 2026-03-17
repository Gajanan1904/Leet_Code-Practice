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
        vector<int> vals;

        for(auto list : lists) {
            while(list) {
                vals.push_back(list->val);
                list = list->next;
            }
        }

        sort(vals.begin(), vals.end());

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        for(int v : vals) {
            temp->next = new ListNode(v);
            temp = temp->next;
        }

        return dummy->next;
    }
};