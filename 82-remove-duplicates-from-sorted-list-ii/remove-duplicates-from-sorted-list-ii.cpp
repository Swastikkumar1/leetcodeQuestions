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
    ListNode* deleteDuplicates(ListNode* head) {
        // Dummy node points to head to handle cases where head is deleted
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy; // 'prev' is the last known distinct node

        while (head != nullptr) {
            // If we detect the start of a duplicate sequence
            if (head->next != nullptr && head->val == head->next->val) {
                // Move 'head' to the end of the duplicate sequence
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                // Skip all duplicates by connecting 'prev' to the node after 'head'
                prev->next = head->next;
            } else {
                // No duplicate detected, 'prev' can safely move to 'head'
                prev = prev->next;
            }
            // Move 'head' forward
            head = head->next;
        }

        return dummy->next;
    }
};