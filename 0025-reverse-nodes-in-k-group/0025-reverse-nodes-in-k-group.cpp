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
        if(!head || k == 1) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy , *curr = dummy , *forw = dummy;
        int size = 0;
        
        while(curr->next != NULL){
            curr = curr->next;
            size++;
        }
        
        
        while(size >= k){
            curr = prev->next;
            forw = curr->next;
            for(int i=1;i<k;i++){
                curr->next = forw->next;
                forw->next = prev->next;
                prev->next = forw;
                forw = curr->next;
            }
            size -= k;
            prev = curr;
        }
    return dummy->next;
    }
};