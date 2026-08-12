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
    void remove(ListNode* temp) {
        ListNode*temp1=temp;
        while (temp1->next != NULL && temp1->next->val == temp1->val) {
            ListNode* temp2 = temp1->next;
            temp1->next = temp2->next;
            delete temp2;
        }
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* temp = head;

        while (temp!=NULL && temp->next !=NULL) {
            if (temp->next->val == temp->val) {
                remove(temp);
            }
            temp=temp->next;
        }

        return head;
    }
};