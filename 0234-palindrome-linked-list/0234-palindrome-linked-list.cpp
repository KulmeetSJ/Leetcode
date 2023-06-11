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
        ListNode* slow = head, *fast = head;
        
        if(head == NULL || head->next == NULL) return true;
        
        //Find middle of linkedList
        while(fast->next !=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //Reverse right half of LL
        ListNode* curr = slow->next;
        ListNode* prev = NULL;
        ListNode* forw = curr->next;
        
        while(curr!=NULL )
        {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        
        slow->next = prev;
        
        //Start traversing from middle
        ListNode* dummy = head;
        slow = slow->next;
        
        while(slow != NULL)
        {   
            if(dummy->val != slow->val) return false;
            slow = slow->next;
            dummy = dummy->next;
        }
        
      return true; 
    }
};