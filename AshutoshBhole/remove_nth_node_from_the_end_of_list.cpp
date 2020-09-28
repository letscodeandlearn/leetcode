/**
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * 
 * 19. Remove Nth Node From End of List
Medium

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* engine = head;
        ListNode* front = head;
        ListNode* back = NULL;
        
        while(n>0) {
            engine = engine->next;
            n--;
        }
        
        while(engine != NULL) {
            engine = engine->next;
            back = front;
            front = front->next;
        }
        
        if(back == NULL) {
            front = front->next;
            return front;
        }
        
        back->next = front->next;
        front->next = NULL;
        return head;
        
    }
};