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
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = head->next;
        while (Next != NULL) {
            curr->next = prev;
            prev = curr;
            curr = Next;
            Next = Next->next;
        }
        curr->next = prev;

        return curr;
    }
    int getDecimalValue(ListNode* head) {

        head=reverseList(head);
        int pow=1,ans=0;
        ListNode*temp=head;

        while(temp!=NULL)
        {
            ans+=(pow*temp->val);
            temp=temp->next;
            pow*=2;
        }

        return ans;
    }
};