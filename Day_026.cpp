// Day_026

// Problem 01: Doubly linked list Insertion at given position
// https://bit.ly/3QD4hHs
// Code:-

class Solution {
  public:
    Node *addNode(Node *head, int pos, int data) {
        Node* newnode = new Node(data);
        Node* temp = head;
        
        if(!head)
            return newnode;
            
        for(int i=0;i<pos;i++) {
            temp = temp->next;
        }
        
        if(!temp->next) {
            temp->next = newnode;
            newnode->prev = temp;
        }
        else {
            Node* temp1 = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = temp1;
            temp1->prev = newnode;
        }
        return head;
    }
};

// TC = O(pos)
// TC = O(1)
// Approach: This function inserts a new node at a given position in a doubly linked list by traversing the list up to the specified position, then updating the next and prev pointers accordingly to maintain the list's structure.

// Problem 02: Search in Linked List
// https://bit.ly/3Epriup
// Code:-

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, Node* head, int key) {
        // Code here
        Node* temp=head;
        while(temp!=NULL)
        {    if(temp->data==key)
            {
                return true;
            }
            temp=temp->next;
        }
        return  false;
       
    }
};

// TC = O(N)
// SC = O(1)
// Approach: This function searches for a key in a singly linked list by traversing the list from the head, comparing each node's value with the given key, and returning true if found; otherwise, it returns false.
