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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        int carry = 0;

        while(curr1 != nullptr || curr2 != nullptr || carry != 0)
        {
            int x = (curr1 != nullptr) ? curr1->val : 0;
            int y = (curr2 != nullptr) ? curr2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
 
            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            if(curr1 != nullptr) curr1 = curr1->next;
            if(curr2 != nullptr) curr2 = curr2->next;
        }
        
        return dummy->next;
    }
};
