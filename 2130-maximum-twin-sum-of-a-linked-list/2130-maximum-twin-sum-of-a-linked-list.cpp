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
    
    
    int pairSum(ListNode* head) {
        stack<int> s;
        ListNode* temp = head;
        while(temp)
        {
            s.push(temp->val);
            temp = temp->next;
        }
        int ans = 0;
        while(s.size())
        {
            ans = max(ans, head->val + s.top());
            s.pop();
            head = head->next;
        }
    return ans;
    }
};