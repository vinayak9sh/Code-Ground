// Day_029

// Problem 01: Find length of loop
// https://bit.ly/3dyXL6m
// Code:-

class Solution {
  public:
    int countNodesinLoop(Node *head) {
       
        if(head==NULL ||head->next == NULL) return NULL;
        int cnt = 1;
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next !=  NULL){
            slow = slow->next;
            fast= fast->next->next;
            if(fast == slow){
                fast = fast -> next;
                while(fast != slow){
                    cnt++;
                    fast = fast->next;
                }
                return cnt;
            }
        }
        return NULL;
    }
};

// TC = O(N)
// SC = O(1)
// Approach: The approach uses Floyd’s Cycle Detection Algorithm (Tortoise and Hare) to detect a loop in the linked list by moving the `slow` pointer one step at a time and the `fast` pointer two steps at a time. If a cycle is detected when `slow` and `fast` meet, the algorithm then moves the `fast` pointer forward while counting the number of nodes in the cycle until it meets `slow` again, giving the loop length. 

// Problem 02: Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/
// Code:-

class Solution {
public:
    bool isPalindrome(ListNode* head) {
         if(head == NULL || head->next == NULL){
            return (head);
        }
        ListNode *r_head = NULL;
        ListNode *ptr = head;
        while(ptr!=NULL){
            ListNode *temp = new ListNode(ptr->val);
            temp ->next = r_head;
            r_head = temp;
            ptr = ptr->next;
        }
        while(head && r_head){
            if(head->val != r_head->val){
                return false;
            }
            head = head->next;
            r_head = r_head->next;
        }
        return true;
    }
};

// TC = O(N)
// SC = O(N)
// Approach: The code creates a reversed copy of the original linked list by iterating through it and inserting each node at the beginning of a new list. It then compares the original and reversed lists node by node to check if the linked list is a palindrome. 
