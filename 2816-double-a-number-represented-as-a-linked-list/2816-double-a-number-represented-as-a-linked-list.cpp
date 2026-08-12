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
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        
        ListNode* temp = head;
        ListNode* prev = nullptr;
        int carry = 0;

        while (temp != nullptr) {
            int sum = temp->val * 2 + carry;
            temp->val = sum % 10;
            carry = sum / 10;
            prev = temp;
            temp = temp->next;
        }

        if (carry > 0) {
            prev->next = new ListNode(carry);
        }

        return reverseList(head);
    }
};