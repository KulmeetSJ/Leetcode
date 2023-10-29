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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        
        ListNode* fast = head , *slow = head; 
        
        while(fast->next!=NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //Now slow is pointing at mid
        //Reverse right half
        ListNode* prev = NULL , *curr=slow->next;
        
        while(curr != NULL ){
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        
        ListNode* p = head;
        slow->next = prev;
        slow = slow->next;
        
        while(slow != NULL){
            if(slow->val != p->val){
                return false;
            }
            slow = slow->next;
            p = p->next;
        }
    return true;
    }
};