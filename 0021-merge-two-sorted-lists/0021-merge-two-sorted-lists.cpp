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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 , *l2;
        ListNode* temp;
        
        if(!list1) return list2;
        if(!list2) return list1;
        
        bool one = false;
        
        if(list1->val <= list2->val){
            l1 = list1;
            l2 = list2;
            one = true;
        }
        else{
            l1 = list2;
            l2 = list1;
            one = false;
        }
        
        while(l1 && l2){
            if(l1->val <= l2->val){
                temp = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                swap(l1,l2);
                // l2 = l1;
                // l1 = temp->next;
            }
        }
        
        if(!l1){
            temp->next = l2;
        }
        if(!l2){
            temp->next = l1;
        }
        
      return one?list1:list2;
    }
};