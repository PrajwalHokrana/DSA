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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* write = head->next;
        ListNode* read = head->next;

        int currentSum = 0;

        while (read != nullptr) {
            if (read->val == 0) {
                write->val = currentSum;
                currentSum = 0;

                // If there are more segments after this zero
                if (read->next != nullptr) {
                    write = write->next;
                }
            } else {
                currentSum += read->val;
            }
            read = read->next;
        }

        // Sever the remainder of the old list
        write->next = nullptr;
        return head->next;
    }
};