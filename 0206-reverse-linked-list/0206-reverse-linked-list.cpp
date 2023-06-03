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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        vector<int> arr;
        while(p!= NULL)
        {
            arr.push_back(p->val);
            p = p->next;
        }
        
        reverse(arr.begin(),arr.end());
        
        ListNode* newHead = new ListNode(-1);
        
        ListNode* q = newHead;
        
        for(int i=0;i<arr.size();i++)
        {     
            ListNode *node = new ListNode(arr[i]);
            q->next = node;
            q = q->next;
        }
    return newHead->next;
    }
};