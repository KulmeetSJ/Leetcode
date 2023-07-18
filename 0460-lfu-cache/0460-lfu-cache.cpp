class Node{
    public:
    int key,val,cnt;
    Node *next,*prev;
    Node(int k,int v){
        key = k;
        val = v;
        cnt = 1;
    }
};

class List{
    public:
    int size;
    Node *head,*tail;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addNode(Node* p){
        Node *temp = head->next;
        p->next = temp;
        p->prev = head;
        head->next = p;
        temp->prev = p;
        size++;
    }
    
    void delNode(Node* p){
        Node* pnext = p->next;
        Node* pprev = p->prev;
        pprev->next = pnext;
        pnext->prev = pprev;
        size--;
    }
};


class LFUCache {
public:
    unordered_map<int,Node*> keyNode;
    unordered_map<int,List*> freqMap;
    int cap, minFreq,currSize;
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
        currSize = 0;        
    }
    
    void updateFreqMap(Node *node){
        keyNode.erase(node->key);
        freqMap[node->cnt]->delNode(node);
        if(node->cnt == minFreq && freqMap[node->cnt]->size == 0)
        {
           minFreq++;    
        }
        List *nextHigherFreqList = new List();
        if(freqMap.find(node->cnt + 1) != freqMap.end()){
            nextHigherFreqList = freqMap[node->cnt + 1];
        }
        node->cnt +=1;
        nextHigherFreqList->addNode(node);
        freqMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key)!= keyNode.end()){
            Node* temp = keyNode[key];
            int x = temp->val;
            updateFreqMap(temp);
            return x;
        }
    return -1;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        if(keyNode.find(key)!= keyNode.end()){
            Node* temp = keyNode[key];
            temp->val = value;
            updateFreqMap(temp);
        }
        else{
            if(currSize == cap){
            List* ls = freqMap[minFreq];
            keyNode.erase(ls->tail->prev->key);
            freqMap[minFreq]->delNode(ls->tail->prev);
            currSize--;
            }
            currSize++; 
            minFreq = 1;
            List* listFreq = new List();
            if(freqMap.find(minFreq) != freqMap.end()){
               listFreq = freqMap[minFreq];
            }
            
            Node *newNode = new Node(key,value);
            listFreq->addNode(newNode);
            keyNode[key] = newNode;
            freqMap[minFreq] = listFreq;  
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */