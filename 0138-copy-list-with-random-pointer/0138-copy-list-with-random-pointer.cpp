/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        
        Node* curr = head;
        
        while( curr!=NULL){
            Node* copyNode = new Node(curr->val);
            copyNode->next = curr->next;
            curr->next = copyNode;
            curr = curr->next->next;
        }
        
        Node* iter = head;
        while( iter!=NULL){
            if(iter->random != NULL)
            iter->next->random = iter->random->next;
            iter = iter->next->next;
        }
        
        Node* dummyHead = new Node(-1);
        Node* dummyPtr = dummyHead;
        
        iter = head;
        Node* front ;
        
        while(iter!=NULL){
            front = iter->next->next;
            dummyPtr->next = iter->next;
            iter->next = front;
            dummyPtr = dummyPtr->next;
            iter = front;
        }
    return dummyHead->next;
    }
};