// Day_031

// Problem 01: Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/
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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val){    
            head = head->next;  
        }
        ListNode* first = head; 
        while(first && first->next){
            if(first->next->val == val){
                first->next = first->next->next;   
            }
            else{
                first = first->next;
            }
        }
        return head;
    }
};

// TC = O(N)
// SC = O(1)
// Approach: The approach first skips all leading nodes that contain the target value by moving the head pointer forward. Then, it iterates through the remaining list and removes any matching nodes by adjusting the `next` pointers to skip over them. 

// Problem 02: Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;
            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};

// TC = O(M+N)
// SC = O(M+N)   where M and N are number of nodes in the linked list l1 and l2 respectively.
// Approach: raverse both linked lists while adding corresponding digits and carry to form a new result node at each step. Continue until all digits and any remaining carry are processed into a new linked list.
