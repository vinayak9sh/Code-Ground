// Day_032

// Problem 01: Remove Duplicates from Sorted List II
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy ;
        prev->next = head;
        while(temp!=nullptr&&temp->next!=nullptr){
            if(temp->next->val==temp->val){
                int v = temp->val;
                while(temp!=nullptr){
                    if(temp->val==v)temp = temp->next;
                    else break ;
                }
                prev->next = temp;
            }
            else{
                prev = temp ;
                temp = temp->next;
            }
        }
        return dummy->next;
    }
};

// TC = O(N)
// SC = O(1)
// Approach: The code skips over all consecutive duplicate nodes by comparing each node with the next and moving the pointer past all nodes with the same value. It maintains a prev pointer to re-link the last distinct node to the next unique node, effectively removing duplicates

// Problem 02: Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/description/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* curr = head;
        stack<int> st;
        int count = k;
        while (temp) {
            st.push(temp->val);  
            count--;
            if (count == 0) {
                while (!st.empty()) {
                    curr->val = st.top();  
                    st.pop();
                    curr = curr->next;
                }
                count = k;  
            }
            temp = temp->next;
        }
        return head; 
    }
};

// TC = O(N)
// SC = O(k), where k is stack size temporarily used.
// Approach: The code traverses the list and pushes values of each group of k nodes onto a stack to reverse their order. After every k nodes, it pops the stack to overwrite the original node values with reversed ones.
