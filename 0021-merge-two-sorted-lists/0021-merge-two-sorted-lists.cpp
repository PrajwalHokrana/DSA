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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val < temp2->val) {
                while (temp1->next != NULL && temp1->next->val <= temp2->val) {
                    temp1 = temp1->next;
                }
                ListNode* temp = temp1;
                temp1 = temp1->next;
                temp->next = temp2;
            } else {
                while (temp2->next != NULL && temp2->next->val <= temp1->val) {
                    temp2 = temp2->next;
                }
                ListNode* temp = temp2;
                temp2 = temp2->next;
                temp->next = temp1;
            }
        }

        return list1->val < list2->val ? list1 : list2;
    }
};