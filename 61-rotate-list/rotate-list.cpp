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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // 1. Compute the length of the list and find the tail
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // 2. Handle k >= length
        k = k % length;
        if (k == 0) return head;

        // 3. Connect tail to head to make it circular
        tail->next = head;

        // 4. Find the new tail: (length - k - 1) steps from head
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }

        // 5. The new head is the node after the new tail
        ListNode* newHead = newTail->next;

        // 6. Break the circle
        newTail->next = nullptr;

        return newHead;
    }
};