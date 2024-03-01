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
        ListNode* mergedListHead = NULL;
        ListNode* mergedListTail = NULL;

        // Merge the lists until one of them is exhausted
        while (list1 != nullptr && list2 != nullptr) {
            ListNode* newNode;
            if (list1->val < list2->val) {
                newNode = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                newNode = new ListNode(list2->val);
                list2 = list2->next;
            }

            if (mergedListHead == nullptr) {
                mergedListHead = newNode;
                mergedListTail = newNode;
            } else {
                mergedListTail->next = newNode;
                mergedListTail = newNode;
            }
        }

        // Append the remaining nodes from list1 or list2 if any
        if (list1 != nullptr) {
            if (mergedListHead == nullptr) {
                mergedListHead = list1;
            } else {
                mergedListTail->next = list1;
            }
        } else if (list2 != nullptr) {
            if (mergedListHead == nullptr) {
                mergedListHead = list2;
            } else {
                mergedListTail->next = list2;
            }
        }

        return mergedListHead;
    }
};