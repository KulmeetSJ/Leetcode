/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA && !headB) return NULL;
        ListNode* dummyA = headA , *dummyB = headB;
        int lenA = 0 , lenB = 0 ;
        while(dummyA!=NULL || dummyB!=NULL)
        {
            if(dummyA!=NULL){
                dummyA = dummyA->next;
                lenA++;
            }
            if(dummyB!=NULL){
                dummyB = dummyB->next;
                lenB++;
            }
        }
        
        dummyA = headA , dummyB = headB;
        
        if(lenA > lenB){
            int diff = lenA - lenB;
            while(diff)
            {
                dummyA = dummyA->next;
                diff--;
            }
        }
        else{
            int diff = lenB-lenA;
            while(diff)
            {
                dummyB = dummyB->next;
                diff--;
            }
        }
        
        while(dummyA!=NULL && dummyB!=NULL)
        {   
            if(dummyA == dummyB) return dummyA;
            dummyA = dummyA->next;
            dummyB = dummyB->next;
        }
            
      return NULL;  
    }
};