/**
 * Definition for singly-lin2ed list.
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
    ListNode* swapPairs(ListNode* head) {
        // Stack-allocated dummy node avoids manual memory cleanup
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Rewire pointers to swap the pair
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev to the end of the newly swapped pair
            prev = first;
        }

        return dummy.next;
    }
};