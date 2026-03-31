/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Helper function to reverse a linked list (this was already correct)
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        // Step 0: Handle edge cases where no reordering is needed.
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // Step 1: Find the middle of the list.
        // 'slow' will point to the last node of the first half.
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Split the list into two halves.
        // The second half starts at the node after 'slow'.
        ListNode* second_half = slow->next;
        // Terminate the first half.
        slow->next = nullptr;

        // Step 3: Reverse the second half.
        second_half = reverse(second_half);

        // Step 4: Merge the first half and the reversed second half.
        ListNode* first_half = head;
        while (second_half != nullptr) {
            // Save the next nodes to link later
            ListNode* temp1 = first_half->next;
            ListNode* temp2 = second_half->next;

            // Link first_half node to second_half node
            first_half->next = second_half;
            // Link second_half node to the rest of the first half
            second_half->next = temp1;

            // Move pointers to the next nodes for the next iteration
            first_half = temp1;
            second_half = temp2;
        }
    }
};