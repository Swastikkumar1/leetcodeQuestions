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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Dummy node handles the case where left = 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;

        // 1. Reach the node just before the 'left' position
        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }

        // 2. Start reversing
        ListNode* curr = pre->next; // The first node of the segment to be reversed
        for (int i = 0; i < right - left; ++i) {
            ListNode* nextNode = curr->next;
            
            // Re-wiring pointers to move nextNode to the front of the sub-list
            curr->next = nextNode->next;
            nextNode->next = pre->next;
            pre->next = nextNode;
        }

        ListNode* result = dummy->next;
        delete dummy; // Clean up memory
        return result;
    }
};