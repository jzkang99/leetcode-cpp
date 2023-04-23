#include <stdlib.h>
#include "ListNode.cpp"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        if (list1->val <= list2->val) {
            ListNode* nxt = mergeTwoLists(list1->next, list2);
            list1->next = nxt;
            return list1;
        } else {
            ListNode* nxt = mergeTwoLists(list1, list2->next);
            list2->next = nxt;
            return list2;
        }
    }

    ListNode* mergeTwoListsIterative(ListNode* list1, ListNode* list2) {
        ListNode dummy; // Allocated memory automatically on the stack
        ListNode* head = &dummy;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                head->next = list1;
                head = head->next;
                list1 = list1->next;
            } else {
                head->next = list2;
                head = head->next;
                list2 = list2->next;
            }
        }

        if (list1 != NULL) head->next = list1;
        if (list2 != NULL) head->next = list2;

        return dummy.next;
    }

    ListNode* mergeTwoListsIterative1(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(); // Need to explicitely "new" a memory space on the heap
        ListNode* head = dummy;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                head->next = list1;
                list1 = list1->next;
            } else {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }

        if (list1 != NULL) head->next = list1;
        if (list2 != NULL) head->next = list2;

        return dummy->next;
    }
};