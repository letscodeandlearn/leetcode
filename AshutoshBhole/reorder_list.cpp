/**
 * URL:https://leetcode.com/problems/reorder-list/
 * 
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.

Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

*/
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
    
    ListNode* getSecondLastNode(ListNode* root) {
        bool isPresent = false;
        
        if(root->next != NULL) {
            while(root->next->next != NULL) {
                isPresent = true;
                root = root->next;
            }
        }
        
        if (isPresent == true) {
            return root;
        }
        
        return NULL;
    }
    
    
    void reorderList(ListNode* head) {
        
    
        if(head == NULL) {
            return;
        }
 
        ListNode* front = head;
        bool reorder = true;
        
        while(front->next != NULL) {

            if(reorder == true) {
                ListNode* node = getSecondLastNode(front);
                
                if(node != NULL) {
                    
                    ListNode* chain = front->next;
                    front->next = node->next;
                    front->next->next = chain;
                    node->next = NULL;
                }
           }
            reorder = !reorder;
            front = front->next;
        }
        
        
    }
};