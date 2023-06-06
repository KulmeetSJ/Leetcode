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
        if(list1==NULL && list2 == NULL) return NULL;
        else if(list1 == NULL && list2 != NULL) return list2;
        else if(list1 != NULL && list2 == NULL) return list1;
        
        ListNode* p = list1 , *q = list2;
        ListNode* newHead = new ListNode(-1);
        ListNode* k = newHead;
        while(p!= NULL && q!= NULL)
        {   
            ListNode* temp = new ListNode();
            if(p->val <= q->val)
            {
                temp->val = p->val;
                p = p->next;
            }
            else{
                temp->val = q->val;
                q=q->next;
            }
            k->next = temp;
            k = k->next;
        }
        
        while(p!=NULL)
        {
            ListNode* temp = new ListNode(p->val);
            p = p->next;
            k->next = temp;
            k = k->next;
        }
        while(q!=NULL)
        {
            ListNode* temp = new ListNode(q->val);
            q = q->next;
            k->next = temp;
            k = k->next;
        }
        
    return newHead->next;
    }
};