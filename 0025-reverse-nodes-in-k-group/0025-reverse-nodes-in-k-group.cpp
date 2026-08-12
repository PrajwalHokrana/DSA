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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*prevGroupEnd=dummy;
        int len=0;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        while(len>=k)
        {
            ListNode*curr=prevGroupEnd->next;
            for(int i=1;i<k;i++)
            {
                ListNode*Next=curr->next;
                curr->next=Next->next;
                Next->next=prevGroupEnd->next;
                prevGroupEnd->next=Next;
            }

            prevGroupEnd=curr;
            len-=k;
        }

        return dummy->next;
    }
};