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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        // base case
        if(size == 0)
            return nullptr;
        if(size == 1)
            return lists[0];

        // treat it as a recursive merge sort problem
        int m = (int)(size / 2);
        vector<ListNode*> leftList(lists.begin(), lists.begin() + m);
        vector<ListNode*> rightList(lists.begin() + m, lists.end());

        ListNode *leftNode  = mergeKLists(leftList);
        ListNode *rightNode = mergeKLists(rightList);

        // sanity check for empty lists
        if (leftNode == nullptr)
            return rightNode;
        if (rightNode == nullptr)
            return leftNode;

        // each linked list is already sorted, so we only need to merge
        ListNode* mergedHead;

        // set the node head
        if (leftNode->val <= rightNode->val) {
            // take the left node
            mergedHead = leftNode;
            leftNode = leftNode->next;
            if (leftNode == nullptr) {
                mergedHead->next = rightNode;
                return mergedHead;
            }

        } else {
            mergedHead = rightNode;
            rightNode = rightNode->next;
            if(rightNode == nullptr) {
                mergedHead->next = leftNode;
                return mergedHead;
            }
        }

        ListNode *currNode = mergedHead;

        while(leftNode != nullptr && rightNode != nullptr) {
            // insert the smaller value'd node
            if(leftNode->val <= rightNode->val) {
                currNode->next = leftNode;
                leftNode = leftNode->next;
            } else {
                currNode->next = rightNode;
                rightNode = rightNode->next;
            }

            // progress the output node
            currNode = currNode->next;
        }

        // check for leftovers on each end
        if(rightNode != nullptr)
            currNode->next = rightNode;
        else if (leftNode != nullptr)
            currNode->next = leftNode;

        return mergedHead;
    }
};
