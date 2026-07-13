class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *second=slow->next;
        slow->next=NULL;

        ListNode *curr=second;
        ListNode *prev=NULL;

        while(curr!=NULL){
            ListNode *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        second=prev;
        ListNode *first=head;

        while(first!=NULL && second!=NULL){
            ListNode *next1=first->next;
            ListNode *next2=second->next;

            first->next=second;
            second->next=next1;

            first=next1;
            second=next2;
        }
    }
};