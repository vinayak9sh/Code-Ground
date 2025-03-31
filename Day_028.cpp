// Day_028

// Problem 01: Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/
// Code:-

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true; // Cycle detected
            }
        }
        return false; // No cycle
    }
};

// TC = O(N)
// SC = O(1)
// Approach: Both pointers were started at the head of the list. Slow was moved by 1 step, and fast by 2 steps. If slow was met by fast, a cycle was found to exist; otherwise, if the end was reached by fast, no cycle was detected, tortoise was moved 1 step, hare was moved 2 steps, and if they were met, a cycle was detected!

// Problem 02: Middle of the Linked List
// https://leetcode.com/problems/middle-of-the-linked-list/
// Code:-

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// TC = O(N)
// SC = O(1)
// Approach: Two pointers were initialized at the head of the list. One pointer was moved one step at a time, while the other was moved two steps at a time. When the faster pointer reached the end, the slower pointer was at the middle, which was returned as the result.
