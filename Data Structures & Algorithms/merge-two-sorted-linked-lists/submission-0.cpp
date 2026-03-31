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
        ListNode* newHead;
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        if(list1->val < list2->val)
        {
            newHead = list1;
        }
        else
        {
            newHead = list2;
        }

        ListNode* tail = newHead;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        if(tail == curr1) curr1 = curr1->next;
        else curr2 = curr2->next;

        while(curr1 != nullptr && curr2 != nullptr)
        {
            if(curr1->val < curr2->val)
            {
                tail->next = curr1;
                curr1 = curr1->next;
            }
            else
            {
                tail->next = curr2;
                curr2 = curr2->next;
            }
            tail = tail->next;
        }

        if(curr1 == nullptr)
        {
            tail->next = curr2;
        }
        else
        {
            tail->next = curr1;
        }
        return newHead;
    }
};
