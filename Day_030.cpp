// Day_030

// Problem 01: Sort List
// https://leetcode.com/problems/sort-list/
// Code:-

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
    ListNode* getmid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        while (left != NULL) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while (right != NULL) {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        dummy = dummy->next;
        return dummy;
    }

    ListNode* sortList(ListNode* head) {
        // using merge sort

        // base case
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* mid = getmid(head);

        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        ListNode* result = merge(left, right);

        return result;
    }
};

// TC = O(NLogN)
// SC = O(NLogN)
// Approach: This code uses **merge sort** to sort a singly-linked list by recursively dividing it into halves using the slow and fast pointer technique. It then **merges the sorted halves** back together in sorted order using an in-place merge function.

// Problem 02: Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Code:-

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases
        ListNode* res = new ListNode(0, head);
        ListNode* dummy = res;

        // Move the head pointer n steps forward
        for (int i = 0; i < n; i++) {
            head = head->next;
        }

        // Move both pointers until head reaches the end
        while (head != nullptr) {
            head = head->next;
            dummy = dummy->next;
        }

        // Remove the nth node from the end
        dummy->next = dummy->next->next;

        // Return the updated list
        return res->next;
    }
};

// TC = O(N)
// SC = O(1)
// Approach: This code uses a two-pointer technique with a dummy node to simplify edge cases. It first moves one pointer n steps ahead, then advances both until the first reaches the end, allowing it to remove the nth node from the end in a single pass.








