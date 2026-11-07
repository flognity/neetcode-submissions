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
        // empty list or single-node list is already reversed
        if (head == nullptr || head->next == nullptr)
            return head;

        // reverse the list that comes after head
        ListNode* newHead = reverseList(head->next);

        // we know head->next exist, so put the head 
        // after its original next node
        head->next->next = head;

        // the original head becomes the new tail
        head->next = nullptr;

        // final return
        return newHead;
    }
};
